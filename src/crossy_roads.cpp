#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "lib/errors.hpp"
#include "lib/Chicken.hpp"
#include "lib/Level.hpp"
#include "lib/Road.hpp"
#include "lib/Car.hpp"

struct Chicken player;
float laneHeight = 0.2f;
int   no_of_levels = 1;
std::vector<Level> levels;

int State = 0;
/*
State Machine Assignment:
0                   : Start Screen
1 to no_of_levels   : Level Screens
no_of_levels + 1    : WIN Screen
no_of_levels + 2    : LOST Screen
*/

void drawStartScreen(){}
void drawWinScreen(){}
void drawLoseScreen(){}

void handleKeypress(unsigned char key, int x, int y) {
    float movementAmount = laneHeight;
    switch (key) {
        case 'w': // Move up
            if (player.y + movementAmount < 1.0f) {
                player.y += movementAmount;
            }
            break;
        case 's': // Move down
            if (player.y - movementAmount > -1.0f) {
                player.y -= movementAmount;
            }
            break;
        case 'a': // Move left
            if (player.x > -1.0f + laneHeight) {
                player.x -= 0.05f;
            }
            player.direction = false;
            break;
        case 'd': // Move right
            if (player.x < 1.0f - laneHeight){
                player.x += 0.05f;
            }
            player.direction = true;
            break;
        case ' ': 
            if (State == 0 || State > no_of_levels){
                State = 1;
                player.resetpos();
            }
            break;
    }
    glutPostRedisplay();
    glFlush();
}

void handleSpecialKeypress(int key, int x, int y) {
    float movementAmount = laneHeight;
    switch (key) {
        case GLUT_KEY_UP:
            if (player.y + movementAmount < 1.0f) {
                player.y += movementAmount;
            }
            break;
        case GLUT_KEY_DOWN:
            if (player.y - movementAmount > -1.0f) {
                player.y -= movementAmount;
            }
            break;
        case GLUT_KEY_LEFT:
            if (player.x > -1.0f + laneHeight) {
                player.x -= 0.05f;
            }
            player.direction = false;
            break;
        case GLUT_KEY_RIGHT:
            if (player.x < 1.0f - laneHeight){
                player.x += 0.05f;
            }
            player.direction = true;
            break;
    }
    glutPostRedisplay();
    glFlush();
}

void update(int){
    try {
        if (State >= 1 && State <=no_of_levels){
            levels[State-1].update();
        }
    } catch (const LevelOver){
        State++;
    } catch (const Collision){
        State = no_of_levels+2;
    }
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
    
    if (State == 0){
        drawStartScreen();
    } else if (State >= 1 && State <=no_of_levels){
        levels[State-1].draw();
	    drawChicken(&player);
    } else if (State == no_of_levels+1){
        drawWinScreen();
    } else if (State == no_of_levels+2){
        drawLoseScreen();
    }

	glFlush();
}
 
void init(){
	glClearColor(0.133, 0.545, 0.133, 0.0);
  
	{//initialise player
		player.resetpos();
        player.size	     =  0.8*laneHeight;	            // Size of the chicken
        player.direction =  true; 		                // Initial Direction ~ right
	}
    
    for (int i = 1; i <= no_of_levels; i++){
        levels.push_back(Level(i, laneHeight));
    }

    std::srand(time(0));

}

int main(int argc, char** argv){
	{//initialise
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
		glutInitWindowSize(1200,600);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Crossy Roads");

		init();
	}
	
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleSpecialKeypress);

	glutDisplayFunc(display);
	glutTimerFunc(33, update, 0);
	glutMainLoop();

	return 0;
}

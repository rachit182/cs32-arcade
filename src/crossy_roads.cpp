#include <GL/gl.h>
#include <GL/glut.h>
#include "lib/Chicken.hpp"

//Global Variables
Chicken player;
float laneHeight = 0.2f;

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

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawChicken(&player);

	glFlush(); //single buffering
}

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	{//initialise player
		player.x 	 =  0.0f; 		// Initial X position
    		player.y	 = -1.0f + 0.5*laneHeight; 		// Initial Y position
    		player.size	 =  0.8*laneHeight;	// Size of the chicken
    		player.direction =  true; 		// Initial Direction ~ right
	}
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
	glutMainLoop();

	return 0;
}


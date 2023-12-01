#include <GL/gl.h>
#include <GL/glut.h>
#include "lib/Chicken.hpp"
#include "lib/road.hpp"

//Global Variables
Chicken player;
float laneHeight = 0.2f;
Road road_1(0.0f, 0.1f, laneHeight, false, laneHeight*0.8);
Road road_2(0.0f, 0.5f, laneHeight, true, laneHeight*0.8);
Road road_3(0.0f, -0.3f, laneHeight, true, laneHeight*0.8);
std::vector<Road> road_list;

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

void update(int value){
	for(size_t i=0; i<road_list.size(); i++){
		if (road_list[i].direction) {
			if (road_list[i].car.x < 1.5f) {
				road_list[i].car.x += 0.01f;
			} else {
				road_list[i].car.x = road_list[i].x - 1.2f;
				road_list[i].car.y = road_list[i].y;
			}
		} else {
			if (road_list[i].car.x > -1.5f) {
				road_list[i].car.x -= 0.01f;
			} else {
				road_list[i].car.x = road_list[i].x + 1.2f;
				road_list[i].car.y = road_list[i].y;
			}
		}
	}
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
  
//C_NPC
	for(auto road: road_list){
		drawRoad(&road);
	}

//B_Player
	drawChicken(&player);

	glFlush(); //single buffering
}

void init(){
	glClearColor(0.133, 0.545, 0.133, 0.0);
  
	{//initialise player
		player.x 	 =  0.0f; 		// Initial X position
    		player.y	 = -1.0f + 0.5*laneHeight; 		// Initial Y position
    		player.size	 =  0.8*laneHeight;	// Size of the chicken
    		player.direction =  true; 		// Initial Direction ~ right
	}
  
	road_list.push_back(road_1);
	road_list.push_back(road_2);
	road_list.push_back(road_3);
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

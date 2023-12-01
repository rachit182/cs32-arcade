#include "road.hpp"

//Car car_1;
//make this a vector
//float car_spawn_point_x = 1.2f;
//float car_spawn_point_y = 0.8f;
//Global Variables
Road road_1(0.0f, 0.0f, false);
float laneHeight = 0.2f;

void update(int value){
	if (road_1.direction) {
		if (road_1.car.x < 1.5f) {
			road_1.car.x += 0.01f;
		} else {
			road_1.car.x = road_1.x - 1.2f;
			road_1.car.y = road_1.y - 0.09f;
		}
	} else {
		if (road_1.car.x > -1.5f) {
			road_1.car.x -= 0.01f;
		} else {
			road_1.car.x = road_1.x + 1.2f;
			road_1.car.y = road_1.y - 0.09f;
		}
	}
    glutPostRedisplay();
    glutTimerFunc(33, update, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawRoad(&road_1);

	glFlush(); //single buffering
}

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	{
	//initialise road
		road_1.x = 0.0f;
		road_1.y = 0.0f;
		road_1.size = laneHeight;
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
	
	glutDisplayFunc(display);
	glutTimerFunc(33, update, 0);
	glutMainLoop();

	return 0;
}

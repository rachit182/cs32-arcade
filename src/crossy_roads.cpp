#include "lib/road.hpp"

//Global Variables
float laneHeight = 0.2f;
Road road_1(0.0f, 0.0f, laneHeight, false, laneHeight*0.8);
Road road_2(0.0f, 0.2f, laneHeight, true, laneHeight*0.8);
Road road_3(0.0f, -0.2f, laneHeight, true, laneHeight*0.8);
std::vector<Road> road_list;

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

	for(auto road: road_list){
		drawRoad(&road);
	}

	glFlush(); //single buffering
}

void init(){
	glClearColor(0.133, 0.545, 0.133, 0.0);
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
	
	glutDisplayFunc(display);
	glutTimerFunc(33, update, 0);
	glutMainLoop();

	return 0;
}

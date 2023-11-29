#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

float car_spawn_x = 0;
float car_spawn_y = 0;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glLoadIdentity();
}

void car(float x, float y){	
	//glColor3f(0.286, 0.278, 0.361);
	//glColor3f(0.624, 0.435, 0.725);
	glColor3f(0.667, 0.224, 0.224);
	//border
	glBegin(GL_POLYGON);
		glVertex2f(x-0.01f, y+0.02f);
		glVertex2f(x+0.02f, y+0.0f);
		glVertex2f(x+0.12f, y+0.0f);
		glVertex2f(x+0.14f, y+0.02f);
		glVertex2f(x+0.14f, y+0.16f);
		glVertex2f(x+0.12f, y+0.18f);
		glVertex2f(x+0.02f, y+0.18f);
		glVertex2f(x-0.01f, y+0.16f);
	glEnd();
	//windows
	glBegin(GL_POLYGON);
		//define window points
	glEnd();
}

void update(int value){
	car_spawn_x=car_spawn_x-0.05;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	car(car_spawn_x, car_spawn_y);

	glFlush();
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

	glutDisplayFunc(render);

	glutTimerFunc(33, update, 0); //33ms ~ 30fps

	glutMainLoop();

	return 0;
}


#include <GL/gl.h>
#include <GL/glut.h>

void update(){
	
}

void render(int value){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.678, 0.847, 0.902);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv){
	{//initialise
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
		glutInitWindowSize(1200,600);
		glutInitWindowPosition(100,100);
		glutCreateWindow("Crossy Roads");

		glClearColor(1.0, 1.0, 1.0, 0.0);
	}

	glutDisplayFunc(update);

	glutTimerFunc(33, render, 0); //33ms ~ 30fps

	glutMainLoop();

	return 0;
}


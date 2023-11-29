#include <GL/gl.h>
#include <GL/glut.h>
#include "lib/Chicken.hpp"

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Move up
            player.y += 0.1f;
            break;
        case 's': // Move down
            player.y -= 0.1f;
            break;
        case 'a': // Move left
            player.x -= 0.1f;
            break;
        case 'd': // Move right
            player.x += 0.1f;
            break;
    }
    glutPostRedisplay(); // Redraw the scene
}

void update(){
	
}

void render(int value){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawChicken(&player);

	glFlush();
}

//Global variable
Chicken player;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	
	{//initialise player
		player.x 	 = 0.0f; // Initial X position
    		player.y	 = 0.0f; // Initial Y position
    		player.size	 = 0.1f; // Size of the chicken
    		player.direction = true; // Initial Direction ~ right
	}
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
	glutKeyboardFunc(handleKeypress);
	glutTimerFunc(33, render, 0); 		//33ms ~ 30fps

	glutMainLoop();

	return 0;
}


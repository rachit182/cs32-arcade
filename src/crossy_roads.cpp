#include <GL/gl.h>
#include <GL/glut.h>
#include "lib/Chicken.hpp"

//Global Variables
Chicken player;
float laneHeight = 0.15f;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Move up
            player.y += laneHeight;
            break;
        case 's': // Move down
            player.y -= laneHeight;
            break;
        case 'a': // Move left
            player.x -= laneHeight;
            break;
        case 'd': // Move right
            player.x += laneHeight;
            break;
    }
    glutPostRedisplay(); // Redraw the scene
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
    		player.y	 = -1.0f; 		// Initial Y position
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
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}


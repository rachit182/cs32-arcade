#ifndef CAR_HPP
#define CAR_HPP

#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>


struct Car{
	float x, y;	 //position of the car
	bool  direction; //true for left to right
	float size;
	
	Car(float x_cord, float y_cord, bool dir, float size) : direction(dir), x(x_cord), y(y_cord), size(size) {}

	void update(float distance){
		std::cout << "x before update: " << x << std::endl;
		if(direction){
			x += distance;
		} else {
			x -= distance;
		}
		std::cout << "x after update: " << x << std::endl;
	}

	void draw(){
		glLoadIdentity();
		glTranslatef(x, y, 0.0f); //changes to the current position of the car
		glColor3f(0.667, 0.224, 0.224);; // pretty red
		//Body
		glBegin(GL_POLYGON);
			glVertex2f(-0.6*size/2.0, 0.5*size);
			glVertex2f(-1.0*size/2.0, 0.35*size);
			glVertex2f(-1.0*size/2.0, -0.35*size);
			glVertex2f(-0.6*size/2.0, -0.5*size);
			glVertex2f(0.6*size/2.0, -0.5*size);
			glVertex2f(1.0*size/2.0, -0.35*size);
			glVertex2f(1.0*size/2.0, 0.35*size);
			glVertex2f(0.6*size/2.0, 0.5*size);
		glEnd();

		glColor3f(0.635, 0.639, 0.643); //window grey
		//Window Left Big
		glBegin(GL_POLYGON);
			glVertex2f(-0.6*size/2.0, 0.4*size);
			glVertex2f(-0.45*size/2.0, 0.2*size);
			glVertex2f(-0.45*size/2.0, -0.2*size);
			glVertex2f(-0.6*size/2.0, -0.4*size);
		glEnd();
		//Window Bottom Left
		glBegin(GL_POLYGON);
			glVertex2f(-0.4*size/2.0, -0.275*size);
			glVertex2f(-0.05*size/2.0, -0.275*size);
			glVertex2f(-0.05*size/2.0, -0.4*size);
			glVertex2f(-0.55*size/2.0, -0.4*size);
		glEnd();
		//Window Upper Left
		glBegin(GL_POLYGON);
			glVertex2f(-0.4*size/2.0, 0.275*size);
			glVertex2f(-0.05*size/2.0, 0.275*size);
			glVertex2f(-0.05*size/2.0, 0.4*size);
			glVertex2f(-0.55*size/2.0, 0.4*size);
		glEnd();
		//Window Right Big
		glBegin(GL_POLYGON);
			glVertex2f(0.6*size/2.0, 0.4*size);
			glVertex2f(0.45*size/2.0, 0.2*size);
			glVertex2f(0.45*size/2.0, -0.2*size);
			glVertex2f(0.6*size/2.0, -0.4*size);
		glEnd();
		//Window Bottom Right
		glBegin(GL_POLYGON);
			glVertex2f(0.4*size/2.0, -0.275*size);
			glVertex2f(0.05*size/2.0, -0.275*size);
			glVertex2f(0.05*size/2.0, -0.4*size);
			glVertex2f(0.55*size/2.0, -0.4*size);
		glEnd();
		//Window Upper Right
		glBegin(GL_POLYGON);
			glVertex2f(0.4*size/2.0, 0.275*size);
			glVertex2f(0.05*size/2.0, 0.275*size);
			glVertex2f(0.05*size/2.0, 0.4*size);
			glVertex2f(0.55*size/2.0, 0.4*size);
		glEnd();
	}
};

#endif //CHICKEN_HPP
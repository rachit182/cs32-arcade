#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>

//remove direction variable, it has no use yet.

struct Car{
	float x, y;	 //position of the car
	bool  direction; //true for left to right
	float size;

	Car(float x_cord, float y_cord, bool dir, float s) {
		direction = dir;
		y = y_cord;
		size = s;
		if(direction){
			x = x_cord - 1.2f;
		} else {
			x = x_cord + 1.2f;
		}
	}
};

void drawCar(const Car* car) {
	glLoadIdentity();
	glTranslatef(car->x, car->y, 0.0f); //changes to the current position of the car
	glColor3f(0.667, 0.224, 0.224);; // pretty red
    //Body
	glBegin(GL_POLYGON);
		glVertex2f(-0.6*car->size/2.0, 0.5*car->size);
		glVertex2f(-1.0*car->size/2.0, 0.35*car->size);
		glVertex2f(-1.0*car->size/2.0, -0.35*car->size);
		glVertex2f(-0.6*car->size/2.0, -0.5*car->size);
		glVertex2f(0.6*car->size/2.0, -0.5*car->size);
		glVertex2f(1.0*car->size/2.0, -0.35*car->size);
		glVertex2f(1.0*car->size/2.0, 0.35*car->size);
		glVertex2f(0.6*car->size/2.0, 0.5*car->size);
	glEnd();

	glColor3f(0.635, 0.639, 0.643); //window grey
	//Window Left Big
	glBegin(GL_POLYGON);
		glVertex2f(-0.6*car->size/2.0, 0.4*car->size);
		glVertex2f(-0.45*car->size/2.0, 0.2*car->size);
		glVertex2f(-0.45*car->size/2.0, -0.2*car->size);
		glVertex2f(-0.6*car->size/2.0, -0.4*car->size);
	glEnd();
	//Window Bottom Left
	glBegin(GL_POLYGON);
		glVertex2f(-0.4*car->size/2.0, -0.275*car->size);
		glVertex2f(-0.05*car->size/2.0, -0.275*car->size);
		glVertex2f(-0.05*car->size/2.0, -0.4*car->size);
		glVertex2f(-0.55*car->size/2.0, -0.4*car->size);
	glEnd();
	//Window Upper Left
	glBegin(GL_POLYGON);
		glVertex2f(-0.4*car->size/2.0, 0.275*car->size);
		glVertex2f(-0.05*car->size/2.0, 0.275*car->size);
		glVertex2f(-0.05*car->size/2.0, 0.4*car->size);
		glVertex2f(-0.55*car->size/2.0, 0.4*car->size);
	glEnd();
	//Window Right Big
	glBegin(GL_POLYGON);
		glVertex2f(0.6*car->size/2.0, 0.4*car->size);
		glVertex2f(0.45*car->size/2.0, 0.2*car->size);
		glVertex2f(0.45*car->size/2.0, -0.2*car->size);
		glVertex2f(0.6*car->size/2.0, -0.4*car->size);
	glEnd();
	//Window Bottom Right
	glBegin(GL_POLYGON);
		glVertex2f(0.4*car->size/2.0, -0.275*car->size);
		glVertex2f(0.05*car->size/2.0, -0.275*car->size);
		glVertex2f(0.05*car->size/2.0, -0.4*car->size);
		glVertex2f(0.55*car->size/2.0, -0.4*car->size);
	glEnd();
	//Window Upper Right
	glBegin(GL_POLYGON);
		glVertex2f(0.4*car->size/2.0, 0.275*car->size);
		glVertex2f(0.05*car->size/2.0, 0.275*car->size);
		glVertex2f(0.05*car->size/2.0, 0.4*car->size);
		glVertex2f(0.55*car->size/2.0, 0.4*car->size);
	glEnd();
}

#endif //CHICKEN_HPP
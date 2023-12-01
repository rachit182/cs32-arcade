#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

//remove direction variable, it has no use yet.

struct Car{
	float x, y;	 //position of the chicken
	bool  direction; //true for right
	//float size = 0.17;

	Car(float x_cord, float y_cord, bool dir) {
		direction = dir;
		y = y_cord - 0.09f;
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
		glVertex2f(-0.01f, 0.02f);
		glVertex2f(0.02f, 0.0f);
		glVertex2f(0.12f, 0.0f);
		glVertex2f(0.14f, 0.02f);
		glVertex2f(0.14f, 0.16f);
		glVertex2f(0.12f, 0.18f);
		glVertex2f(0.02f, 0.18f);
		glVertex2f(-0.01f, 0.16f);
	glEnd();

	glColor3f(0.635, 0.639, 0.643); 
	//Window
	glBegin(GL_POLYGON);
		glVertex2f(-0.003f, 0.035f);
		glVertex2f(0.015f, 0.015f);
		glVertex2f(0.015f, 0.16f);
		glVertex2f(-0.003f, 0.14f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(0.135f, 0.03f);
		glVertex2f(0.115f, 0.015f);
		glVertex2f(0.115f, 0.16f);
		glVertex2f(0.135f, 0.14f);
	glEnd();
}

#endif //CHICKEN_HPP
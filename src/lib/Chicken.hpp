#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include <cmath>

//remove direction variable, it has no use yet.

typedef struct {
	float x, y;	 //position of the chicken
	float size;
	bool  direction; //true for right
} Chicken;

void drawChicken(const Chicken* chicken) {

        float half_height = chicken->size/2;
        float half_width  = chicken->size/4;
        
	glTranslatef(chicken->x, chicken->y, 0.0f); //changes to the current position of the chicken
	
	//Body
	glColor3f(0.984f, 0.776f, 0.090f); // lightning yellow
	glRectf(-half_width, -half_height, half_width, 0.33*half_height);
	
	//Head
	glColor3f(0.984f, 0.572f, 0.023f); //pizazz
	glRectf(-0.5*half_width, 0.0f, 0.5*half_width, 0.67*half_height);

	//Beak
	glColor3f(0.776f, 0.0667f, 0.015f); //burnt orange
	glBegin(GL_TRIANGLES);
            glVertex2f(             0.0f,  0.8*half_height);
            glVertex2f(-0.167*half_width,  0.6*half_height);
            glVertex2f( 0.167*half_width,  0.6*half_height);
        glEnd();

	
	
	/*
	// Body
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow for the body
    glRectf(-half_width, -half_height, half_width, half_height);

    // Head
    float headRadius = half_height / 2;
    float headCenterX = chicken->direction ? half_width : -half_width;
    float headCenterY = half_height;

    // Drawing head as a circle approximation
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f; // Convert degrees to radians
        glVertex2f(cos(angle) * headRadius + headCenterX, sin(angle) * headRadius + headCenterY);
    }
    glEnd();

    // Beak
    glColor3f(1.0f, 0.5f, 0.0f); // Orange for the beak
    float beakWidth = headRadius / 2;
    float beakHeight = headRadius / 4;
    float beakCenterX = chicken->direction ? headCenterX + headRadius : headCenterX - headRadius;

    glBegin(GL_TRIANGLES);
    if (chicken->direction) { // Beak pointing right
        glVertex2f(beakCenterX, headCenterY);
        glVertex2f(beakCenterX + beakWidth, headCenterY + beakHeight);
        glVertex2f(beakCenterX + beakWidth, headCenterY - beakHeight);
    } else { // Beak pointing left
        glVertex2f(beakCenterX, headCenterY);
        glVertex2f(beakCenterX - beakWidth, headCenterY + beakHeight);
        glVertex2f(beakCenterX - beakWidth, headCenterY - beakHeight);
    }
    glEnd();

    // Eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black for the eyes
    float eyeRadius = headRadius / 8;
    float eyeCenterX = chicken->direction ? headCenterX + headRadius / 2 : headCenterX - headRadius / 2;
    float eyeCenterY = headCenterY + headRadius / 2;

    // Drawing eye as a circle
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(cos(angle) * eyeRadius + eyeCenterX, sin(angle) * eyeRadius + eyeCenterY);
    }
    glEnd();

    // Legs (just simple lines)
    glColor3f(1.0f, 0.5f, 0.0f); // Orange for the legs
    float legLength = half_height / 2;
    glBegin(GL_LINES);
    glVertex2f(-half_width / 2, -half_height);
    glVertex2f(-half_width / 2, -half_height - legLength);
    glVertex2f(half_width / 2, -half_height);
    glVertex2f(half_width / 2, -half_height - legLength);
    glEnd();
    
	//create square to represent the chicken
	glColor3f(1.0f, 1.0f, 0.0f); //Yellow
	glBegin(GL_QUADS);
		glVertex2f(-half_width , -half_height);
		glVertex2f( half_width , -half_height);
		glVertex2f( half_width ,  half_height);
		glVertex2f(-half_width ,  half_height);
	 glEnd();
	 */
}

#endif //CHICKEN_HPP

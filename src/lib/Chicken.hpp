#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include <cmath>

//remove direction variable, it has no use yet.

struct Chicken {
	float x, y;	 //position of the chicken
	float size;
	bool  direction; //true for right

    void resetpos(){
        x 	     =  0.0f; 		                // Initial X position
        y	     = -1.0f + 0.625*size; 		    // Initial Y position
    }
};

void drawChicken(const Chicken* chicken) {

    float half_height = chicken->size/2;
    float half_width  = chicken->size/4;
	
	glLoadIdentity(); //Set current coordinates to default        
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
}

#endif //CHICKEN_HPP

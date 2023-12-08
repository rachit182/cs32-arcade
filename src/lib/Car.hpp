#ifndef CAR_HPP
#define CAR_HPP

#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include <sstream>
#include <iomanip>

extern float laneHeight;
extern int 	 no_of_levels;
extern int 	 State;
extern struct Chicken player;

struct Color {
    float red;
    float green;
    float blue;
    float alpha;

    // Default constructor
    Color() : red(0), green(0), blue(0), alpha(255) {}

    // Constructor with RGB values
    Color(float r, float g, float b, float a = 255)
        : red(r), green(g), blue(b), alpha(a) {}
};

int i = 0;
std::vector<Color> all_car_colors = {
        Color(197.0f/255.0f, 17.0f/255.0f, 17.0f/255.0f),    // #c51111
        Color(19.0f/255.0f, 46.0f/255.0f, 209.0f/255.0f),    // #132ed1
        Color(17.0f/255.0f, 127.0f/255.0f, 45.0f/255.0f),    // #117f2d
        Color(237.0f/255.0f, 84.0f/255.0f, 186.0f/255.0f),   // #ed54ba
        Color(239.0f/255.0f, 125.0f/255.0f, 13.0f/255.0f),   // #ef7d0d
        Color(245.0f/255.0f, 245.0f/255.0f, 87.0f/255.0f),   // #f5f557
        Color(56.0f/255.0f, 254.0f/255.0f, 220.0f/255.0f),   // #38fedc
        Color(80.0f/255.0f, 239.0f/255.0f, 57.0f/255.0f)     // #50ef39
    };

class Car{
public:
	float x, y;	 //position of the car
	bool  direction; //true for left to right
	float size;
	Color clr;
	
	Car(float x_cord, float y_cord, bool dir, float size) : direction(dir), x(x_cord), y(y_cord), size(size) {
		clr = all_car_colors[i]; i++; i%=8;
	}

	void update(float distance){
		if(direction){
			x += distance;
		} else {
			x -= distance;
		}
		
		if (x < -1.2f){
			x = 1.2f;
		} else if (x > 1.2f){
			x = -1.2f;
		}
	}

	void draw(){

		if (fabs(x-(player.x))<(0.6*laneHeight) && fabs(y-(player.y))<(0.99*laneHeight)){
			State = no_of_levels+2;
		}

		glLoadIdentity();
		glTranslatef(x, y, 0.0f); //changes to the current position of the car
		glColor3f(clr.red, clr.green, clr.blue);
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

		glColor3f(1.0, 1.0, 1.0);
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

#endif //CAR_HPP
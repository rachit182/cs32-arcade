#ifndef ROAD_HPP
#define ROAD_HPP
#include "lib/car.hpp"

//remove direction variable, it has no use yet.

struct Road{
	float x, y;	 //position of the chicken
	float size;
    bool direction;
    Car car;

    Road(float x_cord, float y_cord, bool dir) : x(x_cord), y(y_cord), direction(dir), car(Car(x, y, dir)) {}
};

void drawRoad(const Road* road) {
	glLoadIdentity();
    float half_height = road->size/2;    
	glTranslatef(road->x, road->y, 0.0f); //changes to the current position of the road
	glColor3f(0.2, 0.2, 0.2); // grey
    //Road
	glRectf(-1.0f, -half_height, 1.0f, half_height);

    drawCar(&road->car);
}

#endif //CHICKEN_HPP
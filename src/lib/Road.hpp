#ifndef ROAD_HPP
#define ROAD_HPP

#include "Car.hpp" 
#include <cstdlib>
#include <vector>
#include <iostream>

struct Road{
	float               y;
	float               size;
    bool                direction;
    float               velocity;
    std::vector<Car>    cars;

    Road(float y_cord, float size, bool dir, int no_of_cars, float vel) : y(y_cord), size(size), direction(dir), velocity(vel){
        std::srand(time(0));
        for (int i = 0; i < no_of_cars; ++i){
            float initial_pos = (((std::rand()/RAND_MAX)*2)-1);
            cars.push_back(Car(initial_pos, y, direction, size));
            std::cout << "called car constructor" << std::endl;
        }
    }

    void update(){
        for(auto i: cars){ //updating position of all cars
            i.update(velocity);
        }
    }

    void draw(){
        glLoadIdentity();
        {//draw road structure 
            glTranslatef(0.0f, y, 0.0f); //changes to the current position of the road

            glColor3f(0.2, 0.2, 0.2); //grey road
            glRectf(-1.0f, -size/2.0, 1.0f, size/2.0);

            glColor3f(1.0, 1.0, 1.0); //white divider lines
            glRectf(-1.0f, -size/2.0, 1.0, -size/2.0+0.005);
            glRectf(-1.0f, size/2.0, 1.0, size/2.0+0.005);
        }

        for(auto i: cars){
            i.draw();
        }
    }
};

#endif //CHICKEN_HPP
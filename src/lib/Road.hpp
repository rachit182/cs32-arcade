#ifndef ROAD_HPP
#define ROAD_HPP

#include "Car.hpp" 
#include <cstdlib>
#include <vector>
#include <iostream>

class Road{
public:
	float               y;
	float               size;
    bool                direction;
    float               velocity;
    std::vector<Car>    cars;

    Road(float y_cord, float size, bool dir, int no_of_cars, float vel) : y(y_cord), size(size), direction(dir), velocity(vel){
        std::srand(time(0));
        std::vector<bool> spawn_pts(8,false);
        for (int i = 0; i < no_of_cars; ++i){
            int spawn = (std::rand()%8);
            while (spawn_pts[spawn] == true){
                spawn = (std::rand()%8);
            }
            spawn_pts[spawn] = true;
        }

        float initial_pos = -0.8f;
        for (auto i: spawn_pts){
            if (i){
                cars.push_back(Car(initial_pos, y, direction, size));
            } 
            initial_pos += 0.3f;
        }
    }

    void update(){
        float r_velocity = velocity*(0.8+((rand()%500)/1000.0));
        for(size_t i=0; i < cars.size(); i++){ //updating position of all cars
            cars[i].update(r_velocity);
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
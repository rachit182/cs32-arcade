#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Road.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>



class Level{
    std::vector<Road> roads;
    float laneHeight;

public:
    Level(int difficulty, float lh): laneHeight(lh){
        std::srand(time(0));

        std::vector<bool> road_pos(8, false);
        int n_roads = (difficulty/2)+3;
        
        for (int i = 0; i < n_roads; ++ i){
            road_pos[std::rand()%8] = true;
        }
        
        float velocity = 0.5*difficulty;
        float current_height = -0.7f;
        for (auto i : road_pos){
            if (i){
                bool dir            = std::rand()%2;
                int number_of_cars  = std::rand()%4;
                roads.push_back(Road(current_height, laneHeight*0.8, dir, 1, velocity));
            }
            current_height += 0.2f;

            velocity *= 1.05; //5% increment
        }
    }

    void update(){
        for(auto i: roads){
            i.update();
        }
    }

    void draw(){
        for(auto i: roads){
            i.draw();
        }
    }
};

#endif //LEVEL_HPP

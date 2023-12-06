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

        std::vector<bool> road_pos;
        int n_roads = (difficulty/2)+2;

        for (int i = 0; i < 9; ++i){
            if (n_roads > 0){
                std::cout << std::rand() << std::endl;
                if (std::rand()%3){
                    road_pos.push_back(false);
                } else {
                    std::cout << "creates road \n";
                    road_pos.push_back(true);
                    n_roads--;
                }
            }
        }
        
        float velocity = 0.5*difficulty;
        float current_height = -0.7f;
        for (auto i : road_pos){
            if (i){
                bool dir = std::rand()%2;
                roads.push_back(Road(current_height, laneHeight*0.8, dir, std::rand()%5, velocity));
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

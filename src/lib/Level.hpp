#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Road.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>

std::unordered_map<int, std::vector<bool>> lvl_map = {
    {1, {false, false,  true, false, false, false,  true,  true}},
    {2, {false,  true,  true, false, false, false,  true, false}},
    {3, {false,  true, false,  true, false, false,  true,  true}},
    {4, {false,  true, false,  true,  true, false,  true, false}},
    {5, {false,  true, false,  true,  true, false,  true,  true}},
    {6, {false,  true, false,  true, false,  true, false,  true}},
    {7, { true,  true, false,  true,  true,  true, false,  true}}
    };

class Level{
    std::vector<Road> roads;
    float laneHeight;

public:
    Level(int difficulty, float lh): laneHeight(lh){
        std::srand(time(0));

        std::vector<bool> road_pos(8, false);
        // int n_roads = std::rand()%4+5;
        // std::cout << std::rand() << std::endl;
        // std::cout << "called constructor: " << difficulty << ", " <<n_roads << std::endl;
        // for (int i = 0; i < n_roads; ++ i){
        //     int rand = std::rand()%8;
        //     while(road_pos[rand]){
        //         rand = std::rand()%8;
        //     }
        //     road_pos[std::rand()%8] = true;
        // }

        road_pos=lvl_map[difficulty];
        
        float velocity = 0.01*difficulty;
        float current_height = -0.7f;
        for (auto i : road_pos){
            if (i){
                bool dir            = std::rand()%2;
                int number_of_cars  = (std::rand()%4)+1;
                roads.push_back(Road(current_height, laneHeight*0.8, dir, number_of_cars, velocity));
            }
            current_height += laneHeight;

            velocity *= 1.05; //5% increment
        }
    }

    void update(){
        for(size_t i=0; i < roads.size(); i++){
            roads[i].update();
        }
    }

    void draw(){
        for(auto i: roads){
            i.draw();
        }
    }
};

#endif //LEVEL_HPP

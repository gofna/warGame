#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include <iostream>
#include <cmath>
//#include "Board.hpp"
#include <algorithm> 
#include <vector>
//using namespace std;

class Soldier{

    public:
        int _player;
        int _points;
        int _ability;
        int MAX_LIFE;
        

    Soldier(int player):_player(player){}

    virtual std::pair<int,int> activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) =0;
    // void LiveUp(int up){
    //     this->_points= min(MAX_LIFE, this->_points+up);
    // }

};




#endif
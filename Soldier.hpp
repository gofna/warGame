#ifndef _SOLDIER_H_
#define _SOLDIER_H_
#include <iostream>
using namespace std;

class Soldier{
    public:
        int _player;
        int _points;
        int _ability;

    Soldier(int player):_player(player){}

    virtual void activity()=0;
};




#endif
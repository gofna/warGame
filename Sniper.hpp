#ifndef _SNIPER_H_
#define _SNIPER_H_

#include "Soldier.hpp"


class Sniper : public Soldier{
    public:
    Sniper(int player): Soldier(player){
        _points = 100;
        _ability = 50;
    }
    void activity() override;

};

#endif


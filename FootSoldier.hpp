#ifndef _FOOTSOLDIER_H_
#define _FOOTSOLDIER_H_

#include "Soldier.hpp"



class FootSoldier: public Soldier{
    public:
    FootSoldier(int player):Soldier(player){
        _points = 100;
        _ability = 10;
    }
    virtual void activity() override;

};

#endif

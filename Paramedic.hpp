
#ifndef _PARAMEDIC_H_
#define _PARAMEDIC_H_
#include "Soldier.hpp"



class Paramedic : public Soldier{
    public:
    Paramedic(int player): Soldier(player){
        _points = 100;
        _ability = 50;
        
    }
    virtual void activity(std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override;
};

#endif
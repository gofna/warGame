
#ifndef _PARAMEDIC_H_
#define _PARAMEDIC_H_
#include "Soldier.hpp"



class Paramedic : public Soldier{
    public:
    Paramedic(int player): Soldier(player){
        _points = 100;
        _ability = 50;
        MAX_LIFE = 100;
        
    }
    virtual std::pair<int,int> activity(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> location) override;
};

#endif
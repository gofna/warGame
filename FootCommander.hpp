#ifndef _FOOTCOMMANDER_H_
#define _FOOTCOMMANDER_H_


#include "FootSoldier.hpp"



class FootCommander : public FootSoldier{
    public:
    FootCommander(int player):FootSoldier(player){
        _points = 150;
        _ability = 20;
    }
    void activity(std::vector<std::vector<Soldier*>> &board, pair<int,int> location) override;
};

#endif


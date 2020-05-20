#ifndef _SNIPERCOMMANDER_H_
#define _SNIPERCOMMANDER_H_


#include "Sniper.hpp"



class SniperCommander : public Sniper{
    public:
    SniperCommander(int player): Sniper(player){
        _points = 120;
        _ability = 100;
    }
    void activity() override;

};

#endif


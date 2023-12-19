#ifndef MINER_ACTION_H
#define MINER_ACTION_H

#include <iostream>
#include "./defs.h"
#include "./action.h"
#include "./miner.h"

class MinerAction: public Action
{
    public:
        MinerAction();
        MinerAction(int actionSpeed, int actionCooldown);
        MinerAction(const MinerAction& other);
        void execute(Character* character);
        void execute(Miner* character);

    private:
        MinerAction* clone() const;

};

#endif

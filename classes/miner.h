#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "./defs.h"
#include "./character.h"

class Miner: public Character
{
    public:
        Miner();
        Miner(string name, float health, int speed, float damage, int attackSpeed, int attackRange, int attackCooldown, int cost, int populationCost, int trainingTime);
        Miner(const Miner& other);
        ~Miner();

        inline void setGoldPerAction(int goldPerAction) { this->goldPerAction = goldPerAction; }
        inline int getGoldPerAction() const { return this->goldPerAction; }

        friend class MinerAction;
        friend class MinerUpdate;
    private:
        int goldPerAction = 150;
};

#endif // MINER_H

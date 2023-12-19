#include "./miner.h"
#include "./minerAction.h"

Miner::Miner(string name, float health, int speed, float damage, int attackSpeed, int attackRange, int attackCooldown, int cost, int populationCost, int trainingTime): Character(name, health, speed, damage, attackSpeed, attackRange, attackCooldown, cost, populationCost, trainingTime)
{
    this->addAction(new MinerAction());
}

Miner::Miner(): Character("Miner", 100, 1000, 6.0, 1000, 1, 500, 150, 1, 8000)
{
    this->addAction(new MinerAction());
}

Miner::Miner(const Miner& other): Character(other)
{
}

Miner::~Miner()
{
}


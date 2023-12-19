#include "./magikill.h"

Magikill::Magikill(string name, float health, int speed, float damage, int attackSpeed, int attackRange, int attackCooldown, int cost, int populationCost, int trainingTime): Character(name, health, speed, damage, attackSpeed, attackRange, attackCooldown, cost, populationCost, trainingTime)
{
    this->maxInvokedMinions = Magikill::BASE_MAX_INVOKED_MINIONS;
    this->invokedMinions = 0;

    this->addAction(new InvokeAction());
    this->minion = new Character("Minion", 50, 500, 5, 800, 1, 400, 0, 1, 0);
}

Magikill::Magikill(const Magikill& other): Character(other)
{
    this->maxInvokedMinions = other.maxInvokedMinions;
    this->invokedMinions = other.invokedMinions;
    this->minion = new Character(*other.minion);
}

Magikill::~Magikill()
{
    if (this->minion != NULL)
    {
        delete this->minion;
    }
}



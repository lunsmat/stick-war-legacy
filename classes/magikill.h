#ifndef MAGIKILL_H
#define MAGIKILL_H

#include "./defs.h"
#include "./character.h"
#include "./invokeAction.h"

class Magikill: public Character
{
    public:
        const static int BASE_MAX_INVOKED_MINIONS = 2;

        Magikill(string name = "Magikill", float health = 100.0, int speed = 1000, float damage = 10.0, int attackSpeed = 1000, int attackRange = 6, int attackCooldown = 100, int cost = 400, int populationCost = 2, int trainingTime = 12000);
        Magikill(const Magikill& other);
        ~Magikill();

        inline int getInvokedMinions() const { return this->invokedMinions; };
        inline int getMaxInvokedMinions() const { return this->maxInvokedMinions; };

        friend class InvokeAction;
        friend class MagikillMinionUpdate;

    private:
        const Character* minion;
        int invokedMinions;
        int maxInvokedMinions;

        inline void setMaxInvokedMinions(int maxInvokedMinions) { this->maxInvokedMinions = maxInvokedMinions; };
};

#endif // MAGIKILL_H

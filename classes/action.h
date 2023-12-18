#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include "./defs.h"

class Action
{
    public:
        Action(int actionSpeed, int actionCooldown);
        Action(const Action& other);
        virtual ~Action();

        virtual void execute(Character* character) = 0;

        inline int getActionSpeed() const { return this->actionSpeed; };
        inline int getActionProgress() const { return this->actionProgress; };
        inline int getActionCooldown() const { return this->actionCooldown; };

        inline void setActionSpeed(int actionSpeed) { this->actionSpeed = actionSpeed; };
        inline void setActionProgress(int actionProgress) { this->actionProgress = actionProgress; };
        inline void setActionCooldown(int actionCooldown) { this->actionCooldown = actionCooldown; };

        friend class Character;

        friend std::ostream& operator<<(std::ostream& os, const Action& action);

    private:
        virtual Action* clone() const = 0;
        int actionSpeed; // in milliseconds
        int actionCooldown;
        int actionProgress;

};

#endif // ACTION_H

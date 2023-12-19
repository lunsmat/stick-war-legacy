#ifndef INVOKEACTION_H
#define INVOKEACTION_H

#include <iostream>
#include "./defs.h"
#include "./action.h"


class InvokeAction: public Action
{
    public:
        InvokeAction();
        InvokeAction(int actionSpeed, int actionCooldown);
        InvokeAction(const InvokeAction& other);
        void execute(Character* character);
        void execute(Magikill* character);

    private:
        InvokeAction* clone() const;

};

#endif // INVOKEACTION_H

#include "./invokeAction.h"
#include "./magikill.h"

InvokeAction::InvokeAction()
{
    this->setActionSpeed(1000);
    this->setActionCooldown(10000);
    this->setActionProgress(0);
}

InvokeAction::InvokeAction(int actionSpeed, int actionCooldown)
{
    this->setActionSpeed(actionSpeed);
    this->setActionCooldown(actionCooldown);
    this->setActionProgress(0);
}

void InvokeAction::execute(Magikill* character)
{
    if (character->invokedMinions < character->maxInvokedMinions)
    {
        character->invokedMinions++;
        character->minion = new Character(*character);
    }
}

InvokeAction::InvokeAction(const InvokeAction& other)
{
    this->setActionSpeed(other.getActionSpeed());
    this->setActionCooldown(other.getActionCooldown());
    this->setActionProgress(0);
}

void InvokeAction::execute(Character* character)
{
    std::cout << "This character cannot invoke minions." << std::endl;
}


InvokeAction* InvokeAction::clone() const
{
    Action* action = new InvokeAction(*this);
}

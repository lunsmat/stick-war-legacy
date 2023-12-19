#include "./action.h"

Action::Action()
{
    this->setActionSpeed(INT_MAX);
    this->setActionCooldown(INT_MAX);
    this->setActionProgress(0);
}

Action::Action(int actionSpeed, int actionCooldown)
{
    this->setActionSpeed(actionSpeed);
    this->setActionCooldown(actionCooldown);
    this->setActionProgress(0);
}

Action::Action(const Action& other)
{
    this->setActionSpeed(other.getActionSpeed());
    this->setActionCooldown(other.getActionCooldown());
    this->setActionProgress(other.getActionProgress());
}

Action::~Action()
{
}

std::ostream& operator<<(std::ostream& os, const Action& action)
{
    os << "Action: " << action.getActionSpeed() << " " << action.getActionCooldown() << " " << action.getActionProgress();
    return os;
}

#include "./minerAction.h"

MinerAction::MinerAction(): Action(1000, 1000)
{
}

MinerAction::MinerAction(int actionSpeed, int actionCooldown): Action(actionSpeed, actionCooldown)
{
}

MinerAction::MinerAction(const MinerAction& other): Action(other)
{
}

void MinerAction::execute(Character* character)
{
    std::cout << "This character cannot mine." << std::endl;
}

void MinerAction::execute(Miner* character)
{
}

MinerAction* MinerAction::clone() const
{
    return new MinerAction(*this);
}

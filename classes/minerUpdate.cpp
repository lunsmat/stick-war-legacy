#include <iostream>
#include "./minerUpdate.h"
#include "./miner.h"

using std::cout;
using std::endl;

MinerUpdate::MinerUpdate(): Update("Miner Update", "Increases the Miner gold by 40%.")
{
}

MinerUpdate::MinerUpdate(const MinerUpdate& other): Update(other)
{
}

MinerUpdate::~MinerUpdate()
{
}

void MinerUpdate::execute(Character* character)
{
    cout << "Not a Miner." << endl;
}

void MinerUpdate::execute(Miner* character)
{
    if (this->getCurrentLevel() == Update::MAX_LEVEL) {
        cout << "Max level reached." << endl;
        return;
    }

    character->setGoldPerAction(character->getGoldPerAction() * 1.4);
    this->setCurrentLevel(this->getCurrentLevel() + 1);
}

MinerUpdate* MinerUpdate::clone() const
{
    return new MinerUpdate(*this);}

#include <iostream>
#include "./update.h"
#include "./magikillMinionUpdate.h"
#include "./magikill.h"

using std::cout;
using std::endl;

MagikillMinionUpdate::MagikillMinionUpdate(string name, string description): Update(name, description)
{
}

MagikillMinionUpdate::MagikillMinionUpdate(const MagikillMinionUpdate& other): Update(other)
{
}

MagikillMinionUpdate::~MagikillMinionUpdate()
{
}

void MagikillMinionUpdate::updateCharacter(Character* character)
{
    cout << "Not a Magikill character" << endl;
}

void MagikillMinionUpdate::updateCharacter(Magikill* character)
{
    cout << "Updating Magikill minion" << endl;
    character->setMaxInvokedMinions(character->getMaxInvokedMinions() + this->MAGIKILL_MINION_INCREASE_PER_LEVEL);
    this->setCurrentLevel(this->getCurrentLevel() + 1);
}

#include <iostream>
#include <cmath>
#include "./update.h"
#include "./character.h"

using std::ceil;
using std::floor;
using std::endl;

Update::Update(string name, string description)
    :increaseHealthPercentagePerLevel(0),
    increaseSpeedPercentagePerLevel(0),
    increaseDamagePercentagePerLevel(0),
    increaseAttackSpeedPercentagePerLevel(0)
{
    this->setName(name);
    this->setDescription(description);
    this->setCurrentLevel(0);
}

Update::Update(string name, string description, float increaseHealthPercentagePerLevel, float increaseSpeedPercentagePerLevel, float increaseDamagePercentagePerLevel, float increaseAttackSpeedPercentagePerLevel)
    :increaseHealthPercentagePerLevel(increaseHealthPercentagePerLevel),
    increaseSpeedPercentagePerLevel(increaseSpeedPercentagePerLevel),
    increaseDamagePercentagePerLevel(increaseDamagePercentagePerLevel),
    increaseAttackSpeedPercentagePerLevel(increaseAttackSpeedPercentagePerLevel)
{
    this->setName(name);
    this->setDescription(description);
    this->setCurrentLevel(0);
}

Update::Update(const Update& other)
    :increaseHealthPercentagePerLevel(other.increaseHealthPercentagePerLevel),
    increaseSpeedPercentagePerLevel(other.increaseSpeedPercentagePerLevel),
    increaseDamagePercentagePerLevel(other.increaseDamagePercentagePerLevel),
    increaseAttackSpeedPercentagePerLevel(other.increaseAttackSpeedPercentagePerLevel)
{
    this->setName(other.getName());
    this->setDescription(other.getDescription());
    this->setCurrentLevel(other.getCurrentLevel());
}

Update::~Update()
{
}

void Update::updateCharacter(Character* character)
{
    if (this->getCurrentLevel() >= Update::MAX_LEVEL) {
        return;
    }
    // round to 2 decimal places
    character->setHealth(ceil(character->getHealth() * (1 + this->increaseHealthPercentagePerLevel * this->getCurrentLevel()) * 100) / 100);
    character->setDamage(ceil(character->getDamage() * (1 + this->increaseDamagePercentagePerLevel * this->getCurrentLevel()) * 100) / 100);

    character->setSpeed(floor((float) character->getSpeed() / (1 + this->increaseSpeedPercentagePerLevel * this->getCurrentLevel())));
    character->setAttackSpeed(floor((float) character->getAttackSpeed() / (1 + this->increaseAttackSpeedPercentagePerLevel * this->getCurrentLevel())));
    character->setAttackCooldown(floor((float) character->getAttackCooldown() / (1 + this->increaseAttackSpeedPercentagePerLevel * this->getCurrentLevel())));

    this->setCurrentLevel(this->getCurrentLevel() + 1);
}

std::ostream& operator<<(std::ostream& os, const Update& update)
{
    os << "Name: " << update.getName() << endl;
    os << "Description: " << update.getDescription() << endl;
    os << "Current level: " << update.getCurrentLevel() << endl;

    return os;
}


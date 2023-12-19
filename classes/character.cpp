#include <iostream>
#include "./character.h"
#include "./update.h"

using std::cout;
using std::endl;

Character::Character(string name, float health, int speed, float damage, int attackSpeed, int attackRange, int attackCooldown, int cost, int populationCost, int trainingTime)
{
    this->setName(name);
    this->setHealth(health);
    this->setSpeed(speed);
    this->setDamage(damage);
    this->setAttackSpeed(attackSpeed);
    this->setAttackRange(attackRange);
    this->setAttackCooldown(attackCooldown);
    this->setCost(cost);
    this->setPopulationCost(populationCost);
    this->setTrainingTime(trainingTime);

    this->setSpeedProgress(0);
    this->setAttackProgress(0);
    this->setTrainingProgress(0);

    this->actions = vector<Action*>();
    this->updates = vector<Update*>();

    this->attackMode = false;
    this->trained = false;
    this->readyToRunAction = false;
}

Character::Character(const Character& other)
{
    this->setName(other.getName());
    this->setHealth(other.getHealth());
    this->setSpeed(other.getSpeed());
    this->setDamage(other.getDamage());
    this->setAttackSpeed(other.getAttackSpeed());
    this->setAttackRange(other.getAttackRange());
    this->setAttackCooldown(other.getAttackCooldown());
    this->setCost(other.getCost());
    this->setPopulationCost(other.getPopulationCost());
    this->setTrainingTime(other.getTrainingTime());

    this->setSpeedProgress(other.getSpeedProgress());
    this->setAttackProgress(other.getAttackProgress());
    this->setTrainingProgress(other.getTrainingProgress());

    this->actions = vector<Action*>();
    this->updates = vector<Update*>();
    this->copyActions(other.getActions(), other.getActionCount());
    this->copyUpdates(other.getUpdates(), other.getUpdateCount());

    this->attackMode = false;
    this->trained = false;
    this->readyToRunAction = false;
}

Character::~Character()
{
    for (int i = 0; i < this->getActionCount(); i++) {
        delete this->actions[i];
    }
}

int Character::getTimeToNextAction() const
{
    if (!this->trained)
        return this->getTrainingTime() - this->getTrainingProgress();

    int timeToNextAction = INT_MAX;
    for (int i = 0; i < this->getActionCount(); i++) {
        Action* action = this->actions[i];
        int actionSpeed = action->getActionSpeed();
        int actionProgress = action->getActionProgress();
        int timeToAction = actionSpeed - actionProgress;
        if (timeToAction < timeToNextAction) {
            timeToNextAction = timeToAction;
        }
    }

    if (this->attackMode) {
        int attackSpeed = this->getAttackSpeed();
        int attackProgress = this->getAttackProgress();
        int timeToAttack = attackSpeed - attackProgress;
        if (timeToAttack < timeToNextAction) {
            timeToNextAction = timeToAttack;
        }
    } else {
        int speed = this->getSpeed();
        int speedProgress = this->getSpeedProgress();
        int timeToSpeed = speed - speedProgress;
        if (timeToSpeed < timeToNextAction) {
            timeToNextAction = timeToSpeed;
        }
    }

    return timeToNextAction;
}

void Character::updateProgress(int elapsedTime)
{
    if (!this->trained) {
        if (this->getTrainingProgress() + elapsedTime >= this->getTrainingTime()) {
            elapsedTime -= this->getTrainingTime() - this->getTrainingProgress();
            this->setTrainingProgress(0);
            this->trained = true;
        } else {
            this->setTrainingProgress(this->getTrainingProgress() + elapsedTime);
            return;
        }
    }

    if (elapsedTime >= this->getTimeToNextAction())
        this->readyToRunAction = true;

    if (this->attackMode) {
        this->setAttackProgress(this->getAttackProgress() + elapsedTime);
    } else {
        this->setSpeedProgress(this->getSpeedProgress() + elapsedTime);
    }

    for (int i = 0; i < this->getActionCount(); i++) {
        Action* action = this->actions[i];
        action->setActionProgress(action->getActionProgress() + elapsedTime);
    }
}

void Character::attack(Character* target)
{
    if (!this->trained)
        return;

    if (!this->attackMode)
        return;

    if (this->getAttackProgress() < this->getAttackSpeed())
        return;

    this->setAttackProgress(this->getAttackProgress() - this->getAttackSpeed() - this->getAttackCooldown());

    target->takeDamage(this->getDamage());
    this->updateReadyToRunAction();
}

void Character::move()
{
    if (!this->trained)
        return;

    if (this->attackMode)
        return;

    if (this->getSpeedProgress() < this->getSpeed())
        return;

    this->setSpeedProgress(this->getSpeedProgress() - this->getSpeed());

    this->updateReadyToRunAction();
}

void Character::takeDamage(int damage)
{
    if (this->getHealth() - damage <= 0) {
        this->setHealth(0);
    } else {
        this->setHealth(this->getHealth() - damage);
    }
}

bool Character::isReadyToAttack()
{
    if (!this->trained)
        return false;

    if (!this->isReadyToRunAction())
        return false;

    if (this->getAttackProgress() < this->getAttackSpeed())
        return false;

    return true;
}

bool Character::isReadyToMove()
{
    if (!this->trained)
        return false;

    if (!this->isReadyToRunAction())
        return false;

    if (this->getSpeedProgress() < this->getSpeed())
        return false;

    return true;
}

bool Character::isReadyToRunAction()
{
    if (!this->trained)
        return false;

    if (!this->readyToRunAction)
        return false;

    for (int i = 0; i < this->getActionCount(); i++) {
        Action* action = this->actions[i];
        if (action->getActionProgress() >= action->getActionSpeed())
            return true;
    }

    return false;
}

bool Character::canUpdateSlot(int slot) const
{
    if (slot < 0 || slot >= this->getUpdateCount())
        return false;

    Update* update = this->updates[slot];
    if (update->getCurrentLevel() >= Update::MAX_LEVEL)
        return false;

    return true;
}

void Character::updateSlot(int slot)
{
    if (!this->canUpdateSlot(slot))
        return;

    Update* update = this->updates[slot];
    update->updateCharacter(this);
}

void Character::resetProgress()
{
    this->setSpeedProgress(0);
    this->setAttackProgress(0);
    this->setTrainingProgress(0);
    for (int i = 0; i < this->getActionCount(); i++) {
        Action* action = this->actions[i];
        action->setActionProgress(0);
    }
    this->readyToRunAction = false;
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    os << "Name: " << character.getName() << endl;
    os << "Health: " << character.getHealth() << endl;
    os << "Speed: " << character.getSpeed() << endl;
    os << "Damage: " << character.getDamage() << endl;
    os << "Attack Speed: " << character.getAttackSpeed() << endl;
    os << "Attack Range: " << character.getAttackRange() << endl;
    os << "Cost: " << character.getCost() << endl;
    os << "Population Cost: " << character.getPopulationCost() << endl;
    os << "Training Time: " << character.getTrainingTime() << endl;
    os << "Is Dead: " << character.getIsDead() << endl;
    os << "Is Trained: " << character.getIsTrained() << endl;
    os << "Action Count: " << character.getActionCount() << endl;
    os << "Actions:" << endl;
    for (int i = 0; i < character.getActionCount(); i++) {
        os << *character.getActions()[i] << endl;
    }
    return os;
}

void Character::copyActions(Action** actions, int actionCount)
{
    for (int i = 0; i < actionCount; i++) {
        this->addAction(actions[i]->clone());
    }
}

void Character::copyUpdates(Update** updates, int updateCount)
{
    for (int i = 0; i < updateCount; i++) {
        this->addUpdate(new Update(*updates[i]));
    }
}

void Character::updateReadyToRunAction()
{
    this->readyToRunAction = false;
    for (int i = 0; i < this->getActionCount(); i++) {
        Action* action = this->actions[i];
        if (action->getActionProgress() >= action->getActionSpeed()) {
            this->readyToRunAction = true;
            break;
        }
    }
}

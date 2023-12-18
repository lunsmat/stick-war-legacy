#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <stdbool.h>

#include "./defs.h"
#include "./action.h"

using std::string;
using std::vector;

class Character
{
    public:
        Character(string name, int health, int speed, int damage, int attackSpeed, int attackRange, int attackCooldown, int cost, int populationCost, int trainingTime);
        Character(const Character& other);
        ~Character();

        inline string getName() const { return this->name; };
        inline int getHealth() const { return this->health; };
        inline int getSpeed() const { return this->speed; };
        inline int getDamage() const { return this->damage; };
        inline int getAttackSpeed() const { return this->attackSpeed; };
        inline int getAttackRange() const { return this->attackRange; };
        inline int getAttackCooldown() const { return this->attackCooldown; };
        inline int getCost() const { return this->cost; };
        inline int getPopulationCost() const { return this->populationCost; };
        inline int getTrainingTime() const { return this->trainingTime; };

        inline int getSpeedProgress() const { return this->speedProgress; };
        inline int getAttackProgress() const { return this->attackProgress; };
        inline int getTrainingProgress() const { return this->trainingProgress; };
        inline bool getIsDead() const { return this->health == 0; }
        inline bool getIsTrained() const { return this->trained; }
        inline bool getIsReadyToRunAction() const { return this->readyToRunAction; }
        inline bool getAttackMode() const { return this->attackMode; }

        inline int getActionCount() const { return this->actions.size(); };
        inline Action** getActions() const { return (Action**)this->actions.data(); };
        inline void addAction(Action* action) { this->actions.push_back(action); };

        int getTimeToNextAction() const;
        void updateProgress(int timeElapsed);

        inline void setName(string name) { this->name = name; };
        inline void setHealth(int health) { this->health = health; }
        inline void setSpeed(int speed) { this->speed = speed; }
        inline void setDamage(int damage) { this->damage = damage; }
        inline void setAttackSpeed(int attackSpeed) { this->attackSpeed = attackSpeed; }
        inline void setAttackRange(int attackRange) { this->attackRange = attackRange; }
        inline void setAttackCooldown(int attackCooldown) { this->attackCooldown = attackCooldown; }
        inline void setCost(int cost) { this->cost = cost; }
        inline void setPopulationCost(int populationCost) { this->populationCost = populationCost; }
        inline void setTrainingTime(float trainingTime) { this->trainingTime = trainingTime; }
        inline void setAttackMode(bool attackMode) { this->attackMode = attackMode; }
        inline void setTrained(bool trained) { this->trained = trained; }

        inline void setSpeedProgress(int speedProgress) { this->speedProgress = speedProgress; }
        inline void setAttackProgress(int attackProgress) { this->attackProgress = attackProgress; }
        inline void setTrainingProgress(int trainingProgress) { this->trainingProgress = trainingProgress; }

        void attack(Character* target);
        void move();
        void takeDamage(int damage);
        bool isReadyToAttack();
        bool isReadyToMove();
        bool isReadyToRunAction();
        void resetProgress();

        friend std::ostream& operator<<(std::ostream& os, const Character& character);

    private:
        string name;

        int health; // in hit points
        int speed; // in pixels per second
        int damage; // per attack
        int attackSpeed; // in milliseconds
        int attackRange; // in pixels
        int attackCooldown; // in milliseconds
        int cost; // in coins
        int populationCost; // in population
        bool attackMode;
        bool trained;
        bool readyToRunAction;

        int trainingTime; // in milliseconds
        vector<Action *> actions;

        // progresses the character's actions
        int speedProgress;
        int attackProgress;
        int trainingProgress;

        void copyActions(Action** actions, int actionCount);
        void updateReadyToRunAction();

};

#endif // CHARACTER_H

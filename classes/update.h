#ifndef UPDATE_H
#define UPDATE_H

#include <string>

#include "./defs.h"

using std::string;

// Updates to be used in the character class
class Update
{
    public:
        const static int MAX_LEVEL = 3;

        Update(string name, string description);

        Update(string name, string description, float increaseHealthPercentagePerLevel, float increaseSpeedPercentagePerLevel, float increaseDamagePercentagePerLevel, float increaseAttackSpeedPercentagePerLevel);
        Update(const Update& other);
        ~Update();

        inline string getName() const { return this->name; };
        inline string getDescription() const { return this->description; };
        inline int getCurrentLevel() const { return this->currentLevel; };

        inline void setName(string name) { this->name = name; };
        inline void setDescription(string description) { this->description = description; };
        inline void setCurrentLevel(int currentLevel) { this->currentLevel = currentLevel; };

        void updateCharacter(Character* character);

        friend std::ostream& operator<<(std::ostream& os, const Update& update);

    private:
        string name;
        string description;
        int currentLevel;

        const float increaseHealthPercentagePerLevel;
        const float increaseSpeedPercentagePerLevel;
        const float increaseDamagePercentagePerLevel;
        const float increaseAttackSpeedPercentagePerLevel;

};

#endif

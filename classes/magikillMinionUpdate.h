#ifndef MAGIKILL_MINION_UPDATE_H
#define MAGIKILL_MINION_UPDATE_H

#include "./update.h"

class MagikillMinionUpdate: public Update
{
    public:
        const int MAGIKILL_MINION_INCREASE_PER_LEVEL = 1;

        MagikillMinionUpdate(string name, string description);
        MagikillMinionUpdate(const MagikillMinionUpdate& other);
        ~MagikillMinionUpdate();

        void updateCharacter(Character* character);
        void updateCharacter(Magikill* character);

        friend std::ostream& operator<<(std::ostream& os, const MagikillMinionUpdate& update);

};

#endif

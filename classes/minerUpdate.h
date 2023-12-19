#ifndef MINER_UPDATE_H
#define MINER_UPDATE_H

#include "./update.h"

class MinerUpdate: public Update
{
    public:
        MinerUpdate();
        MinerUpdate(const MinerUpdate& other);
        ~MinerUpdate();

        void execute(Character* character);
        void execute(Miner* character);

    private:
        MinerUpdate* clone() const;
};

#endif

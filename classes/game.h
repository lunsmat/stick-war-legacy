#ifndef GAME_H
#define GAME_H
#include "./defs.h"

class Game
{
    public:
        Game();
        ~Game();
        void start();

    private:
        void simulateBattle(Character *character1, Character *character2);
};

#endif // GAME_H

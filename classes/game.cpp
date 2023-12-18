#include <iostream>
#include <array>
#include "./game.h"
#include "./character.h"

using std::cout;
using std::array;
using std::endl;

Game::Game()
{
    cout << "Starting Stick War Legacy" << endl << "Welcome to the game!" << endl;
}

Game::~Game()
{
}

void Game::start()
{
    cout << "Game started!" << endl;

    cout << "Thanks for playing!" << endl;

    array<Character*, 2> characters = {
        new Character("Swordwrath", 100, 1000, 12, 1000, 1, 1000, 125, 1, 8000),
        new Character("Spearton", 440, 1130, 15, 750, 1, 1400, 500, 2, 12000)
    };

    cout << "Characters:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int i = 0; i < characters.size(); i++) {
        cout << *characters[i] << endl;
        cout << "------------------------------------------------------" << endl;
    }

    Character swordwrath = Character(*characters[0]);
    Character spearton = Character(*characters[1]);

    this->simulateBattle(&swordwrath, &spearton);

    for (int i = 0; i < characters.size(); i++) {
        delete characters[i];
    }
}

void Game::simulateBattle(Character *character1, Character *character2)
{
    character1->setTrained(true);
    character2->setTrained(true);

    character1->setAttackMode(true);
    character2->setAttackMode(true);

    character1->resetProgress();
    character2->resetProgress();

    cout << "Simulating attack between " << character1->getName() << " and " << character2->getName() << endl;
    cout << "------------------------------------------------------" << endl;
    cout << character1->getName() << " health: " << character1->getHealth() << endl;
    cout << character2->getName() << " health: " << character2->getHealth() << endl;

    while (!character1->getIsDead() && !character2->getIsDead()) {
        int timeToNextAction = character1->getTimeToNextAction() < character2->getTimeToNextAction() ? character1->getTimeToNextAction() : character2->getTimeToNextAction();

        cout << "------------------------------------------------------" << endl;
        cout << "Time to next action: " << timeToNextAction << endl;

        character1->updateProgress(timeToNextAction);
        character2->updateProgress(timeToNextAction);

        if (character1->getIsReadyToRunAction()) {
            character1->attack(character2);
            cout << character1->getName() << " attacked " << character2->getName() << endl;
            cout << character2->getName() << " health: " << character2->getHealth() << endl;
        }

        if (character2->getIsReadyToRunAction()) {
            character2->attack(character1);
            cout << character2->getName() << " attacked " << character1->getName() << endl;
            cout << character1->getName() << " health: " << character1->getHealth() << endl;
        }
    }

    cout << "------------------------------------------------------" << endl;
    cout << character1->getName() << " health: " << character1->getHealth() << endl;
    cout << character2->getName() << " health: " << character2->getHealth() << endl;
    cout << "------------------------------------------------------" << endl;

    if (character1->getIsDead()) {
        cout << character2->getName() << " won!" << endl;
    } else {
        cout << character1->getName() << " won!" << endl;
    }
}

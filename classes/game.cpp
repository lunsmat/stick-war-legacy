#include <iostream>
#include <array>
#include "./game.h"
#include "./character.h"
#include "./magikill.h"
#include "./miner.h"
#include "./update.h"
#include "./magikillMinionUpdate.h"

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

    Magikill* magikill = new Magikill("Magikill", 200, 1500, 9, 1000, 1, 1000, 500, 2, 12000);
    Miner* miner = new Miner("Miner", 100, 1000, 6.0, 1000, 1, 1000, 25, 1, 5000);

    array<Character*, 5> characters = {
        new Character("Swordwrath", 100, 1000, 14.4, 1000, 1, 1000, 125, 1, 8000),
        new Character("Spearton", 440, 1130, 15, 750, 1, 1400, 500, 2, 12000),
        magikill,
        new Character("Giant", 1500, 4000, 25, 4000, 1, 1000, 1500, 5, 20000),
        miner
    };

    // Swordwrath updates
    // 20% increase damage
    characters[0]->addUpdate(new Update("Swordwrath Sword", "Increases the Swordwrath damage by 20%.", 0.0, 0.0, 0.2, 0.0));
    // Helmet - 20% increase health, 10% increase speed
    characters[0]->addUpdate(new Update("Swordwrath Helmet", "Increases the Swordwrath health by 20% and speed by 10%.", 0.2, 0.1, 0.0, 0.0));

    // Spearton updates
    // helmet - 20% increase health
    characters[1]->addUpdate(new Update("Spearton Helmet", "Increases the Spearton health by 20%.", 0.2, 0.0, 0.0, 0.0));
    // shield - 10% increase health
    characters[1]->addUpdate(new Update("Spearton Shield", "Increases the Spearton health by 10%.", 0.1, 0.0, 0.0, 0.0));
    // spear - 25% increase damage
    characters[1]->addUpdate(new Update("Spearton Spear", "Increases the Spearton damage by 25%.", 0.0, 0.0, 0.25, 0.0));

    // Magikill updates
    // staff - 15% increase damage, 5% increase foot speed
    characters[2]->addUpdate(new Update("Magikill Staff", "Increases the Magikill damage by 15% and foot speed by 5%.", 0.0, 0.05, 0.15, 0.0));

    // Miner updates
    // none

    cout << "Characters:" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int i = 0; i < characters.size(); i++) {
        cout << *characters[i] << endl;
        cout << "------------------------------------------------------" << endl;
    }

    Character swordwrath = Character(*characters[0]);
    Character spearton = Character(*characters[1]);

    for (int i = 0; i < swordwrath.getUpdateCount(); i++)
    {
        for (int j = 0; j < Update::MAX_LEVEL; j++) {
            swordwrath.updateSlot(i);
        }
    }

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

/**
 * 301884805.
 * Ophir Haroche.
 */

#include "HumanPlayer.h"
#include <iostream>
#include <limits>

using namespace std;

/**
 * Create a new human player instance.
 */
HumanPlayer::HumanPlayer(){}

/**
 * Destructor.
 */
HumanPlayer::~HumanPlayer() {}

/**
 * Get the player's name.
 * @return The player's name.
 */
std::string HumanPlayer::getName() {
    return this->playerName;
}

/**
 * Set a new name.
 * @param name The new name.
 */
void HumanPlayer::setName() {
    std::string name;
    bool notValidName = true;
    cout << "Please enter a valid (non empty) name:\n";
    while (notValidName) {
        getline( cin , name);
        if (!(name.empty())) {
            notValidName = false;
            this->playerName = name;
            cout << "Thank you! Your name is "<< name <<"\n";
        }
    }
}


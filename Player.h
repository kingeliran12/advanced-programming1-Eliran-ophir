/**
 * 301884805.
 * Ophir Haroche.
 */


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Move.h"

/**
 * Represents a Player in the game.
 */
class Player {
public:
    /**
     * Destructor.
     */
    virtual ~Player() {}

    /**
     * Get the player's name.
     * @return The player's name.
     */
    virtual std::string getName() = 0;

    virtual void setName() = 0;

private:

};
#endif //PLAYER_H

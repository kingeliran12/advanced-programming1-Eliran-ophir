/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef EX1_HUMANPLAYER_H
#define EX1_HUMANPLAYER_H

#include "Player.h"

/**
 * Represents a human player.
 */
class HumanPlayer : public Player {

public:

    /**
     * Creates a new human player instance.
     */
    HumanPlayer();

    /**
     * Destructor.
     */
    ~HumanPlayer();

    /**
     * Get the human player's name.
     * @return The human player's name.
     */
    std::string getName();

    /**
     * Set name.
     * @param name New name.
     */
    void setName();
private:

    /**
     * The human player's name.
     */
    std::string playerName;
};

#endif //EX1_HUMANPLAYER_H

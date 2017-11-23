/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <vector>
#include "GameUI.h"
#include "Move.h"
#include "Board.h"
#include "GameLogic.h"

/**
 * Represents a game board coordinate.
 */
class GameManager {

public:
    /**
     * Create a new instance of game manager.
     */
    GameManager();

    /**
     * Destructor.
     */
    ~GameManager();

    /**
     * Initializes a reversi game game.
     */
    void initializeGame();

    /**
     * Play one turn.
     */
    bool playOneTurn();

    /**
     * Check no more moves ending type.
     * @return
     */
    bool checkNoMovesEnd();

    /**
     * Play one game.
     */
    void playOneGame();

    /**
     * Check if the board is full.
     * @return True if the board is full, false otherwise.
     */
    bool isBoardFull();

private:
    Board* gameBoard;
    GameLogic* gameLogic;
    Player* playerOne;
    Player* playerTwo;
    GameUI* gameUI;
};

#endif //GAMEMANAGER_H

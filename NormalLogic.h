/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef NORMALLOGIC_H
#define NORMALLOGIC_H

#include "GameLogic.h"

/**
 * Represents a normal reversi game logic.
 */
class NormalLogic : public GameLogic {

public:

    /**
     * Create a new game logic instance.
     */
    NormalLogic();

    /**
     * Destructor.
     */
    ~NormalLogic();

    /**
     * Check if the argument
     * @param move
     * @param gameBoard
     * @return
     */
    bool isValidMove(Move move, Board gameBoard);
    bool changeTurn(Board gameBoard);
    bool checkEndNoValidMoves(Board gameBoard);
    std::vector<Move> getValidMoves(Board gameBoard);
    SquareState getWinner(Board gameBoard);
    std::vector<Move> requestMove(Board gameBoard, Move move);
    SquareState getCurrentPlayerColor();
    SquareState getNotPlayingPlayerColor();


private:
    SquareState currentPlayer;
};

#endif //NORMALLOGIC_H

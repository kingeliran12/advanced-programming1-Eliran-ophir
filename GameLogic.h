/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef EX1_GAMELOGIC_H
#define EX1_GAMELOGIC_H

#include <jmorecfg.h>
#include "Board.h"
#include "Player.h"
#include <vector>

class GameLogic {
public:
    /**
     * Virtual destructor.
     */
    virtual ~GameLogic() {}

    /**
     * Check if the argument move is valid.
     * @param move The move to check.
     * @param gameBoard The game board.
     * @return True if valid, false otherwise.
     */
    virtual bool isValidMove(Move move, Board gameBoard) = 0;

    /**
     * Change turn according to logic.
     * @param gameBoard The game board.
     * @return True if turn has changed, false otherwise.
     */
    virtual bool changeTurn(Board gameBoard) = 0;

    /**
     * Check end condition - no valid moves, according to logic.
     * @param gameBoard The game board.
     * @return True if game has ended, false otherwise.
     */
    virtual bool checkEndNoValidMoves(Board gameBoard) = 0;

    /**
     * Get valid moves according to logic.
     * @param gameBoard The game board.
     * @return Valid moves vector.
     */
    virtual std::vector<Move> getValidMoves(Board gameBoard) = 0;

    /**
     * Get the game winner, according to logic.
     * @param gameBoard The game board.
     * @return The game winner.
     */
    virtual SquareState getWinner(Board gameBoard) = 0;

    /**
     * Request a move, and recieve its implications, according to logic.
     * @param gameBoard The game board.
     * @param move The move made.
     * @return Vector of moves.
     */
    virtual std::vector<Move> requestMove(Board gameBoard, Move move) = 0;

    /**
     * Get the currently playing player's color.
     * @return The currently playing player's color.
     */
    virtual SquareState getCurrentPlayerColor() = 0;

    /**
     * Get the currently not playing player's color.
     * @return The currently not playing player's color.
     */
    virtual SquareState getNotPlayingPlayerColor() = 0;

};

#endif //GAMELOGIC_H

/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include "Move.h"

/**
 * Enumarator that represents a square state.
 */
enum SquareState {Black, White, Empty ,Invalid};

/**
 * A class that represents a reversi game board.
 */
class Board {

public:

    /**
     * Enumarator that represents a square state.
     */

    /**
     * Creates a new board instance.
     */
    Board();

    /**
     * Destructor.
     */
    ~Board();

    /**
     * Sets a new square state.
     * @param row The square's row.
     * @param column The square's column.
     * @param squareState The square's state.
     */
    void setSquare(int row, int column, SquareState squareState);

    /**
     * Gets a square state.
     * @param row The square's row.
     * @param column The square's column.
     * @return The square's state.
     */
    SquareState getSquareState(int row, int column);

    /**
     * Get the number of rows the board has.
     * @return The number of rows the board has.
     */
    int getNumOfRows();

    /**
     * Get the number of columns the board has.
     * @return The number of columns the board has.
     */
    int getNumOfColumns();

    /**
     * Update the board with the argument moves with accordance to the argument
     * square state.
     * @param movesToUpdate The moves that the board will be updated with.
     * @param squareState The square state that with it the board will be updated.
     */
    void updateBoard(std::vector<Move> movesToUpdate, SquareState squareState);

    /**
     * Check if the board is full.
     * @return True if the board is full, false otherwise.
     */
    bool isFull();

private:

    /**
     * The board size constant (squared).
     */
    static const int BOARD_SIZE = 8;

    /**
     * The board representation.
     */
    SquareState boardArray[BOARD_SIZE][BOARD_SIZE];
};

#endif //BOARD_H_

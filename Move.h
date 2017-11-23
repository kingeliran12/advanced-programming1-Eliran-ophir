/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <zconf.h>
#include <string>
using namespace std;

/**
 * Represents a game board coordinate.
 */
class Move {

public:
    /**
     * Creates a new move.
     * @param row The move's row.
     * @param column The move's column.
     */
    Move(int row, int column);

    /**
     * Destructor.
     */
    ~Move();

    /**
     * Get the move's row.
     * @return The move's row.
     */
    int getRow();

    /**
     * Get the move's column.
     * @return The move's column.
     */
    int getColumn();

    /**
     * Compare this move to other move.
     * @param otherMove The other move.
     * @return True if the moves are equal (by value), false otherwise.
     */
    bool operator == (const Move& otherMove) const;

    friend ostream &operator <<(ostream &out, const Move &frac);

private:

    /**
     * The move's row.
     */
    int row;

    /**
     * The move's column.
     */
    int column;

};

#endif //COORDINATE_H

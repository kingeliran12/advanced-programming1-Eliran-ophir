/**
 * 301884805.
 * Ophir Haroche.
 */

#include <iostream>
#include "Move.h"

using namespace std;

Move::Move(int row, int column) : row(row), column(column) {
    this->row = row;
    this->column = column;
}

Move::~Move() {}

bool Move::operator == (const Move& otherMove) const {
    return  ((this->row == otherMove.row) && (this->column == otherMove.column));
}

int Move::getRow() {
    return this->row;
}

int Move::getColumn() {
    return this->column;
}
ostream &operator <<(ostream &out, const Move &move)
{
    out << "(" << move.row << ", " << move.column << ")";
    return out;
}





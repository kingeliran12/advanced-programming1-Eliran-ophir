/**
 * 301884805.
 * Ophir Haroche.
 */

#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

Board::Board(){
    for (int i = 1; i <= BOARD_SIZE; i++){
        for (int j = 1; j <= BOARD_SIZE; j++){
            this->setSquare(i, j, Empty);
        }
    }

    this->setSquare(4, 4, White);
    this->setSquare(5, 5, White);
    this->setSquare(5, 4, Black);
    this->setSquare(4, 5, Black);

}

Board::~Board() {}

void Board::setSquare(int row, int column, SquareState squareState) {
    switch (squareState){
        case Black:
            boardArray[row-1][column-1] = Black;
            break;
        case White:
            boardArray[row-1][column-1] = White;
            break;
        case Empty:
            boardArray[row-1][column-1] = Empty;
    }
}

int Board::getNumOfColumns() {
    return BOARD_SIZE;
}

int Board::getNumOfRows() {
    return BOARD_SIZE;
}

SquareState Board::getSquareState(int row, int column) {
    if ((row > this->getNumOfRows()) || (row <= 0) || (column > this->getNumOfColumns()) ||
        (column <= 0)) {
        return Invalid;
    }
    return boardArray[row - 1][column - 1];
}

void Board::updateBoard(vector<Move> movesToUpdate, SquareState squareState) {
    for(int i=0; i < movesToUpdate.size(); i++){
        int row = movesToUpdate[i].getRow();
        int col = movesToUpdate[i].getColumn();
        this->setSquare(row, col, squareState);
    }
}

bool Board::isFull() {
    for (int row = 1; row <= this->getNumOfRows(); row++) {
        for (int column = 1; column <= this->getNumOfColumns(); column++) {
            if (this->getSquareState(row, column) == Empty) {
                return false;
            }
        }
    }
    return true;
}


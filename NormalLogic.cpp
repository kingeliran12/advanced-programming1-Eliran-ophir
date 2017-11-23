/**
 * 301884805.
 * Ophir Haroche.
 */

#include "NormalLogic.h"
#include <algorithm>

using namespace std;

NormalLogic::NormalLogic() : currentPlayer(Black) {}
NormalLogic::~NormalLogic() {}

/**
 * Change turn.
 */
bool NormalLogic::changeTurn(Board gameBoard) {

    // If black just played, check if white has valid moves left?
    if (this->currentPlayer == Black) {
        this->currentPlayer = White;
        vector<Move> validMoves = getValidMoves(gameBoard);
        if (validMoves.size() == 0) {
            this->currentPlayer = Black;
            return false;
        }
        return true;
    }

    // If white just played, check if black has valid moves left?
    if (this->currentPlayer == White) {
        this->currentPlayer = Black;
        vector<Move> validMoves = getValidMoves(gameBoard);
        if (validMoves.size() == 0) {
            this->currentPlayer = White;
            return false;
        }
        return true;
    }

}

vector<Move> NormalLogic::getValidMoves(Board gameBoard) {
    vector<Move> validMoves;
    SquareState enemyColor;
    SquareState playerColor;
    int contCheckedRow = 0;
    int contCheckedCol = 0;
    if (this->currentPlayer == Black) {
        playerColor = Black;
        enemyColor = White;
    } else {
        playerColor = White;
        enemyColor = Black;
    }

    for (int row = 1; row <= gameBoard.getNumOfRows(); row++) {
        for (int col = 1; col <= gameBoard.getNumOfColumns(); col++) {

            // Find an empty square.
            if (gameBoard.getSquareState(row, col) == Empty) {

                // Check the squares around it.
                for (int dRow = -1; dRow <= 1; dRow++) {
                    for (int dCol = -1; dCol <= 1; dCol++) {

                        // If the neighbour square is still on board, and not the original square:
                        if ((dRow != 0 || dCol != 0) && (row + dRow >= 1) &&
                            (row + dRow <= gameBoard.getNumOfRows()) && (col + dCol >= 1) &&
                            (col + dCol <= gameBoard.getNumOfColumns())) {

                            // If it has an enemy piece:
                            if (gameBoard.getSquareState(row + dRow, col + dCol) == enemyColor) {
                                contCheckedRow = row + dRow;
                                contCheckedCol = col + dCol;

                                // Continue to check on this direction while still on the board.
                                while ((contCheckedRow >= 1) && (contCheckedRow <= gameBoard.getNumOfRows()) &&
                                       (contCheckedCol >= 1) && (contCheckedCol <= gameBoard.getNumOfColumns()) &&
                                       (gameBoard.getSquareState(contCheckedRow, contCheckedCol) != Empty)) {
                                    contCheckedRow += dRow;
                                    contCheckedCol += dCol;

                                    // If a hero piece is found:
                                    if (gameBoard.getSquareState(contCheckedRow, contCheckedCol) == playerColor) {

                                        // Add this move to the vector of valid moves.
                                        Move optionalMove = Move(row, col);
                                        if (find(validMoves.begin(), validMoves.end(), optionalMove) ==
                                            validMoves.end()) {
                                            validMoves.push_back(optionalMove);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return validMoves;
}

/**
 * Checks if an argument move is a valid move.
 * @param move The argument move.
 * @param gameBoard The game board.
 * @return True if valid move, false otherwise.
 */
bool NormalLogic::isValidMove(Move move, Board gameBoard) {
    vector<Move> validMoves = getValidMoves(gameBoard);
    return !(find(validMoves.begin(), validMoves.end(), move) == validMoves.end());
}

bool NormalLogic::checkEndNoValidMoves(Board gameBoard) {
    vector<Move> currentPlayerValidMoves = getValidMoves(gameBoard);
    if (currentPlayerValidMoves.size() != 0) {
        return false;
    }
    changeTurn(gameBoard);
    vector<Move> otherPlayerValidMoves = getValidMoves(gameBoard);
    changeTurn(gameBoard);
    if (otherPlayerValidMoves.size() != 0) {
        return false;
    }
    return true;
}

SquareState NormalLogic::getWinner(Board gameBoard) {
    int rows = gameBoard.getNumOfRows();
    int columns = gameBoard.getNumOfColumns();
    int black = 0;
    int white = 0;
    for (int row = 1; row <= rows; row++) {
        for (int col = 1; col <= columns; col++) {
            if (gameBoard.getSquareState(row, col) == Black) {
                black += 1;
            }
            if (gameBoard.getSquareState(row, col) == White) {
                white += 1;
            }
        }
    }
    if (black == white) {
        return Empty;
    }
    if (black > white) {
        return Black;
    }
    return White;
}

vector<Move> NormalLogic::requestMove(Board gameBoard, Move move) {
    vector<Move> movesToMake;
    int row = move.getRow();
    int col = move.getColumn();
    SquareState enemyColor;
    SquareState playerColor;
    int contCheckedRow = 0;
    int contCheckedCol = 0;
    if (this->currentPlayer == Black) {
        playerColor = Black;
        enemyColor = White;
    } else {
        playerColor = White;
        enemyColor = Black;
    }

    // Check around the move square:
    for (int dRow = -1; dRow <= 1; dRow++) {
        for (int dCol = -1; dCol <= 1; dCol++) {

            // Check its not the original square and still on board:
            if ((dRow != 0 || dCol != 0) && (row + dRow >= 1) &&
                (row + dRow <= gameBoard.getNumOfRows()) && (col + dCol >= 1) &&
                (col + dCol <= gameBoard.getNumOfColumns())) {

                // If we found an enemy piece:
                if (gameBoard.getSquareState(row + dRow, col + dCol) == enemyColor) {
                    contCheckedRow = row + dRow;
                    contCheckedCol = col + dCol;

                    // Continue to search that direction.
                    while ((contCheckedRow >= 1) && (contCheckedRow <= gameBoard.getNumOfRows()) &&
                           (contCheckedCol >= 1) && (contCheckedCol <= gameBoard.getNumOfColumns() &&
                                                     (gameBoard.getSquareState(contCheckedRow, contCheckedCol) != Empty))) {
                        contCheckedRow += dRow;
                        contCheckedCol += dCol;

                        // If we found a hero piece:
                        if (gameBoard.getSquareState(contCheckedRow, contCheckedCol) == playerColor) {

                            // Go backwords in the same direction and add all the enemy pieces on the way.
                            while (gameBoard.getSquareState(contCheckedRow -= dRow, contCheckedCol -= dCol) == enemyColor) {
                                Move move = Move(contCheckedRow, contCheckedCol);
                                movesToMake.push_back(move);
                            }
                        }
                    }
                }
            }
        }
    }
    // Add the original move (piece).
    movesToMake.push_back(move);
    return movesToMake;
}

/**
 * Get current player's color.
 * @return Current player's color.
 */
SquareState NormalLogic::getCurrentPlayerColor() {
    return this->currentPlayer;
}

SquareState NormalLogic::getNotPlayingPlayerColor() {
    if (this->currentPlayer == Black) {
        return White;
    }
    return Black;
}
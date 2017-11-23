/**
 * 301884805.
 * Ophir Haroche.
 */

#include "ConsoleUI.h"
#include <limits>

using namespace std;

ConsoleUI::ConsoleUI() {}

ConsoleUI::~ConsoleUI() {}

void ConsoleUI::displayBoardMessage(Board gameBoard) {
    int numCols = gameBoard.getNumOfColumns();
    int numRows = gameBoard.getNumOfRows();

    std::string boundsPerSquare = std::string(4 * numCols, '-');

    // Starts from 0 because of the title line.
    for (int i = 0; i <= numCols; i++){

        // If this is the title line:
        if (i == 0) {

            // Print the row numbers.
            cout << " |";
            for (int k = 1; k <= numRows; k++) {
                cout << " " << k << " |";
            }
            cout << "" << endl;
        } else { // If not title line:
            cout << i << "|";
            for (int j = 0; j <= numCols; j++){

                // print board according to representation.
                switch (gameBoard.getSquareState(i, j)){
                    case Black: cout << " x |";
                        break;
                    case White: cout << " o |";
                        break;
                    case Empty: cout << "   |";
                        break;
                }
            }
            cout << "" << endl;
        }
        cout << "--" + boundsPerSquare << endl;
    }
}

void ConsoleUI::welcomeMessage() {
    cout << "Welcome to my reversi game!!!" << endl;
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
}

void ConsoleUI::assignXPlayerMessage(Player* playerOne) {
    cout << "Player 1 - you will be the black player. Your piece is: x." << endl;
    playerOne->setName();
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
}

void ConsoleUI::assignOPlayerMessage(Player* playerTwo) {
    cout << "Player 2 - you will be the white player. Your piece is: o" << endl;
    playerTwo->setName();
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
}


void ConsoleUI::yourTurnMessage(std::string playerName) {
    cout << playerName << ": Its your turn!" << endl;
}

void ConsoleUI::gameEndMessage() {
    cout << "Thank you for playing!" << endl;
}

void ConsoleUI::gameStartMessage() {
    cout << "The game will now start!!!" << endl;
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
}

void ConsoleUI::invalidMoveMessage(Move invalidMove, string playerName) {
    cout << playerName << " your move: " << invalidMove << " is invalid. please enter another." << endl;
}

void ConsoleUI::validMovesMessage(std::vector<Move>& validMoves, SquareState playerColor) {
    string color;
    if (playerColor == Black) {
        color = "Black player: ";
    } else {
        color = "White player: ";
    }
    cout << color << "Your valid moves are: " << endl;
    for (int i = 0; i < validMoves.size(); i++) {
        cout << validMoves[i];
    }
    cout <<endl;
}

Move ConsoleUI::getMove(SquareState player, Board board) {
    int row;
    int column;
    cout << "Please enter row number: "<<endl;
    while (!(cin >> row) || cin.get() != '\n') {
        cout << "Error. row number must be integer. Try again: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
    }

    cout << "Please enter column number: "<<endl;
    while (!(cin >> column) || cin.get() != '\n') {
        cout << "Error. column number must be integer. Try again: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
    }
    Move move = Move(row, column);
    return move;
}

void ConsoleUI::moveMade(Move move, string playerName) {
    cout << playerName << " made the move: " << move << endl;
}

void ConsoleUI::boardFullMessage() {
    cout << "The board has been filled - The game is over." << endl;
}

void ConsoleUI::noMovesLeftMessage() {
    cout << "There are no moves left for both players - The game is over." << endl;
}

void ConsoleUI::declareWinnerMessage(SquareState winnerColor) {
    string winnerStatusMessage;
    if (winnerColor == Black) {
        winnerStatusMessage = "The winner is the black player.";
    } else if (winnerColor == White) {
        winnerStatusMessage = "The winner is the white player.";
    } else if (winnerColor == Empty) {
        winnerStatusMessage = "This game is a draw.";
    }
    cout << winnerStatusMessage << endl;
}

void ConsoleUI::playerHasNoMovesMessage(SquareState playerColor) {
    string player;
    if (playerColor == Black) {
        player = "The black player";
    } else {
        player = "The white player";
    }
    cout << player << " has no moves to make, his turn is skipped." << endl;
}


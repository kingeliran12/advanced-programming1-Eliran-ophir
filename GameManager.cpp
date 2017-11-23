/**
 * 301884805.
 * Ophir Haroche.
 */

#include <iostream>
#include "GameManager.h"
#include "NormalLogic.h"
#include "HumanPlayer.h"
#include "ConsoleUI.h"

using namespace std;

GameManager::GameManager() {
    this->gameBoard = new Board();
    this->gameLogic = new NormalLogic();
    this->playerOne = new HumanPlayer();
    this->playerTwo = new HumanPlayer();
    this->gameUI = new ConsoleUI();
}

GameManager::~GameManager() {
    delete gameBoard;
    delete gameLogic;
    delete playerOne;
    delete playerTwo;
    delete gameUI;
}

void GameManager::initializeGame() {
    gameUI->welcomeMessage();
    gameUI->assignXPlayerMessage(this->playerOne);
    gameUI->assignOPlayerMessage(playerTwo);
    gameUI->gameStartMessage();

}

bool GameManager::playOneTurn() {
    vector<Move> validMoves;
    vector<Move> madeMoves;
    SquareState currentColor;
    string playerName;
    bool notValidMove = true;

    gameUI->displayBoardMessage(*gameBoard);
    validMoves = gameLogic->getValidMoves(*gameBoard);

    // Check which player's turn.
    currentColor = gameLogic->getCurrentPlayerColor();
    if (currentColor == Black) {
        playerName = playerOne->getName();
    } else {
        playerName = playerTwo->getName();
    }
    gameUI->yourTurnMessage(playerName);
    gameUI->validMovesMessage(validMoves, currentColor);

    // Make sure the move is valid.
    while (notValidMove) {
        Move moveAttempt = gameUI->getMove(currentColor, *gameBoard);
        if (gameLogic->isValidMove(moveAttempt, *gameBoard)) {
            madeMoves = gameLogic->requestMove(*gameBoard, moveAttempt);
            notValidMove = false;
            gameBoard->updateBoard(madeMoves, currentColor);
            gameUI->moveMade(moveAttempt, playerName);

        } else {
            gameUI->invalidMoveMessage(moveAttempt, playerName);
        }
    }

    // Check if the turn swap was made.
    bool turnChanged = gameLogic->changeTurn(*gameBoard);
    if ((!turnChanged) && (!gameLogic->checkEndNoValidMoves(*gameBoard))) {
        SquareState  noMovesPlayer = this->gameLogic->getNotPlayingPlayerColor();
        this->gameUI->playerHasNoMovesMessage(noMovesPlayer);
    }
    return turnChanged;
}

void GameManager::playOneGame() {
    bool gameNotEnded = true;
    bool turnPassed;

    this->initializeGame();

    // While the game is still going:
    while (gameNotEnded) {
        turnPassed = this->playOneTurn();

        // If the board is full, end the game and declare winner.
        if (this->isBoardFull()) {
            this->gameUI->boardFullMessage();
            SquareState winnerColor = this->gameLogic->getWinner(*gameBoard);
            gameUI->displayBoardMessage(*gameBoard);
            gameUI->declareWinnerMessage(winnerColor);
            gameNotEnded = false;

            // If the turn swap was not executed, check if game ended because both have no moves.
        } else if (!(turnPassed)) {
            if (this->checkNoMovesEnd()) {
                this->gameUI->noMovesLeftMessage();
                SquareState winnerColor = this->gameLogic->getWinner(*gameBoard);
                gameUI->displayBoardMessage(*gameBoard);
                gameUI->declareWinnerMessage(winnerColor);
                gameNotEnded = false;
            }
        }
    }
    this->gameUI->gameEndMessage();
}

bool GameManager::checkNoMovesEnd() {
    bool noValidMoves = this->gameLogic->checkEndNoValidMoves(*gameBoard);
    return noValidMoves;
}

bool GameManager::isBoardFull() {
    return this->gameBoard->isFull();
}






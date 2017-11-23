/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef GAMEUI_H
#define GAMEUI_H


#include "Board.h"
#include "Player.h"

class GameUI {
public:
    virtual void displayBoardMessage(Board board) = 0;
    virtual void welcomeMessage() = 0;
    virtual void assignXPlayerMessage(Player* playerOne) = 0;
    virtual void assignOPlayerMessage(Player* playerTwo) = 0;
    virtual void gameStartMessage() = 0;
    virtual void declareWinnerMessage(SquareState winnerColor) = 0;
    virtual void yourTurnMessage(std::string playerName ) = 0;
    virtual void gameEndMessage() = 0;
    virtual void invalidMoveMessage(Move move, string playerName) = 0;
    virtual void validMovesMessage(std::vector<Move>& validMoves, SquareState playerColor) = 0;
    virtual Move getMove(SquareState player, Board board) = 0;
    virtual void moveMade(Move move, string playerName) = 0;
    virtual void boardFullMessage() = 0;
    virtual void noMovesLeftMessage() = 0;
    virtual void playerHasNoMovesMessage(SquareState playerColor) = 0;

};


#endif //GAMEUI_H

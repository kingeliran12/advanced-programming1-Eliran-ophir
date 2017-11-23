/**
 * 301884805.
 * Ophir Haroche.
 */

#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include "GameUI.h"

class ConsoleUI : public GameUI {
public:

    /**
     * Create a new console user interface.
     */
    ConsoleUI();

    /**
     * Destructor.
     */
    ~ConsoleUI();

    /**
     * Display the game board message.
     * @param gameBoard The game board.
     */
    void displayBoardMessage(Board gameBoard);

    /**
     * Welcome message.
     */
    void welcomeMessage();

    /**
     * Assign x player.
     * @param xPlayer The x player.
     */
    void assignXPlayerMessage(Player* playerOne);

    /**
     * Assign o player.
     * @param oPlayer The o player.
     */
    void assignOPlayerMessage(Player* playerTwo);

    /**
     * Change of turn message.
     * @param nextPlayer The player who's next.
     */
    void yourTurnMessage(std::string playerName);

    /**
     * Game end message.
     */
    void gameEndMessage();

    /**
     * Game start message.
     */
    void gameStartMessage();

    /**
     * Invalid move message.
     */
    void invalidMoveMessage(Move move, string playerName);

    /**
     * Valid move message.
     */
    void validMovesMessage(std::vector<Move>& validMoves, SquareState playerColor);

    /**
     * Get move message.
     * @param player The player who makes the move.
     * @param board The game board.
     * @return The move made.
     */
    Move getMove(SquareState player, Board board);

    /**
     * Move made message.
     * @param move The move made.
     */
    void moveMade(Move move, string playerName);

    /**
     * Board is full message.
     */
    void boardFullMessage();

    /**
     * No more moves left for both players message.
     */
    void noMovesLeftMessage();

    /**
     * Declare winner message.
     * @param winnerColor The winner's color.
     */
    void declareWinnerMessage(SquareState winnerColor);

    /**
     * Player has no moves message.
     * @param playerColor The out of moves player's color.
     */
    void playerHasNoMovesMessage(SquareState playerColor);

};
#endif //CONSOLEUI_H

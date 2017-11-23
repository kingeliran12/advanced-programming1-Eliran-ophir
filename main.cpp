/**
 * 301884805.
 * Ophir Haroche.
 */

#include <limits>
#include <iostream>
#include "Move.h"
#include <vector>
#include <algorithm>
#include "HumanPlayer.h"
#include "Board.h"
#include "NormalLogic.h"
#include "GameManager.h"

using namespace std;

int main() {

    GameManager* manager = new GameManager();
    manager->playOneGame();
    delete manager;



}
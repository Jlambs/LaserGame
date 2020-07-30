#include <iostream>
#include <vector>
#include "LaserGame.h"

int main() {

  // Initialize game
  int board_size_x = 7;  // should be odd
  int board_size_y = 7;  // shoud be odd
  int num_players = 2;
  //LaserGame laser_game = LaserGame();  // default 2 players and [7][7] board
  LaserGame laser_game = LaserGame(num_players, board_size_x, board_size_y);

  laser_game.PrintBoard();

  // TODO: Remove above and use LaserGameFactory

}

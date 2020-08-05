#include "LaserGame.h"


std::ostream& operator<<(std::ostream& os, const Tile &t) {
	switch (t.type)
	{

		case TileType::Empty:
			os << '.';
			break;

		case TileType::Mirror:

			switch (t.dir) {
				case Direction::PosSlope:
					os << '/';
					break;
				case Direction::NegSlope:
					os << '\\';
					break;
				default:
					// error handling here
					os << '?';
			}

			break;

		case TileType::Player:

			switch (t.dir) {
				case Direction::PosX:
					os << '>';
					break;
				case Direction::PosY:
					os << '^';
					break;
				case Direction::NegX:
					os << '<';
					break;
				case Direction::NegY:
					os << 'v';
					break;
				default:
					// error handling here
					os << '?';
			}

			break;

		case TileType::Laser:
			switch (t.dir) {
				case Direction::PosX:
					os << '-';
					break;
				case Direction::PosY:
					os << '|';
					break;
				case Direction::NegX:
					os << '-';
					break;
				case Direction::NegY:
					os << '|';
					break;
				default:
					// error handling here
					os << '?';
			}

			break;

		case TileType::Block:
			os << '#';
			break;

		default:
			// error handling here
			os << "?";
	}

	return os;
}

Board::Board(const int max_x, const int max_y) {
	max_x_ = max_x;
	max_y_ = max_y;

	for (int i = 0; i < max_x_; i++) {
		std::vector<Tile> new_row;
    for (int j = 0; j < max_y_; j++) {
			// TODO: Use tile factory
			//Tile new_tile = {TileType::Empty, Direction::None};
      new_row.push_back(new_tile);
    }
		tiles_.push_back(new_row);
  }
}

// returns false if Tile.type_fixed is true
bool Board::SetTileType(Position pos, TileType type) {
  if (tiles_[pos.x][pos.y].type_fixed) { return false; }
	else {
		tiles_[pos.x][pos.y].type = type;
		return true;
	}
}

// returns false if Tile.dir_fixed is true
bool Board::SetTileDirection(Position pos, Direction dir) {
	if (tiles_[pos.x][pos.y].dir_fixed) { return false; }
	else {
		tiles_[pos.x][pos.y].dir = dir;
		return true;
	}
}

// returns false if Tile.dir_fixed is true
bool Board::Rotate(Position pos, bool rot_CCW) {

	Direction new_dir = Direction::None;

	switch (tiles_[pos.x][pos.y].type) {
		case TileType::Mirror:

			switch (tiles_[pos.x][pos.y].dir) {
				case Direction::PosSlope:
					new_dir = Direction::NegSlope;
					break;
				case Direction::NegSlope:
					new_dir = Direction::PosSlope;
					break;
				default:
					// error handling here
					std::cout << "Unrecognized mirror direction! Cannot rotate.\n";
			}

			break;

		// case TileType::Player:
		//
		// 	switch (tiles_[pos.x][pos.y].dir) {
		// 		case Direction::PosX:
		// 			new_dir = rot_CCW ? Direction::PosY : Direction::NegY;
		// 			break;
		// 		case Direction::PosY:
		// 			new_dir = rot_CCW ? Direction::NegX : Direction::PosX;
		// 			break;
		// 		case Direction::NegX:
		// 			new_dir = rot_CCW ? Direction::NegY : Direction::PosY;
		// 			break;
		// 		case Direction::NegY:
		// 			new_dir = rot_CCW ? Direction::PosX : Direction::NegX;
		// 			break;
		// 		default:
		// 			// error handling here
		// 			std::cout << "Unrecognized player direction! Cannot rotate.\n";
		// 	}
		//
		// 	break;

		default:
			// error handling here
			std::cout << "Can only rotate tiles of type Mirror!\n";// or Player!\n";

	}

	if (new_dir != Direction::None) { return SetTileDirection(pos, new_dir); }
	else { return false; }
}

// returns terminal position of laser
Position FireLaser(Position pos, Direction dir) {



	bool laser_stopped = false;

	return pos;
}

std::ostream& operator<<(std::ostream& os, const Board &b) {
  //os << std::endl;
  for (int i = 0; i < b.max_x_; i++) {
    for (int j = 0; j < b.max_y_; j++) {
      os << b.tiles_[i][j];
      if (j == b.max_y_-1) { os << "\n"; }
    }
  }
  return os;
}


LaserGame::LaserGame(const std::vector<Player> players, const int board_size_x, const int board_size_y) {
	// TODO
	// if (board_size_x < 3 || board_size_y < 3) {
	// 	// error handling here
	// 	std::cout << "Warning, board too small!";
	// }
	// if (player_1_pos.x > x_len) {
	// 	// error handling here
	// 	std::cout << "Attempting to place player 1 outside of board";
	// }

	// TODO: rewrite Board constructor using tile factory
	board_ = new Board(board_size_x, board_size_y);

	for(int i=0; i < players.size(); i++) {
  	AddPlayer(player[i]);
	}

}

// TODO: TileFactory or death
bool LaserGame::AddPlayer(Player p) {
	// TODO error stuff, might not be worth it till this class goes away
	board_.SetTileType(p.pos, TileType::Player);
	board_.SetTileDirection(p.pos, p.dir);
	// TODO: this entire thing properly
	return true;
}

bool LaserGame::AddPermanentEmpty(Position pos) {
	board_.SetTileType(p.pos, TileType::Empty);
}

void LaserGame::TakeTurn(Player p) {
	// TODO
}


TileFactory::MakeEmpty() {
	Tile new_tile = {TileType::Empty};
	return new_tile;
}

TileFactory::MakeMirror(Direction dir) {
	Tile new_tile = {TileType::Mirror};
	// switch statement not strictly necessary, but framework for future error stuff
	switch (dir) {
		case Direction::PosSlope:
			new_tile.dir = dir;
			break;
		case Direction::NegSlope:
			new_tile.dir = dir;
			break;
		default:
			// error handling here
			std::cout << "Unrecognized mirror direction! Setting to Direction::None.";
	}
	return new_tile;
}

TileFactory::MakePlayer(Direction dir) {
	Tile new_tile = {TileType::Player};
	// switch statement not strictly necessary, but framework for future error stuff
	switch (dir) {
		case Direction::PosX:
			new_tile.dir = dir;
			break;
		case Direction::PosY:
			new_tile.dir = dir;
			break;
		case Direction::NegX:
			new_tile.dir = dir;
			break;
		case Direction::NegY:
			new_tile.dir = dir;
			break;
		default:
			// error handling here
			std::cout << "Unrecognized player direction! Setting to Direction::None.";
	}

	new_tile.type_fixed = true;
	new_tile.dir_fixed = true;  // necessary?
	new_tile.stops_laser = true;

	return new_tile;
}

TileFactory::MakeBlock() {
	Tile new_tile = {TileType::Block};
	new_tile.stops_laser = true;
	return new_tile;
}

TileFactory::MakePermanentEmpty() {
	// setting dir_fixed to true may not be necessary
	Tile new_tile = {TileType::Empty, Direction::None, true, true};
	return new_tile;
}

TileFactory::MakePermanentBlock() {
	// setting dir_fixed to true may not be necessary
	Tile new_tile = {TileType::Block, Direction::None, true, true, true};
	return new_tile;
}

TileFactory::MakePermanentMirror(Direction dir) {
	Tile new_tile = TileFactory::MakeMirror(dir);
	new_tile.type_fixed = true;
	return new_tile;
}

TileFactory::MakePermanentFixedMirror(Direction dir) {
	Tile new_tile = TileFactory::MakeMirror(dir);
	new_tile.type_fixed = true;
	new_tile.dir_fixed = true;
	return new_tile;
}

LaserGameFactory::Make2PlayerRect(int x_len, int y_len, Position player_1_pos,
	Position player_2_pos, Direction player_1_dir, Direction player_2_dir) {

	Player player_1 = Player();
	player_1.name = "Player 1";
	player_1.pos = player_1_pos;
	player_1.dir = player_1_dir;
	Player player_2 = Player();
	player_2.name = "Player 2";
	player_2.pos = player_2_pos;
	player_2.dir = player_2_dir;
	std::vector<Player> players;
	players.push_back(player_1);
	players.push_back(player_2);

	return LaserGame(players, x_len, y_len);
}

LaserGameFactory::Make2PlayerSquare(int len, Position player_1_pos,
	Position player_2_pos, Direction player_1_dir, Direction player_2_dir) {
	return LaserGameFactory::Make2PlayerRect(len, len, player_1_pos, player_2_pos,
		player_1_dir, player_2_dir); 	// is this legal?
}

LaseGameFactory::Make2PlayerStandardSquare(int len) {
	if (len % 2 == 0) {
		// error handling here
		std::cout << "Must make a Standard game using an odd board size!\n";
		len = len+1;
	}
	if (len < 5) {
		// error handling here
		std::cout << "Board should be at least 5x5 for a Standard game!\n";
		len = 5;
	}

	Player player_1 = Player();
	player_1.name = "Player 1";
	Position player_1_pos = {len/2, 0};
	player_1.pos = player_1_pos;
	player_1.dir = Direction::PosY;

	Player player_2 = Player();
	player_2.name = "Player 2";
	Position player_2_pos = {len/2, len};
	player_2.pos = player_2_pos;
	player_2.dir = Direction::NegY;
	std::vector<Player> players;
	players.push_back(player_1);
	players.push_back(player_2);

	LaserGame game = LaserGame(players, len, len);

	// padding around players
	game.AddPermanentEmpty({len/2-1, 0});
	game.AddPermanentEmpty({len/2-1, 1});
	game.AddPermanentEmpty({len/2, 1});
	game.AddPermanentEmpty({len/2+1, 0});
	game.AddPermanentEmpty({len/2+1, 1});

	// add center mirror
	game.AddPermanentFixedMirror({len/2, len/2});

	return game;

}

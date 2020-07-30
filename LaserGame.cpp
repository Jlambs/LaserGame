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
			Tile new_tile = {TileType::Empty, Direction::None};
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

		case TileType::Player:

			switch (tiles_[pos.x][pos.y].dir) {
				case Direction::PosX:
					new_dir = rot_CCW ? Direction::PosY : Direction::NegY;
					break;
				case Direction::PosY:
					new_dir = rot_CCW ? Direction::NegX : Direction::PosX;
					break;
				case Direction::NegX:
					new_dir = rot_CCW ? Direction::NegY : Direction::PosY;
					break;
				case Direction::NegY:
					new_dir = rot_CCW ? Direction::PosX : Direction::NegX;
					break;
				default:
					// error handling here
					std::cout << "Unrecognized player direction! Cannot rotate.\n";
			}

			break;

		default:
			// error handling here
			std::cout << "Can only rotate tiles of type Mirror or Player!\n";

	}

	if (new_dir != Direction::None) { return SetTileDirection(pos, new_dir); }
	else { return false; }
}

// returns terminal position of laser
Position FireLaser(Position pos, Direction dir) {
	// TODO
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


LaserGame::LaserGame(const int num_players, const int board_size_x, const int board_size_y) {
	// TODO
	board_ = new Board(board_size_x, board_size_y);
}


void LaserGame::TakeTurn(Player *p) {
	// TODO
}

#ifndef LASERGAME_H
#define LASERGAME_H

#include <iostream>
#include <string>
#include <vector>


enum class TileType { Empty, Mirror, Player, Laser };
enum class Direction { None, PosX, PosY, NegX, NegY, PosSlope, NegSlope };

struct Position {
	int x;
	int y;

	bool operator== (const Position& pos) {
		return x == pos.x && y == pos.y;
	}
};

struct Tile {
	TileType type;
	Direction dir;
	bool type_fixed=false;
	bool dir_fixed=false;
};

std::ostream& operator<<(std::ostream& os, const Tile &t);

struct Player {
	std::string name;
	bool is_human;

	// redundant but convenient
	Position pos;
	Direction dir;
};


class Board {
public:

	// cba doing a better constructor for now
	Board(const int max_x, const int max_y);

	int const GetMaxX() { return max_x_; }
	int const GetMaxY() { return max_y_; }

	TileType const GetTileType(Position pos) { return tiles_[pos.x][pos.y].type; }
	bool SetTileType(Position pos, TileType type);  // returns false if Tile.type_fixed is true

	Direction const GetTileDirection(Position pos) { return tiles_[pos.x][pos.y].dir; }
	bool SetTileDirection(Position pos, Direction dir);  // returns false if Tile.dir_fixed is true

	bool Rotate(Position pos, bool rot_CCW=true); // returns false if Tile.dir_fixed is true
	bool RotateCW(Position pos) { return Rotate(pos, false); }
	bool RotateCCW(Position pos) { return Rotate(pos, true); }

	Position FireLaser(Position pos, Direction dir); 	// returns terminal position of laser
	Position FireLaser(Player *p) { return FireLaser(p->pos, p->dir); }

	friend std::ostream& operator<<(std::ostream& os, const Board &b);

private:
	std::vector<std::vector<Tile>> tiles_;
	int max_x_;
	int max_y_;

};


class LaserGame {
	public:
		LaserGame(int num_players=2, int board_size_x=7, int board_size_y=7);

		void TakeTurn(Player *p);

		void PrintBoard() { std::cout << *board_ << std::endl; }

	private:
		Board* board_;
		std::vector<Player*> players_;
		//int turn_count_;

};


class LaserGameFactory {
	public:
		// TODO
};

#endif  // LASERGAME_H

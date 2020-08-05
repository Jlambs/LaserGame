#ifndef LASERGAME_H
#define LASERGAME_H

#include <iostream>
#include <string>
#include <vector>


enum class TileType { Empty, Mirror, Player, Laser, Block };
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
	Direction dir=Direction::None;
	bool type_fixed=false;
	bool dir_fixed=false;  // only really used for mirrors and players
	bool stops_laser=false;
};

std::ostream& operator<<(std::ostream& os, const Tile &t);

struct Player {
	std::string name;
	bool is_human=true;

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
	std::vector<std::vector<Tile>> tiles_;  // TODO: move to pointers and/or change entirely
	int max_x_;
	int max_y_;

};


// TODO: get rid of this whole class??
class LaserGame {
	public:
		LaserGame(std::vector<Player> players=NULL, int board_size_x=7, int board_size_y=7);

		// this must be a sign of bad design, but used for initializing board within the LaserGameFactory
		bool AddPlayer(Player p);  // returns false if player is out of bounds etc.
		bool AddPermanentEmpty(Position pos);
		bool AddPermanentMirror(Position pos);
		bool AddPermanentFixedMirror(Position pos);

		void TakeTurn(Player p);

		void PrintBoard() { std::cout << *board_ << std::endl; }

	private:
		Board* board_;
		std::vector<Player*> players_;
		int turn_count_;

};


// TODO: pointer-ify
class TileFactory {
	public:
		static Tile MakeEmpty();
		static Tile MakeMirror(Direction dir);  // PosSlope, NegSlope
		static Tile MakePlayer(Direction dir);  // PosX, PosY, NegX, NegY
		static Tile MakeBlock();

		// set type_fixed to true
		static Tile MakePermanentEmpty();
		static Tile MakePermanentBlock();
		static Tile MakePermanentMirror(Direction dir);  // does NOT set dir_fixed to true
		static Tile MakePermanentFixedMirror(Direction dir);
};


// TODO: tidy up, this is possibly being thought about wrong in general?
// BoardFactory instead??
class LaserGameFactory {
	public:
		static LaserGame Make2PlayerRect(int x_len, int y_len,
			Position player_1_pos, Position player_2_pos,
			Direction player_1_dir, Direction player_2_dir);
		static LaserGame Make2PlayerSquare(int len,
			Position player_1_pos, Position player_2_pos,
			Direction player_1_dir, Direction player_2_dir);

		// square board of odd size, one imovable mirror in center square that both
		// players face from opposite sides
		static LaserGame Make2PlayerStandardSquare(int len);
};

#endif  // LASERGAME_H

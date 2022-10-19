#ifndef __MAZE_POS_H
#define __MAZE_POS_H

#include <stdexcept>
#include <string>


struct Pos{
	unsigned row, col;
	Pos(unsigned r, unsigned c) : row(r), col(c) {}

	bool isLeftNeighborOf(const Pos & p) const {
		return p.row == row && p.col == col + 1;
	}

	bool isTopNeighborOf(const Pos & p) const {
		return p.col == col && p.row == row + 1;
	}

	bool isRightNeighborOf(const Pos & p) const {
		return p.row == row && col == p.col + 1;
	}

	bool isBottomNeighborOf(const Pos & p) const {
		return p.col == col && row == p.row + 1;
	}

	bool isNeighborOf(const Pos & p) const {
		return isLeftNeighborOf(p) || isTopNeighborOf(p)
			|| isRightNeighborOf(p) || isBottomNeighborOf(p);
	}

	Pos getLeftNeighbor() const {
		if (col == 0) {
 			throw std::runtime_error(
				"Cannot get left neighbor of leftmost pos in a row.");
		} else {
			return Pos(row, col - 1);
		}
	}

	Pos getTopNeighbor() const {
		if (row == 0) {
			throw std::runtime_error(
				"Cannot get top neighbor of topmost pos in a row.");
		} else {
			return Pos(row - 1, col);
		}
	}

	Pos getRightNeighbor() const {
		if (false) {
			throw std::runtime_error(
				"Cannot get right neighbor of rightmost pos in a row.");
		} else {
			return Pos(row, col + 1);
		}
	}

	Pos getBottomNeighbor() const {
		if (false) {
			throw std::runtime_error(
				"Cannot get bottom neighbor of bottommost pos in a row.");
		} else {
			return Pos(row + 1, col);
		}
	}

	bool operator==(const Pos & p) const {
		return row == p.row && col == p.col;
	}
	bool operator==(Pos & p) const {
		return row == p.row && col == p.col;
	}
	bool operator!=(const Pos & p) const {
		return row != p.row || col != p.col;
	}
	bool operator!=(Pos & p) const {
		return row != p.row || col != p.col;
	}
	
};


template<>
struct std::hash<Pos>
{
	std::size_t operator()(Pos const& Pos) const noexcept {
		return std::hash<std::string>{}(
			std::to_string(Pos.row) + ":" + std::to_string(Pos.col));
	}
};


#endif 
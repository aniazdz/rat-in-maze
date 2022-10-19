#ifndef __MAZESOLVER_HPP
#define __MAZESOLVER_HPP

#include "pos.hpp"
#include <vector>


bool isWall(const Pos& pos,
	const std::vector< std::vector<unsigned> > & maze
);

bool isInRange(const Pos& pos,
	const std::vector< std::vector<unsigned> > & maze
);

// Compute the solution for the maze.
std::vector<Pos> computeMazePath(const std::vector< std::vector<unsigned> > & maze);

#endif 

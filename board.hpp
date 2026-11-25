#pragma once

#include "cell.hpp"
#include "point.hpp"

class Board {
    Cell _grid[3][3];
public:
    Board();
    bool MakeMove(Point pos, Cell player);
    Cell GetCell(Point pos) const;
    bool IsFull() const;
    Cell CheckWinner() const;
};

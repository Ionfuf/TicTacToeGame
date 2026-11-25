#pragma once

#include "cell.hpp"
#include "point.hpp"
#include <iostream>

class Board {
    Cell _grid[3][3];
public:
    Board();
    Board(const Board& other);
    Board& operator=(const Board& other);
    bool operator==(const Board& other) const;

    bool MakeMove(Point pos, Cell player);
    Cell GetCell(Point pos) const;
    bool IsFull() const;
    Cell CheckWinner() const;

    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

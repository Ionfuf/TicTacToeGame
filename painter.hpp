#pragma once

#include "board.hpp"
#include "point.hpp"

class Painter {
public:
    void DrawBoard(const Board<3>& board);
    void WriteText(Point position, const char* text);
};

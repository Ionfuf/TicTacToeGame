#include "painter.hpp"
#include <iostream>

void Painter::DrawBoard(const Board& board) {
    std::cout << board;
}

void Painter::WriteText(Point position, const char* text) {
    (void)position;
    std::cout << text << "\n";
}

#include "painter.hpp"
#include <iostream>

void Painter::DrawBoard(const Board& board) {
    std::cout << "\n  0 1 2\n";
    for (int r = 0; r < 3; ++r) {
        std::cout << r << " ";
        for (int c = 0; c < 3; ++c) {
            Cell cell = board.GetCell({r, c});
            char symbol = '.';
            if (cell == Cell::X) symbol = 'X';
            else if (cell == Cell::O) symbol = 'O';
            std::cout << symbol << (c < 2 ? "|" : "");
        }
        std::cout << "\n";
        if (r < 2) std::cout << "  -+-+-\n";
    }
    std::cout << "\n";
}

void Painter::WriteText(Point position, const char* text) {
    (void)position;
    std::cout << text << "\n";
}

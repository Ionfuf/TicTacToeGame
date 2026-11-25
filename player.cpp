#include "player.hpp"
#include <iostream>
#include <vector>

Point HumanPlayer::GetMove(const Board<3>& board) {
    (void)board;
    return _listener.GetMoveInput();
}

Point BotPlayer::GetMove(const Board<3>& board) {
    std::vector<Point> emptyCells;
    for (int r = 0; r < board.GetSize(); ++r) {
        for (int c = 0; c < board.GetSize(); ++c) {
            if (board.GetCell({r, c}) == Cell::Empty) {
                emptyCells.push_back({r, c});
            }
        }
    }

    Cell opponent = (_symbol == Cell::X) ? Cell::O : Cell::X;
    for (Cell target : {_symbol, opponent}) {
        for (const Point& pt : emptyCells) {
            Board<3> copy(board);
            copy.MakeMove(pt, target);
            if (copy.CheckWinner() == target) {
                std::cout << _name << " a ales mutarea: " << pt << "\n";
                return pt;
            }
        }
    }

    if (board.GetCell({1, 1}) == Cell::Empty) {
        std::cout << _name << " a ales mutarea: " << Point(1, 1) << "\n";
        return {1, 1};
    }

    if (!emptyCells.empty()) {
        std::cout << _name << " a ales mutarea: " << emptyCells.front() << "\n";
        return emptyCells.front();
    }

    return {-1, -1};
}

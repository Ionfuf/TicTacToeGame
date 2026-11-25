#include "player.hpp"
#include <iostream>

Point HumanPlayer::GetMove(const Board& board) {
    (void)board;
    return _listener.GetMoveInput();
}

Point BotPlayer::GetMove(const Board& board) {
    Cell opponent = (_symbol == Cell::X) ? Cell::O : Cell::X;
    for (Cell target : {_symbol, opponent}) {
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (board.GetCell({r, c}) == Cell::Empty) {
                    Board copy(board);
                    copy.MakeMove({r, c}, target);
                    if (copy.CheckWinner() == target) {
                        std::cout << _name << " a ales mutarea: " << Point(r, c) << "\n";
                        return {r, c};
                    }
                }
            }
        }
    }

    if (board.GetCell({1, 1}) == Cell::Empty) {
        std::cout << _name << " a ales mutarea: " << Point(1, 1) << "\n";
        return {1, 1};
    }

    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board.GetCell({r, c}) == Cell::Empty) {
                std::cout << _name << " a ales mutarea: " << Point(r, c) << "\n";
                return {r, c};
            }
        }
    }

    return {-1, -1};
}

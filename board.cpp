#include "board.hpp"

Board::Board() {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            _grid[r][c] = Cell::Empty;
        }
    }
}

bool Board::MakeMove(Point pos, Cell player) {
    if (pos.row < 0 || pos.row >= 3 || pos.col < 0 || pos.col >= 3) {
        return false;
    }
    if (_grid[pos.row][pos.col] != Cell::Empty) {
        return false;
    }
    _grid[pos.row][pos.col] = player;
    return true;
}

Cell Board::GetCell(Point pos) const {
    if (pos.row < 0 || pos.row >= 3 || pos.col < 0 || pos.col >= 3) {
        return Cell::Empty;
    }
    return _grid[pos.row][pos.col];
}

bool Board::IsFull() const {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (_grid[r][c] == Cell::Empty) {
                return false;
            }
        }
    }
    return true;
}

Cell Board::CheckWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (_grid[i][0] != Cell::Empty && _grid[i][0] == _grid[i][1] && _grid[i][1] == _grid[i][2]) {
            return _grid[i][0];
        }
        if (_grid[0][i] != Cell::Empty && _grid[0][i] == _grid[1][i] && _grid[1][i] == _grid[2][i]) {
            return _grid[0][i];
        }
    }
    if (_grid[0][0] != Cell::Empty && _grid[0][0] == _grid[1][1] && _grid[1][1] == _grid[2][2]) {
        return _grid[0][0];
    }
    if (_grid[0][2] != Cell::Empty && _grid[0][2] == _grid[1][1] && _grid[1][1] == _grid[2][0]) {
        return _grid[0][2];
    }
    return Cell::Empty;
}

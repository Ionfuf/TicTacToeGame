#pragma once

#include "cell.hpp"
#include "point.hpp"
#include "game_exception.hpp"
#include <iostream>
#include <vector>

template <typename T>
T ClampValue(T value, T minVal, T maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

template <int N = 3>
class Board {
    Cell _grid[N][N];
    std::vector<Point> _moveHistory;

public:
    Board() {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                _grid[r][c] = Cell::Empty;
            }
        }
    }

    Board(const Board& other) : _moveHistory(other._moveHistory) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                _grid[r][c] = other._grid[r][c];
            }
        }
    }

    Board& operator=(const Board& other) {
        if (this != &other) {
            _moveHistory = other._moveHistory;
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    _grid[r][c] = other._grid[r][c];
                }
            }
        }
        return *this;
    }

    bool operator==(const Board& other) const {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (_grid[r][c] != other._grid[r][c]) return false;
            }
        }
        return true;
    }

    int GetSize() const { return N; }
    const std::vector<Point>& GetMoveHistory() const { return _moveHistory; }

    void MakeMove(Point pos, Cell player) {
        if (pos.row < 0 || pos.row >= N || pos.col < 0 || pos.col >= N) {
            throw InvalidMoveException("Coordonate in afara tablei! Foloseste valori intre 0 si " + std::to_string(N - 1) + ".");
        }
        if (_grid[pos.row][pos.col] != Cell::Empty) {
            throw InvalidMoveException("Casuta este deja ocupata! Alege alta pozitie.");
        }
        _grid[pos.row][pos.col] = player;
        _moveHistory.push_back(pos);
    }

    Cell GetCell(Point pos) const {
        if (pos.row < 0 || pos.row >= N || pos.col < 0 || pos.col >= N) {
            return Cell::Empty;
        }
        return _grid[pos.row][pos.col];
    }

    bool IsFull() const {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (_grid[r][c] == Cell::Empty) return false;
            }
        }
        return true;
    }

    Cell CheckWinner() const {
        for (int i = 0; i < N; ++i) {
            Cell rowFirst = _grid[i][0];
            if (rowFirst != Cell::Empty) {
                bool rowWin = true;
                for (int c = 1; c < N; ++c) {
                    if (_grid[i][c] != rowFirst) { rowWin = false; break; }
                }
                if (rowWin) return rowFirst;
            }

            Cell colFirst = _grid[0][i];
            if (colFirst != Cell::Empty) {
                bool colWin = true;
                for (int r = 1; r < N; ++r) {
                    if (_grid[r][i] != colFirst) { colWin = false; break; }
                }
                if (colWin) return colFirst;
            }
        }

        Cell diag1 = _grid[0][0];
        if (diag1 != Cell::Empty) {
            bool d1Win = true;
            for (int i = 1; i < N; ++i) {
                if (_grid[i][i] != diag1) { d1Win = false; break; }
            }
            if (d1Win) return diag1;
        }

        Cell diag2 = _grid[0][N - 1];
        if (diag2 != Cell::Empty) {
            bool d2Win = true;
            for (int i = 1; i < N; ++i) {
                if (_grid[i][N - 1 - i] != diag2) { d2Win = false; break; }
            }
            if (d2Win) return diag2;
        }

        return Cell::Empty;
    }

    friend std::ostream& operator<<(std::ostream& os, const Board<N>& board) {
        os << "\n  ";
        for (int c = 0; c < N; ++c) os << c << " ";
        os << "\n";
        for (int r = 0; r < N; ++r) {
            os << r << " ";
            for (int c = 0; c < N; ++c) {
                Cell cell = board.GetCell({r, c});
                char symbol = '.';
                if (cell == Cell::X) symbol = 'X';
                else if (cell == Cell::O) symbol = 'O';
                os << symbol << (c < N - 1 ? "|" : "");
            }
            os << "\n";
            if (r < N - 1) {
                os << "  ";
                for (int c = 0; c < N; ++c) os << "-" << (c < N - 1 ? "+" : "");
                os << "\n";
            }
        }
        os << "\n";
        return os;
    }
};

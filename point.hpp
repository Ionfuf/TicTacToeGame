#pragma once
#include <iostream>

struct Point {
    int row;
    int col;

    Point() : row(0), col(0) {}
    Point(int r, int c) : row(r), col(c) {}
    Point(const Point& other) : row(other.row), col(other.col) {}

    bool operator==(const Point& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.row << ", " << p.col << ")";
        return os;
    }
};

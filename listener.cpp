#include "listener.hpp"
#include <iostream>

Point Listener::GetMoveInput() {
    Point pos{-1, -1};
    std::cout << "Introdu randul si coloana (0-2, ex: 1 1): ";
    if (!(std::cin >> pos.row >> pos.col)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return pos;
}

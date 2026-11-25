#pragma once

#include "board.hpp"
#include "painter.hpp"
#include "listener.hpp"

class GameEngine {
    Board _board;
    Painter _painter;
    Listener _listener;
    Cell _currentPlayer;
public:
    GameEngine();
    void Init();
    void Run();
};
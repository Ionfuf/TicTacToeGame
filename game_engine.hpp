#pragma once

#include "board.hpp"
#include "painter.hpp"
#include "player.hpp"

class GameEngine {
    Board<3> _board;
    Painter _painter;
    Player* _players[2];
    int _currentIndex;

public:
    GameEngine();
    ~GameEngine();
    void Init();
    void Run();
};

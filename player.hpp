#pragma once

#include "board.hpp"
#include "listener.hpp"
#include <string>

class Player {
protected:
    Cell _symbol;
    std::string _name;
public:
    Player(Cell symbol, const std::string& name) : _symbol(symbol), _name(name) {}
    virtual ~Player() = default;

    Cell GetSymbol() const { return _symbol; }
    std::string GetName() const { return _name; }

    virtual Point GetMove(const Board& board) = 0;
};

class HumanPlayer : public Player {
    Listener _listener;
public:
    HumanPlayer(Cell symbol, const std::string& name) : Player(symbol, name) {}
    Point GetMove(const Board& board) override;
};

class BotPlayer : public Player {
public:
    BotPlayer(Cell symbol, const std::string& name = "Bot AI") : Player(symbol, name) {}
    Point GetMove(const Board& board) override;
};

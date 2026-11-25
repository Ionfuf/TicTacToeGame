#include "game_engine.hpp"
#include <iostream>
#include <string>

GameEngine::GameEngine() : _currentIndex(0) {
    _players[0] = nullptr;
    _players[1] = nullptr;
}

GameEngine::~GameEngine() {
    delete _players[0];
    delete _players[1];
}

void GameEngine::Init() {
    delete _players[0];
    delete _players[1];

    _board = Board();
    _currentIndex = 0;

    int mode = 1;
    std::cout << "Alege modul de joc:\n1. Om vs Calculator (Bot)\n2. Om vs Om\nOptiune: ";
    if (!(std::cin >> mode)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        mode = 1;
    }

    _players[0] = new HumanPlayer(Cell::X, "Jucator X");
    if (mode == 2) {
        _players[1] = new HumanPlayer(Cell::O, "Jucator O");
    } else {
        _players[1] = new BotPlayer(Cell::O, "Calculator (O)");
    }
}

void GameEngine::Run() {
    Init();
    while (true) {
        _painter.DrawBoard(_board);
        Player* current = _players[_currentIndex];

        std::string turnMsg = "Randul lui " + current->GetName() + ":";
        _painter.WriteText({0, 0}, turnMsg.c_str());

        Point move = current->GetMove(_board);
        if (!_board.MakeMove(move, current->GetSymbol())) {
            _painter.WriteText({0, 0}, "Mutare invalida! Incearca din nou.");
            continue;
        }

        Cell winner = _board.CheckWinner();
        if (winner != Cell::Empty) {
            _painter.DrawBoard(_board);
            std::string winMsg = current->GetName() + " a castigat!";
            _painter.WriteText({0, 0}, winMsg.c_str());
            break;
        }

        if (_board.IsFull()) {
            _painter.DrawBoard(_board);
            _painter.WriteText({0, 0}, "Egalitate (Remiza)!");
            break;
        }

        _currentIndex = 1 - _currentIndex;
    }
}

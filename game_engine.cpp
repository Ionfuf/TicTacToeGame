#include "game_engine.hpp"

GameEngine::GameEngine() : _currentPlayer(Cell::X) {}

void GameEngine::Init() {
    _board = Board();
    _currentPlayer = Cell::X;
}

void GameEngine::Run() {
    Init();
    while (true) {
        _painter.DrawBoard(_board);
        _painter.WriteText({0, 0}, _currentPlayer == Cell::X ? "Randul lui X:" : "Randul lui O:");

        Point move = _listener.GetMoveInput();
        if (!_board.MakeMove(move, _currentPlayer)) {
            _painter.WriteText({0, 0}, "Mutare invalida! Incearca din nou.");
            continue;
        }

        Cell winner = _board.CheckWinner();
        if (winner != Cell::Empty) {
            _painter.DrawBoard(_board);
            _painter.WriteText({0, 0}, winner == Cell::X ? "Jucatorul X a castigat!" : "Jucatorul O a castigat!");
            break;
        }

        if (_board.IsFull()) {
            _painter.DrawBoard(_board);
            _painter.WriteText({0, 0}, "Egalitate (Remiza)!");
            break;
        }

        _currentPlayer = (_currentPlayer == Cell::X) ? Cell::O : Cell::X;
    }
}

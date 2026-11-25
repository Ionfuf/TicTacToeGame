# Tic-Tac-Toe (X si O) - Proiect C++ OOP

Aplicatie consola modulara dezvoltata in C++17 pe parcursul a 6 lucrari de laborator.

## Structura Proiectului
- cell.hpp, point.hpp: Tipuri de date de baza si operatori supraincarcati (==, !=, <<).
- board.hpp: Clasa sablon Board<N> pentru tabla de joc, validarea mutarilor si istoricul partidei.
- player.hpp, player.cpp: Ierarhie polimorfica (Player, HumanPlayer, BotPlayer).
- painter.hpp, painter.cpp: Randarea tablei si a mesajelor in consola.
- listener.hpp, listener.cpp: Citirea si validarea intrarilor de la tastatura.
- game_exception.hpp: Ierarhie de exceptii (GameException, InvalidMoveException).
- score_manager.hpp, score_manager.cpp: Persistenta rezultatelor in fisier (scores.txt) si statistici STL.
- game_engine.hpp, game_engine.cpp: Logica principala a jocului gestionata cu std::unique_ptr.

## Compilare si Rulare (Windows / MinGW g++)
Ruleaza in terminal:
.\build.cmd
.\tictactoe.exe

## Evolutia pe Ramuri (Branches)
- lab01: Definirea structurii proiectului si a fisierelor header (.hpp).
- lab02: Implementarea claselor (.cpp), scriptul de compilare build.cmd si .gitignore.
- lab03: Constructori, supraincarcarea operatorilor si polimorfism (HumanPlayer vs BotPlayer).
- lab04: Exceptii personalizate, clasa template Board<N> si containere STL (std::vector).
- lab05: Salvarea scorurilor in fisiere (<fstream>) si algoritmi STL (std::count_if, std::accumulate).
- lab06: Gestionare moderna a memoriei cu std::unique_ptr si documentatie finala.

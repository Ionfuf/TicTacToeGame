@echo off
g++ -std=c++17 -Wall -Wextra -c board.cpp -o board.o
g++ -std=c++17 -Wall -Wextra -c painter.cpp -o painter.o
g++ -std=c++17 -Wall -Wextra -c listener.cpp -o listener.o
g++ -std=c++17 -Wall -Wextra -c player.cpp -o player.o
g++ -std=c++17 -Wall -Wextra -c game_engine.cpp -o game_engine.o
g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o
g++ board.o painter.o listener.o player.o game_engine.o main.o -o tictactoe.exe
echo Compilare finalizata! Ruleaza .\tictactoe.exe

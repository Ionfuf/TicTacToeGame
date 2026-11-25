# TicTacToeGame (X și O)

## Descrierea proiectului
Acest proiect reprezintă o implementare în limbajul C++ a jocului clasic **Tic-Tac-Toe (X și O)**, structurat modular pentru a separa datele jocului, motorul de execuție, afișarea și citirea comenzilor.

## Regulile jocului
1. Jocul se desfășoară pe o tablă pătrată de dimensiune **3x3** între doi jucători: **X** și **O**.
2. Jucătorii mută pe rând, alegând coordonatele (rând și coloană, de la 0 la 2) unei căsuțe libere.
3. Primul jucător care reușește să alinieze 3 simboluri identice pe orizontală, verticală sau diagonală câștigă partida.
4. Dacă toate cele 9 căsuțe sunt completate fără ca vreun jucător să facă linie, jocul se termină la egalitate (remiză).

## Structuri de date și clase
- `Point` (`point.hpp`) — structură care reține coordonatele (`row`, `col`) unei poziții de pe tablă.
- `Cell` (`cell.hpp`) — tip enumerare (`enum class`) care definește starea unei celule: `Empty`, `X` sau `O`.
- `Board` (`board.hpp`, `board.cpp`) — reprezintă tabla de joc 3x3, gestionează validarea mutărilor și verificarea câștigătorului.
- `Painter` (`painter.hpp`, `painter.cpp`) — componenta responsabilă de afișarea tablei de joc și a mesajelor către utilizator.
- `Listener` (`listener.hpp`, `listener.cpp`) — componenta care preia datele de intrare (mutările) de la jucător.
- `GameEngine` (`game_engine.hpp`, `game_engine.cpp`) — motorul principal care inițializează jocul, alternează turele jucătorilor și controlează bucla de joc.

## Construirea și rularea proiectului
Pentru a compila proiectul din linia de comandă pe Windows (folosind compilatorul `g++`), rulați scriptul `build.cmd`:

```cmd
.\build.cmd
.\tictactoe.exe
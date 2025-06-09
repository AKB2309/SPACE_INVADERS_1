#include "Game.h"
#include "ConsoleArea.h"
#include "visualization.h"
using namespace std;

int main() {

    ConsoleArea::LockConsoleSize(POLE_COLS, POLE_ROWS);

    Game game;
    game.run();

    while (true)
    {

    }
    return 0;
}


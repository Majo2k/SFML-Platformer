#include "Game.h"

int main(int argc, char* argv[])
{
    Game game(DEBUG);
    game.Run();
    return EXIT_SUCCESS;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Game game(RELEASE);
    game.Run();
    return EXIT_SUCCESS;
}

/*
---------------------------------------------
                  TO DO:
    1. Put InitResources to all_headers
    2. Delete IR class form Player class 
    3. Add jumpinng mechanics
    4. Fix Animation class (Update func)
    5. Fix character displaying 
    6. Fix warnings (?)
---------------------------------------------
*/
#include "Game.h"

int main(int argc, char* argv[])
{
    Game game(DEBUG);
    game.Run();
    return EXIT_SUCCESS;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE 
    hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
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
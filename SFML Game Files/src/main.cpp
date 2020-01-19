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
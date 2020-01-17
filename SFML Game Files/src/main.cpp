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
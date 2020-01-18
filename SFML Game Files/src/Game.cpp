#include "Game.h"

Game::Game(bool console) :event()
{
	window.create(VideoMode(800, 600), "test window", Style::Close | Style::Titlebar);
    get_time = std::clock();
    //timer.restart();
    srand((unsigned)time(NULL));

    res = new InitResources(console);
    player = new Player(*res); 

    this->console = console;
}

Game::~Game()
{
    delete player;
    delete res;
}

void Game::Run()
{
	while (window.isOpen())
	{
		Update();
		Render();
	}
}

void Game::Render()
{
    window.clear(Color(100, 100, 100, 0));

    // Rendering stuff here
        /*background*/
    player->Render(window, deltaTime);
        /*map*/

    window.display();
}

void Game::Update()
{
    //cout << "wait time: " << wait << endl;
    if (wait > 500 && console)
    {
        system("cls");
        UpdateConsole();
        wait = {};
    }
    UpdateEvents();
    UpdateTimers();
}

void Game::UpdateEvents()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            break;

        case Event::KeyPressed:
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            break;

        default:
            break;
        }
    }
}

void Game::UpdateConsole()
{
	cout << "Render time: " << deltaTime  << " seconds" << endl;
    cout << endl;
}

void Game::UpdateTimers()
{
    deltaTime = timer.restart().asSeconds();
    wait += (std::clock() - get_time);
    //get_time = 0;
    get_time = std::clock();
}


#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window;
	window.create(VideoMode(300, 300), "This is test window", Style::Default);

	while (window.isOpen())
	{
		window.clear(Color::White);
		window.display();
	}
	return 0;
}

int WinMain()
{
	RenderWindow window;
	window.create(VideoMode(300, 300), "This is test window", Style::Default);

	while (window.isOpen())
	{
		window.clear(Color::White);
		window.display();
	}
	return 0;
}

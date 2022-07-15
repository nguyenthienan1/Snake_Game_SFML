#pragma once
#include <SFML/Graphics.hpp>
#include "MainScreen.h"
#include "GameScreen.h"
#include "Menu.h"
class Game
{
public:
	static MainScreen *mainScr;
	static Menu *menuScr;
	static GameScreen *gameScr;
	sf::RenderWindow* window;
	Game();
	void Run();
	void Render();
};


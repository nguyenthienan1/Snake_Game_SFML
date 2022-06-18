#pragma once
#include "SFML/Graphics.hpp"
#include "MainScreen.h"
#include "GameScreen.h"
#include "Menu.h"
class Game
{
public:
	static MainScreen* mainScr;
	static GameScreen* gameScr;
	static Menu* menuScr;
	sf::RenderWindow* window;
	Game();
	void Run();
};


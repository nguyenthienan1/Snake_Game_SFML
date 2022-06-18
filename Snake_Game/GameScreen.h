#pragma once
#include "MainScreen.h"
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "Food.h"
#include "Zone.h"

class GameScreen : public MainScreen
{
private:
	int dir;
	float TimePlaying;
	float timemax;
	bool pause;
	Snake snake;
	Food food;
	Zone zone;
	sf::Font arialFont;
	sf::Clock clock;
public:
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	
	GameScreen();
	void drawScore(sf::RenderWindow& window);
	void drawTime(sf::RenderWindow& window);
	void drawPause(sf::RenderWindow& window);
};


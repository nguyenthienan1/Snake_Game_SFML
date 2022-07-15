#pragma once
#include "MainScreen.h"
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "Food.h"
#include "Zone.h"

class GameScreen : public MainScreen
{
private:
	float TimePlaying;
	float timemax;
	bool pause;
	int Score;
	Snake snake;
	Food food;
	Zone zone;
	sf::Font arialFont;
	sf::Clock clock;
	sf::Text textScore;
	sf::Text textTime;
	sf::Text textPause;
public:
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void reset();
	GameScreen();
};


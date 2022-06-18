#pragma once
#include "SFML/Graphics.hpp"
class MainScreen
{
public:
	MainScreen() {}
	virtual void update(sf::RenderWindow& window) {}
	virtual void draw(sf::RenderWindow& window) {}
};


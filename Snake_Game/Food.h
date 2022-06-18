#pragma once
#include "Zone.h"
#include <SFML/Graphics.hpp>
#include "StaticNumber.h"
class Food
{
public:
	int x, y; //tọa độ food
	sf::RectangleShape rectFood;
	Food();
	void Random(Zone zone); //random food
	void Draw(sf::RenderWindow& window); //draw food
};



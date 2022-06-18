#include "Food.h"
#include <chrono>
#include <iostream>
#include "Zone.h"
#include "StaticNumber.h"
#include <SFML/Graphics.hpp>

Food::Food()
{
	x = 0;
	y = 0;
	rectFood.setSize(sf::Vector2f(StaticNumber::size, StaticNumber::size));
	rectFood.setFillColor(sf::Color::Yellow);
}

void Food::Random(Zone zone) //Random food, chỉ ramdom trong zone
{
	x = rand() % zone.w + zone.position;
	y = rand() % zone.h + zone.position;
}

void Food::Draw(sf::RenderWindow& window)
{
	rectFood.setPosition(x * StaticNumber::size, y * StaticNumber::size); //Set vị trí khi draw food
	window.draw(rectFood);
}

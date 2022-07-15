#include "Zone.h"
#include "StaticNumber.h"
#include <SFML/Graphics.hpp>
Zone::Zone()
{
	w = 30;
	h = 20;
	position = 5;

	rectDefault.setSize(sf::Vector2f(w * StaticNumber::size, h * StaticNumber::size));
	rectDefault.setFillColor(sf::Color::Color(141, 160, 0, 255));
	rectDefault.setOutlineThickness(20);
	rectDefault.setOutlineColor(sf::Color::Cyan);
	rectDefault.setPosition(position * StaticNumber::size, position * StaticNumber::size);

	rectEasy.setSize(sf::Vector2f(w * StaticNumber::size, h * StaticNumber::size));
	rectEasy.setFillColor(sf::Color::Color(141, 160, 0, 255));
	rectEasy.setPosition(position * StaticNumber::size, position * StaticNumber::size);
}

void Zone::Draw(sf::RenderWindow& window)
{	
	window.draw(rectDefault);
}

void Zone::DrawModeEasy(sf::RenderWindow& window)
{
	window.draw(rectEasy);
}

void Zone::update()
{
	rectDefault.setSize(sf::Vector2f(w * StaticNumber::size, h * StaticNumber::size));
}

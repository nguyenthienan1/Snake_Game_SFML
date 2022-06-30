#pragma once
#include <SFML/Graphics.hpp>
struct NODE
{
	int x, y;
};
class Snake
{
public:
	NODE A[1000];
	int dir;
	int Length;
	sf::RectangleShape snakeBody;
	Snake();
	void Draw(sf::RenderWindow& window);
	void Move();
};




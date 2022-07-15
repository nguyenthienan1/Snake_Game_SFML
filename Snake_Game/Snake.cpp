#include "Snake.h"
#include "StaticNumber.h"
#include <SFML/Graphics.hpp>
using namespace sf;
// snake contruction
Snake::Snake()
{
	snakeBody.setSize(sf::Vector2f(StaticNumber::size, StaticNumber::size));
	snakeBody.setFillColor(sf::Color::Green);
	Length = 4;
	A[0].x = 11;
	A[0].y = 10;
	A[1].x = 10;
	A[1].y = 10;
	A[2].x = 9;
	A[2].y = 10;
	A[3].x = 8;
	A[3].y = 10;
	dir = 0;
}
//draw snake
void Snake::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Length; i++)
	{
		// remaining block is body
		snakeBody.setPosition(A[i].x * StaticNumber::size, A[i].y * StaticNumber::size);
		window.draw(snakeBody);
	}
}
// snake move in display
void Snake::Move()
{
	// snanke len
	for (int i = Length; i > 0; i--)
	{
		A[i] = A[i - 1];
	}
	switch (dir)
	{
	case 0:// move right
		A[0].x = A[0].x + 1;
		break;
	case 1:// move up
		A[0].y = A[0].y + 1;
		break;
	case 2:// move left
		A[0].x = A[0].x - 1;
		break;
	case 3://move down
		A[0].y = A[0].y - 1;
		break;
	}
}

void Snake::reset()
{
	Length = 4;
	A[0].x = 11;
	A[0].y = 10;
	A[1].x = 10;
	A[1].y = 10;
	A[2].x = 9;
	A[2].y = 10;
	A[3].x = 8;
	A[3].y = 10;
	dir = 0;
}
#include "GameScreen.h"
#include "Snake.h"
#include "Zone.h"
#include "Food.h"
#include "Game.h"

GameScreen::GameScreen()
{
	srand(time(0));
	TimePlaying = 0;
	timemax = 15;
	pause = false;
	food.Random(zone);
	arialFont.loadFromFile("font/arial.ttf");
}

void GameScreen::update(sf::RenderWindow& window)
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	if (!pause)
	{
		TimePlaying += time;
	}
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			window.close();
		if (e.type == sf::Event::KeyPressed)
		{
			switch (e.key.code)
			{
			case sf::Keyboard::Space:
				pause = !pause;
				break;
			case sf::Keyboard::A:
				if (snake.dir != 0)
					snake.dir = 2;
				break;
			case sf::Keyboard::D:
				if (snake.dir != 2)
					snake.dir = 0;
				break;
			case sf::Keyboard::W:
				if (snake.dir != 1)
					snake.dir = 3;
				break;
			case sf::Keyboard::S:
				if (snake.dir != 3)
					snake.dir = 1;
				break;
			}
		}
	}

	if (!pause)
	{
		snake.Move();

		for (int i = 0; i < snake.Length; i++)
		{
			if (snake.A[i].x == food.x && snake.A[i].y == food.y) // Nếu thân rắn chạm thức ăn
			{
				if (i == 0) // Chỉ đầu rắn chạm thức ăn mới được điểm
				{
					snake.Length++;
					StaticNumber::SCORE += 10;
				}
				food.Random(zone);
			}
		}

		if (StaticNumber::MODE == 3) //MODE Hard
		{
			if (TimePlaying >= timemax)
			{
				timemax += 15;
				zone.w -= 2;
				zone.h -= 2;
				if (food.x >= zone.w + zone.position || food.x < zone.position || food.y >= zone.h + zone.position || food.y < zone.position)
				{
					//food đang ở ngoài phạm vi zone thì mới random lại
					food.Random(zone);
				}
			}
		}
		for (int i = 1; i < snake.Length; i++)
		{
			if (snake.A[0].x == snake.A[i].x && snake.A[0].y == snake.A[i].y) // Nếu đầu rắn ăn thân
			{
				Game::mainScr = Game::menuScr;
			}
		}
		if (StaticNumber::MODE == 2 || StaticNumber::MODE == 3)
		{
			if (snake.A[0].x >= zone.w + zone.position || snake.A[0].x < zone.position || snake.A[0].y >= zone.h + zone.position || snake.A[0].y < zone.position)
			{
				Game::mainScr = Game::menuScr;
			}
		}
		else
		{
			if (snake.A[0].x >= zone.w + zone.position) snake.A[0].x = zone.position;
			if (snake.A[0].x < zone.position) snake.A[0].x = zone.w + (zone.position - 1);
			if (snake.A[0].y >= zone.h + zone.position) snake.A[0].y = zone.position;
			if (snake.A[0].y < zone.position) snake.A[0].y = zone.h + (zone.position - 1);
		}
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	//setting for game graphic
	if (StaticNumber::MODE == 1)
	{
		zone.DrawModeEasy(window);
	}
	else
	{
		zone.Draw(window);
	}

	snake.Draw(window);
	food.Draw(window);
	drawScore(window);
	drawTime(window);
	drawPause(window);
}

void GameScreen::drawScore(sf::RenderWindow& window)
{
	sf::Text text;
	text.setFont(arialFont);
	sf::String str = "Score: " + to_string(StaticNumber::SCORE);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(StaticNumber::size, StaticNumber::size);
	window.draw(text);
}

void GameScreen::drawTime(sf::RenderWindow& window)
{
	sf::Text text;
	text.setFont(arialFont);
	sf::String str = "Time: " + to_string((int)TimePlaying);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(10 * StaticNumber::size, StaticNumber::size);
	window.draw(text);
}

void GameScreen::drawPause(sf::RenderWindow& window)
{
	sf::Text text;
	text.setFont(arialFont);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(20 * StaticNumber::size, StaticNumber::size);
	if (!pause)
	{
		text.setString("Press space to pause game...");
	}
	else
	{
		text.setString("Press space to continue...");
	}
	window.draw(text);
}


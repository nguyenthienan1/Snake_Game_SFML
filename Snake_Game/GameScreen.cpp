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
	Score = 0;
	food.Random(zone);
	arialFont.loadFromFile("font/arial.ttf");

	textScore.setFont(arialFont);
	textScore.setCharacterSize(24);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(StaticNumber::size, StaticNumber::size);

	textTime.setFont(arialFont);
	textTime.setCharacterSize(24);
	textTime.setFillColor(sf::Color::White);
	textTime.setPosition(10 * StaticNumber::size, StaticNumber::size);

	textPause.setFont(arialFont);
	textPause.setCharacterSize(24);
	textPause.setFillColor(sf::Color::White);
	textPause.setPosition(20 * StaticNumber::size, StaticNumber::size);
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
		textPause.setString("Press space to pause game...");
		sf::String strScore = "Score: " + std::to_string(Score);
		textScore.setString(strScore);
		sf::String strTime = "Time: " + std::to_string((int)TimePlaying);
		textTime.setString(strTime);

		snake.Move();

		for (int i = 0; i < snake.Length; i++)
		{
			if (snake.A[i].x == food.x && snake.A[i].y == food.y) // Nếu thân rắn chạm thức ăn
			{
				if (i == 0) // Chỉ đầu rắn chạm thức ăn mới được điểm
				{
					snake.Length++;
					Score += 10;
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
				zone.update();
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
	else
	{
		textPause.setString("Press space to continue...");
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
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
	window.draw(textScore);
	window.draw(textTime);
	window.draw(textPause);
}

void GameScreen::reset()
{
	srand(time(0));
	TimePlaying = 0;
	timemax = 15;
	pause = false;
	Score = 0;
	food.Random(zone);
	snake.reset();
	zone.w = 30;
	zone.h = 20;
	zone.update();
}


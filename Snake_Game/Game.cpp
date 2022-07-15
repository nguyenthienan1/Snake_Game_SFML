#include "Game.h"

MainScreen *Game::mainScr = new MainScreen;
Menu *Game::menuScr = new Menu;
GameScreen *Game::gameScr = new GameScreen;

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(StaticNumber::wWindow, StaticNumber::hWindow), "Snake Game!", sf::Style::Close);
}

void Game::Run()
{
	window->setActive(false);
	window->setFramerateLimit(60);
	mainScr = menuScr;
	sf::Thread renderThread(&Game::Render, this);
	renderThread.launch();
	sf::Clock clock;
	while (window->isOpen())
	{
		mainScr->update(*window);
		long timedone = clock.getElapsedTime().asMilliseconds();
		if (timedone < 80)
		{
			sf::sleep(sf::milliseconds(80 - timedone));
		}
		else
		{
			sf::sleep(sf::milliseconds(1));
		}
		clock.restart();
	}
}

void Game::Render()
{
	while (window->isOpen())
	{
		window->clear();
		mainScr->draw(*window);
		window->display();
	}
}


#include "Game.h"
#include "SFML/Graphics.hpp"

MainScreen*  Game::mainScr = new MainScreen();
Menu* Game::menuScr = new Menu();
GameScreen* Game::gameScr = new GameScreen();

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(StaticNumber::wWindow, StaticNumber::hWindow), "Snake Game!", sf::Style::Close);
}

void Game::Run()
{
	mainScr = menuScr;
	window->setFramerateLimit(15);
	while (window->isOpen())
	{
		mainScr->update(*window);

		window->clear();
		mainScr->draw(*window);
		window->display();
	}
}
#include "Menu.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "GameScreen.h"
#include <iostream>

Menu::Menu()
{
	selectedItemIndex = -1;
	font.loadFromFile("font/arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString("Welcome to Snake Game");

	menu[0].setFont(font);
	menu[0].setString("Play");
	menu[0].setPosition(2 * StaticNumber::size, 7 * StaticNumber::size);

	menu[1].setFont(font);
	menu[1].setString("Exit");
	menu[1].setPosition(2 * StaticNumber::size, 10 * StaticNumber::size);
}

Menu::~Menu()
{
}

void Menu::update(sf::RenderWindow& window)
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		bool flag = true;
		switch (e.type)
		{
		case sf::Event::MouseMoved:
			for (int i = 0; i < MAX_ITEM_MENU; i++)
			{
				if (e.mouseMove.y <= menu[i].getPosition().y + 40 && e.mouseMove.y >= menu[i].getPosition().y && e.mouseMove.x <= menu[i].getPosition().x + 100 && e.mouseMove.x >= menu[i].getPosition().x)
				{
					selectedItemIndex = i;
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				selectedItemIndex = -1;
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				switch (GetPressedItem())
				{
				case 0:
					Game::gameScr = new GameScreen();
					Game::mainScr = Game::gameScr;
					break;
				case 1:
					window.close();
					break;
				}
			}
			break;
		case sf::Event::Closed:
			window.close();
			break;
		}
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(text);
	for (int i = 0; i < MAX_ITEM_MENU; i++)
	{
		if (i == selectedItemIndex)
		{
			menu[i].setFillColor(sf::Color::Green);
		}
		else
		{
			menu[i].setFillColor(sf::Color::White);
		}
		window.draw(menu[i]);
	}
}
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

	sf::Text text1;
	text1.setFont(font);
	text1.setString("Play");
	text1.setPosition(3 * StaticNumber::size, 8 * StaticNumber::size);

	sf::Text text2;
	text2.setFont(font);
	text2.setString("Exit");
	text2.setPosition(3 * StaticNumber::size, 13 * StaticNumber::size);

	listItemMenu.push_back(text1);
	listItemMenu.push_back(text2);
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
			for (int i = 0; i < listItemMenu.size(); i++)
			{
				if (e.mouseMove.y <= listItemMenu[i].getPosition().y + 40 && e.mouseMove.y >= listItemMenu[i].getPosition().y && e.mouseMove.x <= listItemMenu[i].getPosition().x + 100 && e.mouseMove.x >= listItemMenu[i].getPosition().x)
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
					Game::gameScr->reset();
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
	for (int i = 0; i < listItemMenu.size(); i++)
	{
		if (i == GetPressedItem())
		{
			listItemMenu[i].setFillColor(sf::Color::White);
			listItemMenu[i].setOutlineThickness(3);
			listItemMenu[i].setOutlineColor(sf::Color::Blue);
		}
		else
		{
			listItemMenu[i].setOutlineThickness(0);
			listItemMenu[i].setFillColor(sf::Color::White);
		}
		window.draw(listItemMenu[i]);
	}
}
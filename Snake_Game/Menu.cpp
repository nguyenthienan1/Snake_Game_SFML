#include "Menu.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "GameScreen.h"

Menu::Menu()
{
	MaxItemTextMenu = 0;
	selectedItemIndex = 0;
	font.loadFromFile("font/arial.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
}

Menu::~Menu()
{
}

//move up when press up key
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
// move down when press down key
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MaxItemTextMenu)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::update(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		// choose
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				MoveUp();
				break;

			case sf::Keyboard::S:
				MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (GetPressedItem())
				{

				case 0:
					Game::gameScr = new GameScreen();
					Game::mainScr = Game::gameScr;
					break;

				case 1:
					//exit;
					window.close();
					break;
				}
				break;
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
	text.setString("Welcome to Snake Game");
	window.draw(text);
	for (int i = 0; i < MaxItemTextMenu; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::setMenuStart(float width, float height)
{
	MaxItemTextMenu = 2;
	// create play butotn
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2.26, height / (MaxItemTextMenu + 1) * 1));

	//create exit button
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2.26, height / (MaxItemTextMenu + 1) * 2));
	// select index use for button choose
	selectedItemIndex = 0;
}
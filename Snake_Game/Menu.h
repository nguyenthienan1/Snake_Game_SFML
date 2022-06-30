#pragma once
#include "SFML/Graphics.hpp"
#include "MainScreen.h"

#define MAX_ITEM_MENU 2
class Menu : public MainScreen
{
public:
	Menu();
	~Menu();
	int GetPressedItem() { return selectedItemIndex; }
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	sf::Texture background;
	sf::Text text;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_ITEM_MENU];

};


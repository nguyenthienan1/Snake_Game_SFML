#pragma once
#include "SFML/Graphics.hpp"
#include "MainScreen.h"

class Menu : public MainScreen
{
public:
	Menu();
	~Menu();
	int MaxItemTextMenu;
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void setMenuStart(float width, float height);
	sf::Texture background;
	sf::Text text;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[10];

};


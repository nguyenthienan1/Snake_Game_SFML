#pragma once
#include "SFML/Graphics.hpp"
#include "MainScreen.h"
#include <vector>

class Menu : public MainScreen
{
public:
	Menu();
	~Menu();
	int GetPressedItem() { return selectedItemIndex; }
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text text;
	int selectedItemIndex;
	std::vector<sf::Text> listItemMenu;
};


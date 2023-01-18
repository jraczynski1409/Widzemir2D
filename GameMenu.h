#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"

class GameMenu {
	
public:
	Player player;
	sf::RectangleShape background;
	sf::RectangleShape backgroundItem;
	sf::RectangleShape itemBg;

	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;
	sf::RectangleShape expBar;
	sf::RectangleShape expBarBackground;
	sf::RectangleShape inventoryBar;

	GameMenu();
	GameMenu(Player player);

	void draw(sf::RenderWindow& window);
	void drawEq(sf::RenderWindow& window);
	void drawInventory(sf::RenderWindow& window);


};


#endif
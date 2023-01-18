#include "GameMenu.h"

#include <string>

GameMenu::GameMenu() {
}

GameMenu::GameMenu(Player player) {
	this->player = player;

}


void GameMenu::draw(sf::RenderWindow& window) {
	this->background.setSize(sf::Vector2f(300, window.getSize().y));
	this->background.setFillColor(sf::Color(182, 182, 182));
	this->background.setPosition(sf::Vector2f(window.getSize().x - 300, 0));

	window.draw(this->background);
	this->drawEq(window);
	this->drawInventory(window);
}

void GameMenu::drawEq(sf::RenderWindow& window) {
	sf::Text t;
	sf::Font f;
	f.loadFromFile("montseratb.ttf");
	t.setFont(f);
	t.setLetterSpacing(0);
	t.setFillColor(sf::Color::Black);
	t.setStyle(sf::Text::Bold);
	t.setCharacterSize(20);


	t.setString(this->player.getName());
	t.setPosition(window.getSize().x - 290, 10);
	window.draw(t);

	t.setString("Lvl: "+ std::to_string(this->player.getLevel()));
	t.setPosition(window.getSize().x - 100, 10);
	window.draw(t);

	
	itemBg.setFillColor(sf::Color(224, 224, 224));
	itemBg.setSize(sf::Vector2f(48, 48));


	itemBg.setPosition(window.getSize().x - 176, 62);
	window.draw(itemBg);

	itemBg.setPosition(window.getSize().x - 226, 112);
	window.draw(itemBg);

	itemBg.setPosition(window.getSize().x - 176, 112);
	window.draw(itemBg);

	itemBg.setPosition(window.getSize().x - 176, 162);
	window.draw(itemBg);

	itemBg.setPosition(window.getSize().x - 126, 112);
	window.draw(itemBg);
	if (this->player.getHelmet().isItemSet()) {
		this->player.getHelmet().draw(window, window.getSize().x - 176, 62);
	}
	if (this->player.getWeapon().isItemSet()) {
		this->player.getWeapon().draw(window, window.getSize().x - 226, 112);
	}

	if (this->player.getArmor().isItemSet()) {
		this->player.getArmor().draw(window, window.getSize().x - 176, 112);
	}
	if (this->player.getSecondaryWeapon().isItemSet()) {
		this->player.getSecondaryWeapon().draw(window, window.getSize().x - 126, 112);
	}
	if (this->player.getBoots().isItemSet()) {
		this->player.getBoots().draw(window, window.getSize().x - 176, 162);
	}

	this->healthBarBackground.setSize(sf::Vector2f(250, 15));
	this->healthBarBackground.setPosition(sf::Vector2f(window.getSize().x - 275, 225));
	this->healthBarBackground.setFillColor(sf::Color(64,64,64));

	float healthWidth = (float)player.getCurrentHealth() / (float)player.getMaxHealth();

	this->healthBar.setSize(sf::Vector2f(250* healthWidth, 15));
	this->healthBar.setPosition(sf::Vector2f(sf::Vector2f(window.getSize().x - 275, 225)));
	this->healthBar.setFillColor(sf::Color::Red);

	this->expBarBackground.setSize(sf::Vector2f(250, 15));
	this->expBarBackground.setPosition(sf::Vector2f(window.getSize().x - 275, 250));
	this->expBarBackground.setFillColor(sf::Color(64, 64, 64));

	float expWidth = (float)player.getCurrentExp() / (float)player.getMaxExp();
	this->expBar.setSize(sf::Vector2f(250*expWidth, 15));
	this->expBar.setPosition(sf::Vector2f(sf::Vector2f(window.getSize().x - 275, 250)));
	this->expBar.setFillColor(sf::Color::Yellow);

	window.draw(this->healthBarBackground);
	window.draw(this->healthBar);
	window.draw(this->expBarBackground);
	window.draw(this->expBar);



	sf::Text ts;
	ts.setFont(f);
	ts.setCharacterSize(15);
	ts.setStyle(sf::Text::Bold);
	ts.setFillColor(sf::Color(128, 0, 0));
	ts.setString("Strenght: " + std::to_string(this->player.getStrenght()));
	ts.setPosition(window.getSize().x - 290, 580);
	window.draw(ts);

	ts.setFillColor(sf::Color(0, 128,0));
	ts.setString("Agility: " + std::to_string(this->player.getAgility()));
	ts.setPosition(window.getSize().x - 290, 600);
	window.draw(ts);

	ts.setFillColor(sf::Color(0, 0, 128));
	ts.setString("Iq: " + std::to_string(this->player.getIq()));
	ts.setPosition(window.getSize().x - 290, 620);
	window.draw(ts);

	ts.setFillColor(sf::Color(109, 111, 32));
	ts.setString("Gold: " + std::to_string(this->player.getGold()));
	ts.setPosition(window.getSize().x - 290, 640);
	window.draw(ts);

	ts.setFillColor(sf::Color(0,0,0));
	ts.setString("Damage: " + std::to_string(this->player.getDamage()*0.8) + " - "+ std::to_string(this->player.getDamage() * 1.2));
	ts.setPosition(window.getSize().x - 290, 660);
	window.draw(ts);

	ts.setFillColor(sf::Color(0, 0, 0));
	ts.setString(std::to_string(this->player.getCurrentHealth()) + " / " + std::to_string(this->player.getMaxHealth()));
	ts.setPosition(window.getSize().x - 200, 224);
	window.draw(ts);

	ts.setFillColor(sf::Color(0, 0, 0));
	ts.setString(std::to_string(this->player.getCurrentExp()) + " / " + std::to_string(this->player.getMaxExp()));
	ts.setPosition(window.getSize().x - 200, 249);
	window.draw(ts);
}

void GameMenu::drawInventory(sf::RenderWindow& window)
{

	int widthInventory = 295;
	int heightInventory = 280;
	this->inventoryBar.setPosition(window.getSize().x - widthInventory, 280 + this->player.inventoryRow * 49);
	this->inventoryBar.setSize(sf::Vector2f(292, 48));
	this->inventoryBar.setOutlineThickness(5);
	this->inventoryBar.setOutlineColor(sf::Color(148,0,0));
	this->inventoryBar.setFillColor(sf::Color(0,0,0,0));

	for (int i = 0; i < 36; i++) {
		if (widthInventory < 48) {
			widthInventory = 295;
			heightInventory += 49;
		}
		backgroundItem.setFillColor(sf::Color(224, 224, 224));
		backgroundItem.setSize(sf::Vector2f(46, 46));
		backgroundItem.setPosition(window.getSize().x - widthInventory+1, heightInventory+1);
		window.draw(backgroundItem);
		if (i < this->player.inventory.size()) {
			this->player.inventory[i].draw(window, window.getSize().x - widthInventory, heightInventory);
		}
		widthInventory -= 49;
	}
	window.draw(this->inventoryBar);
}



#include "Item.h"

void Item::printDescription() {
	std::cout << "id: " << this->id << std::endl;
	std::cout << "name: " << this->name << std::endl;
	std::cout << "strenght: " << this->strength << std::endl;
	std::cout << "agility: " << this->agility << std::endl;
	std::cout << "iq: " << this->iq << std::endl;
	std::cout << "speed: " << this->speed << std::endl;
	std::cout << "health: " << this->health << std::endl << std::endl;
	std::cout << "price: " << this->price << std::endl;
}

Item::Item() {
	this->id = NULL;
	this->type = NULL;
	this->name = "";
	this->strength = NULL;
	this->agility = NULL;
	this->iq = NULL;
	this->speed = NULL;
	this->health = NULL;
	this->image = "";
	this->price = NULL;
}

Item::Item(int id, int type, std::string name, float strength, float agility, float iq, float speed, float health, std::string image, int price) {
	this->id = id;
	this->type = type;
	this->name = name;
	this->strength = strength;
	this->agility = agility;
	this->iq = iq;
	this->speed = speed;
	this->health = health;
	this->image = image;
	this->price = price;
}

void Item::draw(sf::RenderWindow& window, int x, int y) {
	sf::Texture texture;
	texture.loadFromFile(this->image);
	sf::Sprite sprite(texture);
	sprite.setPosition(x, y);
	window.draw(sprite);
}

int Item::isItemSet()
{
	if (this->id == NULL) {
		return 0;
	}
	else
	{
		return 1;
	}
}


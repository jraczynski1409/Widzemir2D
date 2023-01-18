#include "Npc.h"


Npc::Npc() {
	
}

Npc::Npc(std::string name,int type, int level, float x, float y, std::string image) {
	this->name = name;
	this->type = type;
	this->level = level;
	this->x = x*48;
	this->y = y*48;
	this->image = image;
	this->damage = this->level*3;
	this->hp = this->level*10;
}

float Npc::getX() {
	return this->x / 48;
}

float Npc::getY() {
	return this->y / 48;
}

void Npc::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile(this->image);
	sf::IntRect rectSorceSprite(0,0,46,56);
	sf::Sprite sprite(texture, rectSorceSprite);
	sprite.setPosition(this->x+1, this->y-20);
	f.loadFromFile("montseratb.ttf");
	if(this->type==1){
		bg.setFillColor(sf::Color(187, 236, 138));
		bg.setOutlineColor(sf::Color(68, 103, 33));
		t.setFillColor(sf::Color(48, 59, 38));
	}
	else {
		bg.setFillColor(sf::Color(201, 108, 100));
		bg.setOutlineColor(sf::Color(61, 17, 14));
		t.setFillColor(sf::Color(61, 17, 14));
	}
	bg.setSize(sf::Vector2f(64,30));
	bg.setPosition(this->x-6, this->y - 60);
	bg.setOutlineThickness(2);
	t.setFont(f);
	t.setLetterSpacing(-0.2);
	t.setCharacterSize(14);
	t.setStyle(sf::Text::Bold);
	t.setPosition(this->x-4, this->y - 60);
	t.setString(this->name);
	window.draw(sprite);
	window.draw(bg);
	window.draw(t);
	t.setPosition(this->x-4, this->y - 45);
	t.setString(std::to_string(this->level));
	window.draw(t);
}

int Npc::getHp() {
	return this->hp;
}
int Npc::getLevel()
{
	return this->level;
}
int Npc::getDamage() {
	return this->damage;
}

std::string Npc::getImage() {
	return this->image;
}


std::string Npc::getName() {
	return this->name;
}

#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h> 

class Item {
public:
	int id;
	int type;
	std::string name;
	float strength;
	float agility;
	float iq;
	float speed;
	float health;
	int price;

	std::string image;
	Item();
	Item(int id,int type, std::string name, float strength, float agility, float iq, float speed, float health, std::string image, int price);

	void printDescription();

	void draw(sf::RenderWindow& window,int x, int y);

	int isItemSet();



};

#endif
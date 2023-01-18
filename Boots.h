#ifndef BOOTS_H
#define BOOTS_H

#include"Item.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h> 

class Boots : public Item {
public:

	Boots();
	Boots(int id, int type, std::string name, float strength, float agility, float iq, float speed, float health, std::string image, int price);
};

#endif
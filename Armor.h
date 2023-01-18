#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"



class Armor : public Item {
public:

	Armor();
	Armor(int id,int type, std::string name, float strength, float agility, float iq, float speed, float health, std::string image, int price);
};

#endif
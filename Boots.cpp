#include "Boots.h"


Boots::Boots() {

}

Boots::Boots(int id, int type, std::string name, float strength, float agility, float iq, float speed, float health, std::string image, int price) :Item(id,type, name, strength, agility, iq, speed, health, image, price) {

}


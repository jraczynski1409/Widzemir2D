
#ifndef NPC_H
#define NPC_H

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class Npc
{

	sf::Font f;
	sf::RectangleShape bg;
	sf::Text t;

	std::string name;
	int level;
	float x;
	float y;
	std::string image;
	int type;

	int hp;
	int damage;


public:
	Npc();
	Npc(std::string name,int type, int level, float x, float y, std::string image);

	float getX();
	float getY();

	int getHp();
	int getLevel();
	int getDamage();
	std::string getName();

	std::string getImage();



	void draw(sf::RenderWindow& window);
};



#endif
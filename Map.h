#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



#define MAX_WIDTH 64
#define MAX_HEIGHT 50
#define BLOCK_SIZE 48

class Map
{
public:
	int matrix[MAX_WIDTH][MAX_HEIGHT];
	int collision[MAX_WIDTH][MAX_HEIGHT];

	sf::Texture Dirt;
	sf::Texture Grass;
	sf::Texture Stone;
	sf::Texture Coal;
	sf::Texture Mud;
	sf::Texture Sand;
	sf::Texture Snow;
	sf::Texture Water;
	sf::Texture Chimney;
	sf::Texture Doors;
	sf::Texture Roof;
	sf::Texture WindowT;
	sf::Texture WoodenWall;

	sf::Sprite DirtSprite;
	sf::Sprite GrassSprite;
	sf::Sprite StoneSprite;
	sf::Sprite CoalSprite;
	sf::Sprite MudSprite;
	sf::Sprite SandSprite;
	sf::Sprite SnowSprite;
	sf::Sprite WaterSprite;
	sf::Sprite ChimneySprite;
	sf::Sprite DoorsSprite;
	sf::Sprite RoofSprite;
	sf::Sprite WindowSprite;
	sf::Sprite WoodenWallSprite;

	Map();
	Map(const std::string& fileName, int w, int h);
	void mapDraw(sf::RenderWindow& window);

	int whereAmI(int x, int y, int direction);
	void setCollision(int x, int y);

	int isClear(int x, int y);
	
};

#endif


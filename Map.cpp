#include "Map.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <cstdlib>

Map::Map() {
}
Map::Map(const std::string& fileName,int w, int h) {
	this->Dirt.loadFromFile("img/Dirt.png");
	this->Grass.loadFromFile("img/Grass.png");
	this->Stone.loadFromFile("img/Stone.png");
	this->Coal.loadFromFile("img/Coal.png");
	this->Mud.loadFromFile("img/Mud.png");
	this->Sand.loadFromFile("img/Sand.png");
	this->Snow.loadFromFile("img/Snow.png");
	this->Water.loadFromFile("img/Water.png");
	this->Chimney.loadFromFile("img/Chimney.png");
	this->Roof.loadFromFile("img/Roof.png");
	this->Doors.loadFromFile("img/Doors.png");
	this->WindowT.loadFromFile("img/Window.png");
	this->WoodenWall.loadFromFile("img/WoodenWall.png");

	std::ifstream file(fileName);
	if (file.is_open()) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				file >> matrix[j][i];
				if (matrix[j][i] % 2 == 0) {
					collision[j][i] = 2;
				}
				else {
					collision[j][i] = 1;
				}
			}
		}
		file.close();
	}
}


void Map::mapDraw(sf::RenderWindow& window) {
	this->DirtSprite.setTexture(Dirt);
	this->GrassSprite.setTexture(Grass);
	this->StoneSprite.setTexture(Stone);
	this->CoalSprite.setTexture(Coal);
	this->MudSprite.setTexture(Mud);
	this->SandSprite.setTexture(Sand);
	this->SnowSprite.setTexture(Snow);
	this->WaterSprite.setTexture(Water);
	this->ChimneySprite.setTexture(Chimney);
	this->DoorsSprite.setTexture(Doors);
	this->RoofSprite.setTexture(Roof);
	this->WindowSprite.setTexture(WindowT);
	this->WoodenWallSprite.setTexture(WoodenWall);
	

	for (int i = 0; i < (MAX_HEIGHT * BLOCK_SIZE); i = i + BLOCK_SIZE) {

		for (int j = 0; j < (MAX_WIDTH * BLOCK_SIZE); j = j + BLOCK_SIZE) {
			switch(this->matrix[j/ BLOCK_SIZE][i/ BLOCK_SIZE]) {
			case 1:
				GrassSprite.setPosition(j, i);
			
				window.draw(GrassSprite);
				break;
			
			case 2: 
				MudSprite.setPosition(j, i);
				window.draw(MudSprite);
				break;
			
			case 4: 
				StoneSprite.setPosition(j, i);
				window.draw(StoneSprite);
				break;
			case 3:
				DirtSprite.setPosition(j, i);
				window.draw(DirtSprite);
				break;
			case 6:
				CoalSprite.setPosition(j, i);
				window.draw(CoalSprite);
				break;
			case 5:
				SandSprite.setPosition(j, i);
				window.draw(SandSprite);
				break;
			case 7:
				SnowSprite.setPosition(j, i);
				window.draw(SnowSprite);
				break;
			case 8:
				WaterSprite.setPosition(j, i);
				window.draw(WaterSprite);
				break;
			case 50:
				WoodenWallSprite.setPosition(j, i);
				window.draw(WoodenWallSprite);
				break;
			case 52:
				DoorsSprite.setPosition(j, i);
				window.draw(DoorsSprite);
				break;
			case 54:
				RoofSprite.setPosition(j, i);
				window.draw(RoofSprite);
				break;
			case 56:
				WindowSprite.setPosition(j, i);
				window.draw(WindowSprite);
				break;
			case 58:
				ChimneySprite.setPosition(j, i);
				window.draw(ChimneySprite);
				break;

			}
			

		}
	}
}

int Map::whereAmI(int x, int y, int direction ) {
	if (direction == 1) {
		return this->collision[x][y - 1];
	}
	else if (direction == 2) {

		return this->collision[x-1][y];
	}
	else if (direction == 3) {

		return this->collision[x][y + 1];
	}
	else if (direction == 4) {

		return this->collision[x+1][y];
	}
	else
	{
		return 1;
	}
}

void Map::setCollision(int x, int y) {

	this->collision[x][y] = 2;

}

int Map::isClear(int x, int y) {
	if (this->collision[x][y] == 2) {
		return 0;
	}
	else {
		return 1;
	}
}
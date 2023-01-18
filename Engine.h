#ifndef ENGINE_H
#define ENGINE_H

//biblioteki c++
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h> 
#include <ctime>

//biblioteki SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Map.h"
#include "Item.h"
#include "Helmet.h"
#include "Weapon.h"
#include "SecondaryWeapon.h"
#include "Boots.h"
#include "Armor.h"
#include "GameMenu.h"
#include "Npc.h"

using namespace sf;

class Engine
{
private:
	Event sfEvent;

	void initWindow();
	
public:
	RenderWindow* window;
	View camera;
	View menu;


	std::vector<Item> itemList;
	std::vector<Npc> npcList;
	

	Clock rClock;
	Clock dClock;
	Clock mClock;
	Clock bClock;
	float rTime;
	float mTime;
	float dTime;
	float bTime;

	bool isFight;

	int wave;
	Map map;
	Player player;
	GameMenu sideMenu;



	Engine();
	virtual ~Engine();

	void initNpc();
	void initVariables();
	void updateVariables();
	void initItems();
	void update();
	void updateTime();
	void updateGraphic();
	
	void run();
		
};

#endif
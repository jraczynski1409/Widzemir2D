#include "Engine.h"

void Engine::initWindow() {
	std::ifstream windowInit("config/initWindow.ini");

	std::string title = "3ID13B";
	float windowHeight = 400;
	float windowWidth = 500;
	int FPS = 120;
	bool VerticalSyncFlag = false;

	if (windowInit.is_open()) {
		std::getline(windowInit, title);
		windowInit >> windowWidth;
		windowInit >> windowHeight;
		windowInit >> FPS;
		windowInit >> VerticalSyncFlag;
	}

	this->window = new RenderWindow(VideoMode(windowWidth,windowHeight), title);
	this->window->setFramerateLimit(FPS);
	this->window->setVerticalSyncEnabled(VerticalSyncFlag);
	
	windowInit.close();

}

Engine::Engine() {
	srand(time(NULL));
	this->initWindow();
}

Engine::~Engine() {
	delete this->window;
}

void Engine::update(){

	this->updateTime();
	this->updateVariables();

	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == Event::Closed)
		{
			this->window->close();
		}
	}

	if (this->mTime > player.movementSpeed) {
		if (Keyboard::isKeyPressed(Keyboard::W) && this->map.whereAmI(ceil(this->player.getX() / 48), ceil(this->player.getY() / 48), 1) % 2 != 0) {
			this->camera.move(0, -6);
			
			this->player.translate(0, -6);
			this->player.moveSprite(3);
			mClock.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::S) && this->map.whereAmI(floor(this->player.getX() / 48), floor(this->player.getY() / 48), 3) % 2 != 0) {
			this->camera.move(0, 6);
			this->player.translate(0, 6);
			this->player.moveSprite(4);
			mClock.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::A) && this->map.whereAmI(ceil(this->player.getX() / 48), ceil(this->player.getY() / 48), 2) % 2 != 0) {
			this->camera.move(-6, 0);
			this->player.translate(-6, 0);
			this->player.moveSprite(2);
			mClock.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::D) && this->map.whereAmI(floor(this->player.getX() / 48), floor(this->player.getY() / 48), 4) % 2 != 0) {
			this->camera.move(6, 0);

			this->player.translate(6, 0);
			this->player.moveSprite(1);
			mClock.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::F)) {
			int FightRes = -1;
			if ((FightRes = this->player.vsNpc(npcList, itemList[rand() % itemList.size()])) > -1) {
				this->npcList.erase(this->npcList.begin() + FightRes);
			}
		}


	}
			if (this->bTime > 0.2f) {
				

				if (Keyboard::isKeyPressed(Keyboard::Up) ) {
					this->player.setInventoryRow(-1);
				}
				if (Keyboard::isKeyPressed(Keyboard::Down)) {
					this->player.setInventoryRow(1);
				}

				if (Keyboard::isKeyPressed(Keyboard::Num1) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 1);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 2);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num4) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 3);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num5) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 4);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num6) && Keyboard::isKeyPressed(Keyboard::LShift)) {
					this->player.equip(this->player.getInventoryRow() * 6 + 5);
				}

				if (Keyboard::isKeyPressed(Keyboard::Num1)&& Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 0);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num2) && Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 1);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num3) && Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 2);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num4) && Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 3);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num5) && Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 4);
				}
				if (Keyboard::isKeyPressed(Keyboard::Num6) && Keyboard::isKeyPressed(Keyboard::RShift)) {
					this->player.sell(this->player.getInventoryRow() * 6 + 5);
				}

				if (Keyboard::isKeyPressed(Keyboard::I)) {
					this->player.unEquip(0);
				}

				if (Keyboard::isKeyPressed(Keyboard::J)) {
					this->player.unEquip(1);
				}
				if (Keyboard::isKeyPressed(Keyboard::K)) {
					this->player.unEquip(2);
				}

				if (Keyboard::isKeyPressed(Keyboard::L)) {
					this->player.unEquip(3);
				}
				if (Keyboard::isKeyPressed(Keyboard::M)) {
					this->player.unEquip(4);
				}


				bClock.restart();
			}
		
	
}

void Engine::initVariables() {
	this->map = Map("maps/newAbraham.txt", 64, 32);
	this->camera = View();
	this->menu = View();
	this->player = Player();

	this->isFight = true;

	this->player.setSpriteTop(0);

	this->camera.setCenter(this->player.getX(), this->player.getY());
	this->camera.setSize(this->window->getSize().x, this->window->getSize().y);
	this->camera.setViewport(sf::FloatRect(0.0f, 0.f, 1.0f, 1.f));

	this->wave = 5;
}

void Engine::updateVariables() {
	this->menu.setCenter(this->window->getSize().x - 150, this->window->getSize().y / 2);
	this->menu.setSize(300, this->window->getSize().y);
	this->menu.setViewport(sf::FloatRect(0.80f, 0.f, 0.20f, 1.f));

	this->sideMenu = GameMenu(this->player);

	if (this->player.getLevel() >= this->wave) {
		this->initNpc();
			this->wave += 5;
	}

}

void Engine::initNpc() {
	
	int x = 1;
	int y = 1;
	for (int i = 0; i < 10; i++) {
		x = rand() % 62+1;
		y = rand() % 30+1;
		if (this->map.isClear(y, x) == 1) {
			this->npcList.push_back(Npc("Bad man", 2, this->player.getLevel() + rand() % 10+1, x, y, "./img/npc/Bad.png"));
		}
		else
		{
			i--;
		}
		
	}
	
}





void Engine::initItems() {
	this->itemList.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 500, "./items/images/31.png", 50));
	this->itemList.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 1500, "./items/images/32.png", 50));
	this->itemList.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 3000, "./items/images/33.png", 50));
	this->itemList.push_back(Weapon(1, 2, "Blood sword", 40, 30, 20, 55, 0, "./items/images/1.png", 5000));
	this->itemList.push_back(SecondaryWeapon(2, 4, "Jack Sprarrow Gun", 25, 40, 35, 40, 50, "./items/images/3.png", 4800));
	this->itemList.push_back(Boots(3, 5, "Socks and Sandals", 15, 30, 10, 0, 150, "./items/images/5.png", 3600));
	this->itemList.push_back(Helmet(4, 1, "Cowboy Hat", 25, 25, 30, 0, 80, "./items/images/2.png", 3600));
	this->itemList.push_back(Armor(5, 3, "Ortalion", 40, 50, -100, 50, 250, "./items/images/4.png", 8000));

	this->itemList.push_back(Weapon(6, 2, "6", 25, 25, 20, 40, 0, "./items/images/6.png", 3000));
	this->itemList.push_back(Helmet(7, 1, "7", 40, 25, -30, 0, 50, "./items/images/7.png", 2500));
	this->itemList.push_back(SecondaryWeapon(8, 4, "8", 0, 0, 40, 10, 0, "./items/images/8.png", 2000));
	this->itemList.push_back(Armor(9, 3, "9", 30, 15, 10, 0, 350, "./items/images/9.png", 3000));
	this->itemList.push_back(Boots(10, 5, "10", 5, 30, 20, 0, 100, "./items/images/10.png", 1999));

	this->itemList.push_back(Weapon(11, 2, "11", 40, 0, -50, 35, 0, "./items/images/11.png", 1500));
	this->itemList.push_back(Helmet(12, 1, "12", 50, 15, 0, 0, 150, "./items/images/12.png", 1200));
	this->itemList.push_back(SecondaryWeapon(13, 4, "13", 5, 25, 45, 15, 0, "./items/images/13.png", 1000));
	this->itemList.push_back(Armor(14, 3, "14", 30, 0, -5, 0, 0, "./items/images/14.png", 1500));
	this->itemList.push_back(Boots(15, 5, "15", 10, 50, 10, 0, 200, "./items/images/15.png", 1300));

	this->itemList.push_back(Weapon(16, 2, "16", 20, 15, 5, 20, 0, "./items/images/16.png", 500));
	this->itemList.push_back(Helmet(17, 1, "17", 15, 10,0, 0, 150, "./items/images/17.png", 200));
	this->itemList.push_back(SecondaryWeapon(18, 4, "18", 10, 5, 0, 10, 0, "./items/images/18.png", 100));
	this->itemList.push_back(Armor(19, 3, "19", 30, 0, 0, 0, 100, "./items/images/19.png", 150));
	this->itemList.push_back(Boots(20, 5, "20", 5, 10, 5, 0, 100, "./items/images/20.png", 130));

	this->itemList.push_back(Weapon(21, 2, "21", 10, 10, 10, 15, 0, "./items/images/21.png", 400));
	this->itemList.push_back(Helmet(22, 1, "22", 5, 10, 40, 0, 0, "./items/images/22.png", 300));
	this->itemList.push_back(SecondaryWeapon(23, 4, "23", 5, 5, 5, 5, 20, "./items/images/23.png", 200));
	this->itemList.push_back(Armor(24, 3, "24", 5, 20, 5, 0, 50, "./items/images/24.png", 50));
	this->itemList.push_back(Boots(25, 5, "25", 5, 10, 10, 0, 50, "./items/images/25.png", 80));

	this->itemList.push_back(Weapon(26, 2, "26", 0, 10, 15, 20, 0, "./items/images/26.png", 300));
	this->itemList.push_back(Helmet(27, 1, "27", 0, 10, 20, 0, -100, "./items/images/27.png", 500));
	this->itemList.push_back(SecondaryWeapon(28, 4, "28", 10, 5, 5, 15, 0, "./items/images/28.png", 250));
	this->itemList.push_back(Armor(29, 3, "29", 15, -10, 15, 0, 0, "./items/images/29.png", 30));
	this->itemList.push_back(Boots(30, 5, "30", 15, 0, 10, 0, 50, "./items/images/30.png", 80));

}

void Engine::updateTime() {
	this->mTime = mClock.getElapsedTime().asSeconds();
	this->bTime = bClock.getElapsedTime().asSeconds();
}

void Engine::updateGraphic() {
	this->window->clear(sf::Color(10,0,10));

	this->window->setView(this->camera);
	map.mapDraw(*this->window);
	for (int i = 0; i < npcList.size(); i++) {
		this->npcList[i].draw(*this->window);
	}
	this->player.draw(*this->window);

	this->window->setView(this->menu);
	this->sideMenu.draw(*this->window);

	this->window->display();
}

void Engine::run() {
	this->initNpc();
	this->initVariables();
	this->initItems();
	this->player.LevelUp();
	while (this->window->isOpen()) {
		this->update();
	
		this->updateGraphic();
	}
}
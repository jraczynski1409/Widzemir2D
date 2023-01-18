#ifndef GRA_H
#define GRA_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Gra
{
private:
	sf::RenderWindow *window;
	sf::Event sfEvent;

	float deltaTime;
	sf::Clock DTclock;

	void initWindow();
	void updateDT();
public:
	Gra();
	virtual ~Gra();

	void updateEvents();
	void update();
	void render();
	void run();

};

#endif
#include "Gra.h"
#include "Engine.h"

/*
void Gra::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Under The Stone");
}


Gra::Gra()
{
	this->initWindow();
}

Gra::~Gra()
{
	delete this->window;

}

void Gra::updateDT()
{
	this->deltaTime = this->DTclock.restart().asSeconds();
}

void Gra::updateEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Gra::update()
{
	this->updateDT();
	this->updateEvents();
}

void Gra::render()
{
	this->window->clear();

	this->window->display();
}

void Gra::run()
{
	while (this->window->isOpen())
	{
		
		this->update();
		this->render();
	}
}*/
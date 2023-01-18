#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Player::Player() {
    this->name = "Wiedzimir";
	this->x = 48*10;
	this->y = 48*10;

	this->spriteLeft = 0;
	this->spriteTop = 46;
	this->spriteWidth=46;
	this->spriteHeight=59;
    this->leftFrame = 0;

    this->movementSpeed = 0.02;
    this->level = 0;

    this->strength = 12;
    this->agility = 15;
    this->iq = 5;
    this->gold = 100;

    this->damage = 0;
    this->maxHealth = 0;
    this->currentHealth = maxHealth;
    this->currentExp = 1;
    this->maxExp = 0 ;

    this->inventoryRow = 0;

    helmet = Helmet();
    weapon = Weapon();
    armor = Armor();
    secondaryWeapon = SecondaryWeapon();
    boots = Boots();

    this->inventory.push_back(Weapon(26, 2, "26", 0, 10, 15, 20, 0, "./items/images/26.png", 300));
    this->inventory.push_back(Armor(29, 3, "29", 15, -10, 15, 0, 0, "./items/images/29.png", 30));
    this->inventory.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 500, "./items/images/31.png", 50));
    this->inventory.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 1500, "./items/images/32.png", 50));
    this->inventory.push_back(Item(0, 0, "Mix", 0, 0, 0, 0, 3000, "./items/images/33.png", 50));

}

void Player::draw(sf::RenderWindow& window)
{
	
	this->texture.loadFromFile("img/Player.png");
	sf::IntRect rectSorceSprite(this->spriteLeft, this->spriteTop, this->spriteWidth, this->spriteHeight);
	sf::Sprite sprite(this->texture, rectSorceSprite);

	sprite.setPosition(this->x+1, this->y-20);
	window.draw(sprite);
}

void Player::translate(float tx, float ty) {
	this->x = this->x + tx;
	this->y = this->y + ty;
}

void Player::moveSprite(int direction) {
    this->spriteTop = 120;
    this->spriteLeft = leftFrame;
    if (direction == 1) {  // Move right
        this->spriteTop = 60;
        if (leftFrame >= 138) {
            leftFrame = 0;
        }
        else {
            leftFrame = leftFrame + 46;
        }
    }
    else if (direction == 2) {  // Move left
        this->spriteTop = 120;
        if (leftFrame <= 0) {
            leftFrame = 138;
        }
        else {
            leftFrame = leftFrame - 46;
        }
    }
    else if (direction == 3) {  // Move up
        this->spriteTop = 181;
        if (leftFrame <= 0) {
            leftFrame = 138;
        }
        else {
            leftFrame = leftFrame - 46;
        }
    }
    else if (direction == 4) {  // Move down
        this->spriteTop = 0;
        if (leftFrame <= 0) {
            leftFrame = 138;
        }
        else {
            leftFrame = leftFrame - 46;
        }
    }
}

void Player::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void Player::setSpriteTop(int i)
{
    this->spriteTop = i;
}

void Player::setName(std::string name)
{
    this->name = name;
}

void Player::LevelUp()
{
    if (currentExp >= maxExp) {
        
        this->level += 1;
        this->strength += level ;
        this->agility += level ;
        this->iq += level ;
        this->damage += 5;
        this->maxHealth += 69;
        this->currentHealth = maxHealth;
        this->currentExp = currentExp - maxExp;
        this->maxExp = level * 126;
        if (currentExp >= maxExp) {
            LevelUp();
        }

    }
}



void Player::addExp(int exp) {
    this->currentExp += exp;
    if (currentExp >= maxExp) {
        this->LevelUp();
    }
}

void Player::setItem(Helmet item) {
    this->helmet = item;
}

void Player::setItem(Weapon item) {
    this->weapon = item;
}

void Player::setItem(SecondaryWeapon item) {
    this->secondaryWeapon = item;
}

void Player::setItem(Boots item) {
    this->boots = item;
}

void Player::setInventoryRow(int i)
{
    if (this->inventoryRow >= 5 && i > 0) {
        this->inventoryRow = 0;
    }
    else if (this->inventoryRow <= 0 && i<0) {
        this->inventoryRow = 5;
    }
    else {
        this->inventoryRow += i;
    }

}


void Player::setItem(Armor item) {
    this->armor = item;
}

float Player::getX() {
    return this->x;
}

float Player::getY() {
    return this->y;
}

std::string Player::getName()
{
    return this->name;
}

int Player::getLevel()
{
    return this->level;
}

int Player::getStrenght() {
    return this->strength;
}

int Player::getAgility() {
    return this->agility;
}

int Player::getIq() {
    return this->iq;
}

int Player::getDamage() {
    return this->damage;
}

int Player::getGold()
{
    return this->gold;
}

int Player::getCurrentHealth()
{
    return this->currentHealth;
}

int Player::getMaxHealth()
{
    return this->maxHealth;
}

int Player::getCurrentExp()
{
    return this->currentExp;
}

int Player::getMaxExp()
{
    return this->maxExp;
}

void Player::setFightDamage(int damage)
{
    this->currentHealth -= damage;
}

int Player::getInventoryRow()
{
    return this->inventoryRow;
}

Helmet Player::getHelmet() {
    return this->helmet;
}

Armor Player::getArmor() {
    return this->armor;
}


Weapon Player::getWeapon() {
    return this->weapon;
}
SecondaryWeapon Player::getSecondaryWeapon() {
    return this->secondaryWeapon;
}
Boots Player::getBoots() {
    return this->boots;
}

void Player::addToInventory(Item item)
{
    if (this->inventory.size() < 37) {
        this->inventory.push_back(item);
    }
    else
    {
        std::cout << "Nie mozesz wiecej dzwigac" << std::endl;
    }
}

void Player::addStats(int strength, int agility, int iq, int health)
{
    this->strength += strength;
    this->agility += agility;
    this->iq += iq;
    this->damage = (this->strength + this->agility  + this->iq * 0.5 + 5) * 0.2;

    this->maxHealth += health ;
}

void Player::equip(int i) {
    if (i >= this->inventory.size()) {
        std::cout << "nie masz przedmiotu na miejscu nr: " + i << std::endl;
    }
    else{

        std::cout << this->inventory.size() << std::endl;
        Item item = this->inventory[i];

        Helmet newHelmet;
        Weapon newWeapon;
        Armor newArmor;
        SecondaryWeapon newSWeapon;
        Boots newBoots;

        switch (item.type) {
        case 0:
            this->currentHealth += inventory[i].health;
            if (currentHealth > maxHealth) {
                currentHealth = maxHealth;
            }
            this->inventory.erase(this->inventory.begin() + i);
         
            break;
        case 1:
            newHelmet = Helmet(item.id, item.type, item.name, item.strength, item.agility, item.iq, item.speed, item.health, item.image, item.price);

            if (this->helmet.isItemSet() == 0) {

                setItem(newHelmet);
                addStats(item.strength, item.agility, item.iq, item.health);

                this->inventory.erase(this->inventory.begin() + i);
            }
            break;
        case 2:
            newWeapon = Weapon(item.id, item.type, item.name, item.strength, item.agility, item.iq, item.speed, item.health, item.image, item.price);
            if (this->weapon.isItemSet() == 0) {
                setItem(newWeapon);
                addStats(item.strength, item.agility, item.iq, item.health);
                damage += item.speed;

                this->inventory.erase(this->inventory.begin() + i);
            }
            break;
        case 3:
            newArmor = Armor(item.id, item.type, item.name, item.strength, item.agility, item.iq, item.speed, item.health, item.image, item.price);
            if (this->armor.isItemSet() == 0) {
                setItem(newArmor);
                addStats(item.strength, item.agility, item.iq, item.health);
                this->inventory.erase(this->inventory.begin() + i);
            }
            break;
        case 4:
            newSWeapon = SecondaryWeapon(item.id, item.type, item.name, item.strength, item.agility, item.iq, item.speed, item.health, item.image, item.price);
            if (this->secondaryWeapon.isItemSet() == 0) {
                setItem(newSWeapon);
                this->inventory.erase(this->inventory.begin() + i);
            }
            break;
        case 5:
            newBoots = Boots(item.id, item.type, item.name, item.strength, item.agility, item.iq, item.speed, item.health, item.image, item.price);
            if (this->boots.isItemSet() == 0) {
                setItem(newBoots);
                addStats(item.strength, item.agility, item.iq, item.health);
                this->inventory.erase(this->inventory.begin() + i);
            }
            break;

        }

    }
}

void Player::unEquip(int i) {
    if (this->inventory.size() < 36) {
        switch (i) {
        case 0:
            if (this->helmet.isItemSet()) {
                this->inventory.push_back(this->helmet);

                addStats(this->helmet.strength * -1, this->helmet.agility * -1, this->helmet.iq * -1, this->helmet.health*-1);

                this->helmet = Helmet();
            }
            break;
        case 1:
            if (this->weapon.isItemSet()) {
                this->inventory.push_back(this->weapon);

                addStats(this->weapon.strength * -1, this->weapon.agility * -1, this->weapon.iq * -1, this->weapon.health * -1);
                damage += this->weapon.speed;
                this->weapon = Weapon();
            }
            break;
        case 2:
            if (this->armor.isItemSet()) {
                this->inventory.push_back(this->armor);

                addStats(this->armor.strength * -1, this->armor.agility * -1, this->armor.iq * -1, this->armor.health * -1);
                this->armor = Armor();
            }
            break;
        case 3:
            if (this->secondaryWeapon.isItemSet()) {
                this->inventory.push_back(this->secondaryWeapon);

                addStats(this->secondaryWeapon.strength * -1, this->secondaryWeapon.agility * -1, this->secondaryWeapon.iq * -1, this->secondaryWeapon.health * -1);
                damage += this->secondaryWeapon.speed;
                this->secondaryWeapon = SecondaryWeapon();
            }
            break;
        case 4:
            if (this->boots.isItemSet()) {
                this->inventory.push_back(this->boots);

                addStats(this->boots.strength * -1, this->boots.agility * -1, this->boots.iq * -1, this->boots.health * -1);
                this->boots = Boots();
            }
            break;
        }
    }
}




void Player::sell(int i) {
    if (i >= this->inventory.size()) {
        std::cout << "nie masz przedmiotu na miejscu nr: " + i << std::endl;
    }
    else {
        this->gold += this->inventory[i].price;
        this->inventory.erase(this->inventory.begin() + i);
    }
}


int Player::vsNpc(std::vector<Npc> npcety,Item loot) {
    int i = 0;
    int res = -1;
    
    for (i = 0; i < npcety.size(); i++) {
        std::cout << round(getX() / 48) << " - " << round(npcety[i].getX() / 48) << std::endl;
        if (round(getX() / 48) == round(npcety[i].getX()) && round(getY() / 48) == round(npcety[i].getY())){
            res = i;
        }
    }


    if (res >= 0) {
        int enemyMax = npcety[res].getHp();
        int enemyHp = npcety[res].getHp();
        int damageP;
        int damageE = npcety[res].getDamage();

        int enemyDamage = npcety[res].getDamage();

        while (enemyHp > 0 && getCurrentHealth() > 0) {
            std::cout << enemyHp << "/" << enemyMax << std::endl;
            damageP = getDamage() * 0.8 + getDamage() * rand() % 4 / 10 - 2;
            enemyHp -= damageP;

            std::cout << getCurrentHealth() << "/" << getMaxHealth() << std::endl;
            damageE = damageE * 0.8 + damageE * rand() % 4 / 10;
            setFightDamage(damageE);
        }

        if (currentHealth <= 0) {
            currentHealth = 1;
        }
        else
        {
            addToInventory(loot);
            addExp(getLevel()*80);
            return res;
        }

    }
    
    return -1;


}
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Helmet.h"
#include "Armor.h"
#include "Weapon.h"
#include "SecondaryWeapon.h"
#include "Boots.h"
#include "Npc.h"


class Player
{
private:
    //polozenie
    std::string name;
    float x;
    float y;

    int spriteLeft;
    int spriteTop;
    int spriteWidth;
    int spriteHeight;
    int leftFrame;

    int level;

    int damage;
    int strength;
    int agility;
    int iq;

    int maxHealth;
    int currentHealth;

    int maxExp;
    int currentExp;

    int gold;

   
public:
    //sprite
    

    sf::Texture texture;

    //stats
    float movementSpeed;
    std::vector<Item> inventory;
    int inventoryRow;

    //eq

    Helmet helmet;
    Weapon weapon;
    Armor armor;
    SecondaryWeapon secondaryWeapon;
    Boots boots;

   




    Player();

    void translate(float tx, float ty);
    void draw(sf::RenderWindow& window);
    void moveSprite(int direction);
    void setPosition(float x, float y); 
    void setSpriteTop(int i);

    void setName(std::string name);
    void LevelUp();
    void addExp(int exp);
    void setItem(Helmet item);
    void setItem(Weapon item);
    void setItem(Armor item);
    void setItem(SecondaryWeapon item);
    void setItem(Boots item);
    void setInventoryRow(int i);

    float getX();
    float getY();
    std::string getName();
    int getLevel();
    int getStrenght();
    int getAgility();
    int getIq();
    int getDamage();
    int getGold();

    int getCurrentHealth();
    int getMaxHealth();
    int getCurrentExp();
    int getMaxExp();

    void setFightDamage(int damage);

    int vsNpc(std::vector<Npc> npcety, Item loot);
    int getInventoryRow();


    Helmet getHelmet();
    Weapon getWeapon();
    Armor getArmor();
    SecondaryWeapon getSecondaryWeapon();
    Boots getBoots();


    void equip(int i);
    void unEquip(int i);
    void sell(int i);
    void addToInventory(Item item);
    void addStats(int strength,int agility,int iq, int health);
};

#endif
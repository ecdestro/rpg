#include <iostream>
#include <string>

#ifndef __ACTOR_H_INCLUDED__
#define __ACTOR_H_INCLUDED__

class Actor {
public:
	Actor();
	Actor(std::string handle, int HP, int dmg, int init);
	~Actor();

	void setHP(int HP);
	int getHP();
	void setDamage(int dmg);
	int getDamage();
	void setName(std::string handle);
	std::string getName();	
	void setInit(int init);	
	int getInit();
	void print();

private:
	std::string name;
	int hitPoints;
	int damage;
	int initiative;
};

#endif
#include "actor.h"

Actor::Actor() {}

Actor::Actor(std::string handle = "", int HP = 0, int dmg = 0, int init = 0) {
	setName(handle);
	setHP(HP);
	setDamage(dmg);
	setInit(init);
	//std::cout << "Actor " << getName() << " created with " << getHP();
	//std::cout << " and " << getDamage() << " attack." << std::endl;
	//std::cout << getName() << "'s initiative is " << getInit(); << std::endl;
}

Actor::~Actor() {}

void Actor::setHP(int HP) {
	hitPoints = HP;
}

int Actor::getHP() {
	return hitPoints;
}

void Actor::setDamage(int dmg) {
	damage = dmg;
}

int Actor::getDamage() {
	return damage;
}

void Actor::setName(std::string handle) {
	name = handle;
}

std::string Actor::getName() {
	return name;
}

void Actor::setInit(int init) {
	initiative = init;
}

int Actor::getInit() {
	return initiative;
}

void Actor::print() {
	std::cout << "Name = " << getName() << std::endl;
	std::cout << "HP = " << getHP() << std::endl;
	std::cout << "Dmg = " << getDamage() << std::endl;
	std::cout << "Init = " << getInit() << std::endl;
}
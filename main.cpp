#include <iostream>
#include <string>
#include <unistd.h>

class Actor {
public:
	Actor(std::string handle = "", int HP = 0, int dmg = 0) {
		setName(handle);
		setHP(HP);
		setDamage(dmg);
		//std::cout << "Actor " << getName() << " created with " << getHP();
		//std::cout << " and " << getDamage() << " attack." << std::endl;
	}
	~Actor() {}

	void setHP(int HP) {
		hitPoints = HP;
	}

	int getHP() {
		return hitPoints;
	}

	void setDamage(int dmg) {
		damage = dmg;
	}

	int getDamage() {
		return damage;
	}

	void setName(std::string handle) {
		name = handle;
	}

	std::string getName() {
		return name;
	}

	void print() {
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "HP = " << getHP() << std::endl;
		std::cout << "Dmg = " << getDamage() << std::endl;
	}

private:
	int hitPoints;
	int damage;
	std::string name;
};

Actor combat(Actor char1, Actor char2) {
	std::cout << "Attack!" << std::endl;
	Actor victor;
	int round = 1;
	int hitChance = 0;
	while ((char1.getHP() > 0) && (char2.getHP() > 0)) {
		sleep(rand() % 3);
		std::cout << "Round " << round << " FIGHT!" << std::endl;
		hitChance = rand() % 3;
		std::cout << "Hit chance player1 = " << hitChance << std::endl;
		if (hitChance != 0) {
			std::cout << "HIT!\n"; 
			char1.setHP(char1.getHP() - rand() % char2.getDamage());
		}
		else {
			std::cout << "Miss!\n";
		}

		hitChance = rand() % 3;
		std::cout << "Hit chance player2 = " << hitChance << std::endl;
		if (hitChance != 0) {
			std::cout << "HIT!\n";
			char2.setHP(char2.getHP() - rand() % char1.getDamage());
		}
		else {
			std::cout << "Miss!\n";
		}

		char1.print();
		char2.print();
		round++;
	}
	if (char1.getHP() > 0) {
		victor = char1;
	}
	else if (char2.getHP() > 0) {
		victor = char2;
	}

	return victor;
}

int main() {
	Actor player1("player1",30,5);
	Actor player2("player2",30,5);
	Actor victor;

	victor = combat(player1, player2);
	std::cout << "Winner!\n";
	victor.print();
	//player1.print();
	//player2.print();

	return 0;
}
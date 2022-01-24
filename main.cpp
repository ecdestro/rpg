#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

class Actor {
public:
	Actor(std::string handle = "", int HP = 0, int dmg = 0, int init = 0) {
		setName(handle);
		setHP(HP);
		setDamage(dmg);
		setInit(init);
		//std::cout << "Actor " << getName() << " created with " << getHP();
		//std::cout << " and " << getDamage() << " attack." << std::endl;
		//std::cout << getName() << "'s initiative is " << getInit(); << std::endl;
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
	
	void setInit(int init) {
		initiative = init;
	}
	
	int getInit() {
		return initiative;
	}

	void print() {
		std::cout << "Name = " << getName() << std::endl;
		std::cout << "HP = " << getHP() << std::endl;
		std::cout << "Dmg = " << getDamage() << std::endl;
		std::cout << "Init = " << getInit() << std::endl;
	}

private:
	std::string name;
	int hitPoints;
	int damage;
	int initiative;
};

Actor combat(Actor char1, Actor char2) {
	std::cout << "Attack!" << std::endl;
	Actor victor, initTop, initBot;
	srand(time(0));
	int round = 1;
	int hitChance = 0;
	int rand1 = rand() % 5;
	int rand2 = rand() % 5;

	// Compare initiative rolls
	if ((char1.getInit() + rand1) > (char2.getInit() + rand2)) {
		initTop = char1;
		initTop.setInit(char1.getInit() + rand1);
		initBot = char2;
		initBot.setInit(char2.getInit() + rand2);
	}
	else if ((char2.getInit() + rand1) > (char1.getInit() + rand2)) {
		initTop = char2;
		initTop.setInit(char2.getInit() + rand1);
		initBot = char1;
		initBot.setInit(char1.getInit() + rand2);
	}
	else { // On a tie, flip a coin - This does not give advantage to who has the higher initiative modifier
		int rand0 = rand() % 2;
		if (rand0) {
			initTop = char1;
			initTop.setInit(char1.getInit() + rand0);
			initBot = char2;
		}
		else {
			initTop = char2;
			initTop.setInit(char2.getInit() + rand0);
			initBot = char1;
		}
	}
	std::cout << initTop.getName() << " starts the fight. (Initiaive " << initTop.getName() << " " << initTop.getInit();
	std::cout << " versus " << initBot.getName() << " " << initBot.getInit() << ")" << std::endl;
	// Start the encounter loop
	while ((initTop.getHP() > 0) && (initBot.getHP() > 0)) {
		sleep(1);
		std::cout << "Round " << round << " FIGHT!" << std::endl;
		hitChance = rand() % 2;
		std::cout << "Hit chance " << initTop.getName() << " = " << hitChance << std::endl;
		if (hitChance != 0) {
			initTop.setDamage(rand() % initTop.getDamage() + 1);
			initBot.setHP(initBot.getHP() - initTop.getDamage());
			std::cout << "HIT! for " << initTop.getDamage() << std::endl;
			initBot.print();
		}
		else {
			std::cout << "Miss!\n";
		}

		hitChance = rand() % 2;
		std::cout << "Hit chance " << initBot.getName() << " = " << hitChance << std::endl;
		if (hitChance != 0) {
			initBot.setDamage(rand() % initBot.getDamage() + 1);
			initTop.setHP(initTop.getHP() - initBot.getDamage());
			std::cout << "HIT! for " << initBot.getDamage() << std::endl;
			initTop.print();
		}
		else {
			std::cout << "Miss!\n";
		}
		round++;
	}
	if (initTop.getHP() > 0) {
		victor = initTop;
	}
	else if (initBot.getHP() > 0) {
		victor = initBot;
	}
	initTop.print();
	initBot.print();
	return victor;
}

int main() {
	//Actor object("name",HP,DMG,Init);
	Actor player1("player1",30,5,5);
	Actor player2("player2",30,5,5);
	Actor victor;

	victor = combat(player1, player2);
	std::cout << "Winner! " << victor.getName() << std::endl;

	return 0;
}
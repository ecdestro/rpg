#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include "combat.hpp"

Actor combat(Actor char1, Actor char2) {
	std::cout << "Attack!" << std::endl;
	Actor victor, initTop, initBot;
	srand(time(0));
	int round = 1;
	int hitChance = 0;

	if (char1.getInit() > char2.getInit()) {
		initTop = char1;
		initBot = char2;
	}
	else if (char2.getInit() > char1.getInit()) {
		initTop = char2;
		initBot = char1;
	}
	else {
		if (rand() % 1) {
			initTop = char1;
			initBot = char2;
			std::cout << char1.getName() << " won the coin flip\n";
		}
		else {
			initTop = char2;
			initBot = char1;
			std::cout << char2.getName() << " won the coin flip\n";
		}
	}

	std::cout << initTop.getName() << " starts the fight. (Initiaive " << initTop.getName() << " " << initTop.getInit();
	std::cout << " versus " << initBot.getName() << " " << initBot.getInit() << ")" << std::endl;
	// Start the encounter loop
	while ((initTop.getHP() > 0) && (initBot.getHP() > 0)) {
		std::cout << "Round " << round << " FIGHT!" << std::endl;
		hitChance = rand() % 2;
		std::cout << "Hit chance " << initTop.getName() << " = " << hitChance << std::endl;
		if (hitChance != 0) {
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

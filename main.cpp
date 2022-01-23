#include <iostream>
#include <string>

class Character {
public:
	Character(std::string handle, int HP, int dmg) {
		setName(handle);
		setHP(HP);
		setDamage(dmg);
		//std::cout << "Character " << getName() << " created with " << getHP();
		//std::cout << " and " << getDamage() << " attack." << std::endl;
	}
	~Character() {}

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

Character combat(Character char1, Character char2) {
	std::cout << "Attack!" << std::endl;
	Character victor("winner",0,0);
	int round = 1;
	while ((char1.getHP() >= 0) && (char2.getHP() >= 0)) {
		std::cout << "Round " << round << " FIGHT!" << std::endl;
		char1.setHP(char1.getHP() - char2.getDamage());
		char2.setHP(char2.getHP() - char1.getDamage());
		char1.print();
		char2.print();
		round++;
	}
	if (char1.getHP() >= 0) {
		victor = char1;
	}
	else if (char2.getHP() >= 0) {
		victor = char2;
	}

	return victor;
}	

int main() {
	Character player1("player1",25,15);
	Character player2("player2",45,5);
	Character victor("winner",0,0);
	
	victor = combat(player1, player2);
	std::cout << "Winner!\n";
	victor.print();
	//player1.print();
	//player2.print();

	return 0;
}

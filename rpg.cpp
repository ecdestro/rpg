#include "actor.h"
#include "combat.h"

int main() {
	//Actor object("name",HP,DMG,Init);
	Actor player1("player1",30,5,5);
	Actor player2("player2",30,5,5);
	Actor victor;

	victor = combat(player1, player2);
	std::cout << "Winner! " << victor.getName() << std::endl;

	return 0;
}
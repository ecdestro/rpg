#include <string>
#include "play.hpp"
#include "actor.hpp"
#include "combat.hpp"

int run() {
    std::string playerName;
    std::cout << "Enter a name: ";
    std::cin >> playerName;

    Actor generated(playerName,30,5,5);
    Actor opponent("Enemy",30,5,5);
    Actor victor;

    victor = combat(generated, opponent);

    std::cout << "Winner! " << victor.getName() << std::endl;

    return 0;
}
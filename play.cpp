#include <string>
#include "play.hpp"
#include "actor.hpp"
#include "combat.hpp"
#include "fileLoadSave.hpp"

int encounter(Actor player) {
    Actor opponent("Enemy",30,5,5);
    Actor victor;
    if (player.getHP() == 0) {
        player = loadPlayer();
    }
    else {
        victor = combat(player, opponent);
    }    

    std::cout << "Winner! " << victor.getName() << std::endl;

    return 0;
}
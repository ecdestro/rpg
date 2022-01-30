#include <string>
#include <cstdlib>
#include <time.h>
#include "play.hpp"
#include "actor.hpp"
#include "combat.hpp"
#include "fileLoadSave.hpp"

Actor encounter(Actor player) {
    srand(time(0));
    Actor opponent("Enemy",15 + (rand() % 15), 5 + (rand() % 5), 5 + (rand() % 5));
    Actor victor;
    if (player.getHP() == 0) {
        //player = loadPlayer();
        player.print();
    }
    else {
        victor = combat(player, opponent);
    }    

    std::cout << "Winner! " << victor.getName() << std::endl;

    if (victor.getName() == player.getName()) {
        victor.setName(player.getName());
        victor.setHP(victor.getHP());
        victor.setDamage(player.getDamage());
        victor.setInit(player.getInit());
        return victor;
    }
    else {
        player.setHP(1);
        return player;
    }
}
#include <iostream>
#include <fstream>
#include "actor.hpp"

Actor createCharacter() {
    Actor player;
    std::string fName = "";
    std::cout << "Name your character\n";
    std::cin >> fName;
    std::ofstream fileOut("players/" + fName);

    player.setName(fName);
    player.setHP(30);
    player.setDamage(5);
    player.setInit(6);
    fileOut << player.getName() << " ";
    fileOut << player.getHP() << " ";
    fileOut << player.getDamage() << " ";
    fileOut << player.getInit() << " ";
    fileOut.close();
    return player;
}
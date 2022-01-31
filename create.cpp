#include <iostream>
//#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "actor.hpp"

Actor createCharacter() {
    Actor player;
    srand(time(0));
    char choice = 'Y';
    std::string fName = "";
    std::cout << "Name your character\n";
    std::cin >> fName;
    
    while (choice == 'Y' || choice == 'y') {
        player.setName(fName);
        player.setHP(30 + (rand() % 15));
        player.setDamage(5 + (rand() % 5));
        player.setInit(5 + (rand() % 5));
        player.print();
        std::cout << "\nRefresh this character? Y/N\n";
        std::cin >> choice;
    }
    
    if (std::filesystem::exists("players")) {
        std::ofstream fileOut("players/" + fName);
        fileOut << player.getName() << " ";
        fileOut << player.getHP() << " ";
        fileOut << player.getDamage() << " ";
        fileOut << player.getInit();
        fileOut.close();
    }
    else {
        std::filesystem::create_directory("players");
        std::ofstream fileOut("players/" + fName);
        fileOut << player.getName() << " ";
        fileOut << player.getHP() << " ";
        fileOut << player.getDamage() << " ";
        fileOut << player.getInit();
        fileOut.close();
    }
    return player;
}
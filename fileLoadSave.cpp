#include <fstream>
#include "actor.hpp"
#include "menu.hpp"

Actor loadPlayer() {
    Actor player;
    std::string read = "";
    std::string fName = "";
    std::cout << "Enter a player name\n";
    std::cin >> fName;

    std::ifstream fileIn(fName);
    if (fileIn.fail()) {
        std::cout << "Error opening player file\n";
        return player;
    }
    for (int i = 0; !fileIn.eof() && (i < 4); i++) {
        fileIn >> read;
        if (i == 0) {
            player.setName(read);
        }
        else if (i == 1) {
            player.setHP(std::stoi(read));
        }
        else if (i == 2) {
            player.setDamage(std::stoi(read));
        }
        else {
            player.setInit(std::stoi(read));
        }
    }

    fileIn.close();

    player.print();
    
    return player;
}

void savePlayer(Actor player) {
    std::string fName = "";
    std::cout << "Name your character\n";
    std::cin >> fName;
    std::ofstream fileOut(fName);

    player.setName(fName);
    player.setHP(30);
    player.setDamage(5);
    player.setInit(6);
    fileOut << player.getName() << " ";
    fileOut << player.getHP() << " ";
    fileOut << player.getDamage() << " ";
    fileOut << player.getInit() << " ";
    fileOut.close();

    std::cout << "Character saved!\n";
}

int fileLoadSave() {
    Actor player;
    char choice;
    std::cout << "Load or Create character?\n";
    std::cout << "\tA - Load\n";
    std::cout << "\tB - Create\n";
    std::cin >> choice;

    if (choice == 'A' || choice == 'a') {
        player = loadPlayer();
        mainMenu();
    }
    else if (choice == 'B' || choice == 'b') {
        savePlayer(player);
        mainMenu();
    }

    return 0;
}
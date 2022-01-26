#include <fstream>
#include <filesystem>
#include "actor.hpp"
#include "menu.hpp"
#include "create.hpp"

void listFiles() {
    std::string path = "players";
    for (const auto & entry : std::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}

Actor loadPlayer() {
    listFiles();
    Actor player;
    std::string read = "";
    std::string fName = "";
    std::cout << "Enter a player name\n";
    std::cin >> fName;

    std::ifstream fileIn("players/" + fName);
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
    std::ofstream fileOut("players/" + player.getName());
    fileOut << player.getName() << " ";
    fileOut << player.getHP() << " ";
    fileOut << player.getDamage() << " ";
    fileOut << player.getInit();
    fileOut.close();
    std::cout << "Character saved!\n";
}

Actor fileLoadSave() {
    char choice;
    Actor player;
    std::cout << "Load or Save character?\n";
    std::cout << "\tA - Load\n";
    std::cout << "\tB - Save\n";
    std::cout << "\tC - Back\n";
    std::cin >> choice;

    if (choice == 'A' || choice == 'a') {
        player = loadPlayer();
        return player;
    }
    else if (choice == 'B' || choice == 'b') {
        savePlayer(player);
        return player;
    }
    else if (choice == 'C' || choice == 'c') {
        return player;
    }
    return player;
}
#include <string>
#include <fstream>
#include <filesystem>
#include "actor.hpp"
#include "create.hpp"

void listFiles() {
    for (const auto & entry : std::filesystem::directory_iterator("players")){
        std::string players;
        players = entry.path().string();
        players.erase(0,8);
        std::cout << players << std::endl;
    }
}

Actor loadPlayer() {
    listFiles();
    Actor player;
    std::string read = "";
    std::string fName = "";
    std::cout << "Enter a player name\n";
    std::cin >> fName;

    if (!std::filesystem::exists("players")) {
        std::cout << "No Player Characters created!\n";
        player = createCharacter();
    }
    else {
        std::ifstream fileIn("players/" + fName);
        if (fileIn.fail()) {
        std::cout << "Error opening player file\n";
        return player;
        }
        else {
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
        }
        fileIn.close();
    }    
    
    player.print();
    return player;
}

Actor savePlayer(Actor player) {
    std::ofstream fileOut("players/" + player.getName());
    fileOut << player.getName() << " ";
    fileOut << player.getHP() << " ";
    fileOut << player.getDamage() << " ";
    fileOut << player.getInit();
    fileOut.close();
    std::cout << "Character saved!\n";

    return player;
}
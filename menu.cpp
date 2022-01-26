#include "menu.hpp"
#include "demo/demo.hpp"
#include "play.hpp"
#include "create.hpp"
#include "actor.hpp"
#include "fileLoadSave.hpp"

Actor player("",0,0,0);

void mainMenu() {
    char option;
    std::cout << "\nRPG v0.0.1" << "\tCurrent character: " << player.getName();
    std::cout << std::endl << std::endl;
    std::cout << "Please choose an option:\n";
    //std::cout << "\tA - Play the Demo\n";
    std::cout << "\tA - Play\n";
    std::cout << "\tB - Load and Save\n";
    std::cout << "\tC - Create Character\n";
    std::cout << "\tD - Quit\n";
    std::cin >> option;

    if (option == 'A' || option == 'a') {
        player = loadPlayer();
        encounter(player);
    }
    else if (option == 'B' || option == 'b') {
        fileLoadSave();
    }
    else if (option == 'C' || option == 'c') {
        player = createCharacter();
    }
    else if (option == 'D' || option == 'd') {
        return;
    }
    else {
        mainMenu();
    }
}
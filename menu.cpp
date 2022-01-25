#include "menu.hpp"
#include "demo.hpp"
#include "play.hpp"
#include "fileLoadSave.hpp"

int mainMenu() {
    char option;
    
    std::cout << "RPG v0.0.1" << std::endl << std::endl;
    std::cout << "Please choose an option:\n";
    std::cout << "\tA - Play the Demo\n";
    std::cout << "\tB - Load and Save\n";
    std::cout << "\tC - Quit\n";
    std::cin >> option;
    
    if (option == 'A' || option == 'a') {
        demo();
    }
    else if (option == 'B' || option == 'b') {
        fileLoadSave();
    }
    else if (option == 'C' || option == 'c') {
        return 0;
    }

    return 0;
}
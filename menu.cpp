#include "menu.hpp"
#include "demo.hpp"
#include "play.hpp"

int mainMenu() {
    char option;
    
    std::cout << "RPG v0.0.1" << std::endl << std::endl;
    std::cout << "Please choose an option:\n";
    std::cout << "\tA - Play the Demo\n";
    std::cout << "\tB - Generate a character\n";
    std::cout << "\tC - Quit\n";
    std::cin >> option;
    
    if (option == 'A') {
        demo();
    }
    else if (option == 'B') {
        run();
    }
    else if (option == 'C') {
        return 0;
    }

    return 0;
}
#include <filesystem>
#include "actor.hpp"
#include "combat.hpp"
#include "fileLoadSave.hpp"
#include "play.hpp"
#include "create.hpp"

int main() {
    char option;
	Actor player("None",0,0,0);

    while (option != 'E' && option != 'e') {
		std::cout << "\nRPG v0.0.3" << std::endl;
		std::cout << "Current character: " << std::endl;
		player.print();
		std::cout << std::endl << std::endl;

		std::cout << "Please choose an option:\n";
		std::cout << "\tA - Play\n";
		std::cout << "\tB - Load\n";
		std::cout << "\tC - Save\n";
		std::cout << "\tD - New\n";
		std::cout << "\tE - Quit\n";
		std::cin >> option;

        if (option == 'A' || option == 'a') {
            if (!std::filesystem::exists("players")) {
				player = createCharacter();
			}
			else {
				player = encounter(player);
			}
        }
        else if (option == 'B' || option == 'b') {
            player = loadPlayer();
        }
        else if (option == 'C' || option == 'c') {
            if (player.getName() == "") {
				std::cout << "Can't save!\n";
			}
			else {
				player = savePlayer(player);
        	}
		}	
		else if (option == 'D' || option == 'd') {
			player = createCharacter();
		}
    }

	return 0;
}

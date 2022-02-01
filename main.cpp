#include <SFML/Graphics.hpp>
#include "menu.hpp"

// int menu() {
// 	char option;
// 	Actor player("None",0,0,0);

//     while (option != 'E' && option != 'e') {
// 		std::cout << "\nRPG v0.0.4" << std::endl;
// 		std::cout << "Current character: " << std::endl;
// 		if (player.getName() == "None") {
// 			std::cout << "None selected\n";
// 		}
// 		else {
// 			player.print();
// 		}
// 		std::cout << std::endl << std::endl;

// 		std::cout << "Please choose an option:\n";
// 		std::cout << "\tA - Play\n";
// 		std::cout << "\tB - Load\n";
// 		std::cout << "\tC - Save\n";
// 		std::cout << "\tD - New\n";
// 		std::cout << "\tE - Quit\n";
// 		std::cin >> option;

//         if (option == 'A' || option == 'a') {
//             if (!std::filesystem::exists("players")) {
// 				player = createCharacter();
// 			}
// 			else {
// 				player = encounter(player);
// 			}
//         }
//         else if (option == 'B' || option == 'b') {
//             player = loadPlayer();
//         }
//         else if (option == 'C' || option == 'c') {
//             if (player.getName() == "None") {
// 				std::cout << "Can't save!\n";
// 			}
// 			else {
// 				player = savePlayer(player);
//         	}
// 		}	
// 		else if (option == 'D' || option == 'd') {
// 			player = createCharacter();
// 		}
//     }

// 	return 0;
// }

int main() {
	sf::RenderWindow MENU(sf::VideoMode(1200, 600), "RPG v0.0.4", sf::Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	while (MENU.isOpen()) {
		sf::Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				MENU.close();
			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					mainMenu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {
					int choice = mainMenu.MainMenuPressed();
					if (choice == 0) {
						MENU.clear();
						mainMenu.draw(MENU);
						MENU.display();
					}
					if (choice == 1) {
						MENU.clear();
						mainMenu.draw(MENU);
						MENU.display();
					}
					if (choice == 2) {
						MENU.clear();
						mainMenu.draw(MENU);
						MENU.display();
					}
					if (choice == 3) {
						MENU.clear();
						mainMenu.draw(MENU);
						MENU.display();
					}
					if (choice == 4) {
						MENU.close();
					}
				}
			}
		}
		MENU.clear();
		mainMenu.draw(MENU);
		MENU.display();
	}

	return 0;
}




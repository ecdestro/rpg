#include "menu.hpp"

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "Font not loaded\n";
    }

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::Yellow);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(24);
    mainMenu[0].setPosition(200, 200);

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::Yellow);
    mainMenu[1].setString("Load");
    mainMenu[1].setCharacterSize(24);
    mainMenu[1].setPosition(200, 250);

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::Yellow);
    mainMenu[2].setString("Save");
    mainMenu[2].setCharacterSize(24);
    mainMenu[2].setPosition(200, 300);

    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::Yellow);
    mainMenu[3].setString("New");
    mainMenu[3].setCharacterSize(24);
    mainMenu[3].setPosition(200, 350);

    mainMenu[4].setFont(font);
    mainMenu[4].setFillColor(sf::Color::Yellow);
    mainMenu[4].setString("Exit");
    mainMenu[4].setCharacterSize(24);
    mainMenu[4].setPosition(200, 400);

    MainMenuSelected = -1;
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::moveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);

        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Green);
    }
}

void MainMenu::moveDown() {
    if (MainMenuSelected + 1 <= max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Yellow);
        MainMenuSelected++;
        if (MainMenuSelected == 5) {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(sf::Color::Green);
    }
}
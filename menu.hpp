#include <SFML/Graphics.hpp>
#include <iostream>

#define max_main_menu 5
class MainMenu {
public:
    MainMenu(float width, float height);
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int MainMenuPressed() {
        return MainMenuSelected;
    }
    ~MainMenu();

private:
    int MainMenuSelected;
    sf::Font font;
    sf::Text mainMenu[max_main_menu];
};
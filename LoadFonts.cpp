#include <StudentManager.hpp>

void LoadFonts(sf::Font &font1, sf::Font &font2, sf::Font &font3, sf::Font &font4, sf::Font &font5)
{
    font1.loadFromFile("../resources/Lato/Lato-Regular.ttf");
    font2.loadFromFile("../resources/Lato/Lato-Bold.ttf");
    font3.loadFromFile("../resources/Lato/Lato-Italic.ttf");
    font4.loadFromFile("../resources/Lato/Lato-Light.ttf");
    font5.loadFromFile("../resources/Lato/Lato-Heavy.ttf");
}
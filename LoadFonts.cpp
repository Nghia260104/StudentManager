#include <LoadFonts.hpp>
#include <FrontendGlobal.hpp>

// void LoadFonts(sf::Font &font1, sf::Font &font2, sf::Font &font3, sf::Font &font4, sf::Font &font5)
// {
//     font1.loadFromFile("../resources/Font/Fira Code/FiraCode-Regular.ttf");
//     font2.loadFromFile("../resources/Font/Fira Code/FiraCode-Bold.ttf");
//     font3.loadFromFile("../resources/Font/Fira Code/FiraCode-Medium.ttf");
//     font4.loadFromFile("../resources/Font/Fira Code/FiraCode-Light.ttf");
//     font5.loadFromFile("../resources/Font/Fira Code/FiraCode-SemiBold.ttf");
// }

void loadFont()
{
    RegularFont.loadFromFile("../resources/Font/Fira Code/FiraCode-Regular.ttf");
    BoldFont.loadFromFile("../resources/Font/Fira Code/FiraCode-Bold.ttf");
    MediumFont.loadFromFile("../resources/Font/Fira Code/FiraCode-Medium.ttf");
    LightFont.loadFromFile("../resources/Font/Fira Code/FiraCode-Light.ttf");
    HeavyFont.loadFromFile("../resources/Font/Fira Code/FiraCode-SemiBold.ttf");
    Helvetica.loadFromFile("../resources/Font/TTF file/Helvetica.ttf");
    RecRobot.loadFromFile("../resources/Font/TTF file/Roboto-Regular.ttf");
    RecOpen.loadFromFile("../resources/Font/TTF file/OpenSans-Regular.ttf");
    Alga.loadFromFile("../resources/Font/TTF file/Ahganirya.ttf");
    JB.loadFromFile("../resources/Font/TTF file/JetBrainsMonoNL-Regular.ttf");
    Arial.loadFromFile("../resources/Font/TTF file/ArialNova.ttf");
    ArialBold.loadFromFile("../resources/Font/TTF file/ArialNova-Bold.ttf");
    Times.loadFromFile("../resources/Font/TTF file/times.ttf");
    TimesBold.loadFromFile("../resources/Font/TTF file/timesbd.ttf");
    Tahoma.loadFromFile("../resources/Font/TTF file/tahoma.ttf");
    Consola.loadFromFile("../resources/Font/TTF file/consola.ttf");
    Luvenia.loadFromFile("../resources/Font/TTF file/Luvenia.otf");
    Montelgo.loadFromFile("../resources/Font/TTF file/Montelgo.otf");
    Over.loadFromFile("../resources/Font/TTF file/Overbrushing.otf");
}
#include <SFML/Graphics.hpp>
#include <LogIn.hpp>
#include <StudentWindow.hpp>
#include <AdminWindow.hpp>

sf::RenderWindow window;
sf::Clock Clock;
sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont;
sf::Color BackgroundColor;
sf::Cursor cursor;
LogIn LogInWindow;
StudentWindow StudentScreen;
AdminWindow AdminScreen;
int LeftWindowWidth, RightWindowWidth;
#include <SFML/Graphics.hpp>
#include <LogIn.hpp>
#include <StudentWindow.hpp>
#include <AdminWindow.hpp>
#include <StaffWindow.hpp>

sf::RenderWindow window;
sf::Clock Clock;
sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont, Helvetica, RecRobot, RecOpen, Alga, JB, Arial, ArialBold, Times;
sf::Font TimesBold, Tahoma, Consola, Luvenia, Montelgo, Over, IA, Calibri;
sf::Color BackgroundColor, RightSideColor, ButtonColor, TextColor, ButtonCoverColor, RightSideCover, TextCoverColor;
sf::Cursor cursor;
LogIn LogInWindow;
StudentWindow StudentScreen;
AdminWindow AdminScreen;
StaffWindow StaffScreen;
int LeftWindowWidth, RightWindowWidth;
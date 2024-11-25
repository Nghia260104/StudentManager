#pragma once
#include <SFML/Graphics.hpp>
#include <LogIn.hpp>
#include <StudentWindow.hpp>
#include <AdminWindow.hpp>
#include <StaffWindow.hpp>

extern sf::RenderWindow window;
extern sf::Clock Clock;
extern sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont, Helvetica, RecRobot, RecOpen, Alga, JB, Arial, ArialBold, Times;
extern sf::Font TimesBold, Tahoma, Consola, Luvenia, Montelgo, Over, IA, Calibri;
extern sf::Color BackgroundColor, RightSideColor, ButtonColor, TextColor, ButtonCoverColor, RightSideCover, TextCoverColor;
extern sf::Cursor cursor;
extern LogIn LogInWindow;
extern StudentWindow StudentScreen;
extern AdminWindow AdminScreen;
extern StaffWindow StaffScreen;
extern int LeftWindowWidth, RightWindowWidth;
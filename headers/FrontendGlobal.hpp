#pragma once
#include <SFML/Graphics.hpp>
#include <LogIn.hpp>
#include <StudentWindow.hpp>
#include <AdminWindow.hpp>

extern sf::RenderWindow window;
extern sf::Clock Clock;
extern sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont;
extern sf::Color BackgroundColor;
extern sf::Cursor cursor;
extern LogIn LogInWindow;
extern StudentWindow StudentScreen;
extern AdminWindow AdminScreen;
extern int LeftWindowWidth, RightWindowWidth;
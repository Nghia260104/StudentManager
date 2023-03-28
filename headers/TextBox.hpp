#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TextBox : public sf::Drawable
{
private:
    float x, y;
    sf::Text Text;
    sf::RectangleShape Rec;
    sf::RenderTexture Texture;
    sf::Color color1, color2;
    sf::Cursor cursor;
    bool isTyping;
    unsigned int EdgeOpacity;
    bool BlinkCursor;

    void drawOpacity();
    void drawBlinkCursor(sf::Clock &clock);
    bool mouseOn(sf::Vector2i MousePos);

public:
    TextBox();
    TextBox(float a, float b, float w, float h);
    TextBox(float a, float b, float w, float h, unsigned int fontsize, float pos = 8.0f);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setPosition(float a, float b);
    void setSize(float w, float h);
    void setFontSize(unsigned int fontsize);
    void setTextPos(float pos = 8.0f);
    void setColor(sf::Color c1 = sf::Color::Black, sf::Color c2 = sf::Color::Black);
    void setTyping(sf::Vector2i MousePos, int Click);
    void setMouseCursor(sf::Window &window);
    void setText(sf::String S);
    void setFont(const sf::Font &font);
    void setOpacity(unsigned int thick = 4);
    void setBlinkCursor();
    void drawTexture(sf::Clock &clock);
    void setTextColor(sf::Color color);
};
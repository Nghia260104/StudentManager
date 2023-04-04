#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
    // Constructor

    Button();
    Button(sf::String S);
    Button(float a, float b, float w, float h, unsigned int fontsize, sf::String S);

    // Box

    void setPosition(float a = 0, float b = 0);
    void setSize(float w = 50, float h = 50);
    void setFillColor(sf::Color color = sf::Color::White, float ratio = 0);
    void setOutline(sf::Color color = sf::Color::Black, float thick = 1.0f);

    // Text

    void setFont(sf::Font &font);
    void setFontSize(unsigned int fontsize);
    void setText(sf::String S);
    void setTextPos();
    void setTextColor(sf::Color color = sf::Color::Black);

    // Misc

    void processEvent(sf::Event event);

    // Draw

    void drawTexture();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    float x, y;
    sf::Vector2f RecSize;
    sf::Text Text;
    sf::RectangleShape Rec;
    sf::RenderTexture Texture;
    sf::Color getContrastColor(sf::Color color, float ratio);
    sf::Vector2i getMousePosition();
    bool mouseOn(sf::Vector2i MousePos);
};
#pragma once
#include <SFML/Graphics.hpp>

class TextBox : public sf::Drawable
{
public:
    // Constructor

    TextBox();
    TextBox(float a, float b, float w, float h, unsigned int fontsize, sf::Vector2f pos);

    // Box

    void setPosition(float a, float b);
    void setSize(float w, float h);
    void setOutlineColor(sf::Color c1 = sf::Color::Black, sf::Color c2 = sf::Color::Black);
    void setFillColor(sf::Color color = sf::Color::White, float ratio = 0);

    // Text

    void setFontSize(unsigned int fontsize = 30);
    void setTextPos(float x = 8.0f);
    void setTextPos(sf::Vector2f pos);
    void setTextColor(sf::Color color = sf::Color::Black);
    void setFont(sf::Font &font);
    void setText(sf::String S);
    void setPassword();

    // Misc

    void processEvent(sf::Event event);
    void setTyping();
    void setCaret();
    sf::RectangleShape Caret();
    void setOpacity(unsigned int thick = 4);
    sf::RectangleShape *Opacity();

    // Draw

    void drawTexture();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    float x, y;
    sf::Vector2f posText;
    sf::Text Text;
    sf::RectangleShape Rec;
    sf::RenderTexture Texture;
    sf::Color color1, color2, fill;
    sf::String Pass;
    bool isTyping, HasCaret, AllowTyping, password;
    unsigned int EdgeOpacity;
    int FKey, Key, limit;
    const int Backspace = sf::Keyboard::Backspace,
              LeftArrow = sf::Keyboard::Left,
              RightArrow = sf::Keyboard::Right,
              Enter = sf::Keyboard::Enter,
              Esc = sf::Keyboard::Escape;
    int Type;
    const int Click = sf::Event::MouseButtonPressed,
              keyPressed = sf::Event::KeyPressed,
              TextEntered = sf::Event::TextEntered;
    int id;
    float charlength;

    sf::Vector2i getMousePosition();
    bool mouseOn(sf::Vector2i MousePos);
    void checkTyping(sf::Event event);
    sf::Color getContrastColor(sf::Color color, float ratio);
    void updateTypePos();
    void updateText();
};
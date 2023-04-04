#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Button.hpp>

class LogIn : public sf::Drawable
{
public:
    // Constructor

    LogIn();
    void create();

    // Misc

    void processEvent(sf::Event event);

    // Draw

    void drawTexture();
    void FirstDraw();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::RenderTexture Texture;
    TextBox Username;
    TextBox Password;
    sf::RectangleShape Bound;
    sf::Text Title, Title1, Title2;
    Button Confirm;
};
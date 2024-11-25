#pragma once
#include <TextBox.hpp>
#include <Button.hpp>

class AddStaffMember : public sf::Drawable
{
public:
    // Constructor

    AddStaffMember();
    void create();

    // Draw

    void drawTexture();
    void FirstDraw();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void clearLine();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, Subtitle, Success, Fail1, Fail2;
    TextBox Username;
    Button Confirm;
    int fail;
    const int empty = 1,
              existed = 2,
              Clear = INT_MAX;
};
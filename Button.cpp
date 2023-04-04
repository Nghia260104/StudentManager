#include <StudentManager.hpp>

extern sf::RenderWindow window;

// Constructor //////////////////////////////////////////////////////////////////////////////////

Button::Button()
{
    setPosition();
    setSize();
    setFillColor();
    setOutline();
}

Button::Button(sf::String S)
{
    setPosition();
    setSize();
    setFillColor();
    setOutline();
    setText(S);
}

Button::Button(float a, float b, float w, float h, unsigned int fontsize, sf::String S)
{
    setPosition(a, b);
    setSize(w, h);
    setFillColor();
    setOutline();
    setFontSize(fontsize);
    setText(S);
}

// Box ///////////////////////////////////////////////////////////////////////////////////////////////

void Button::setPosition(float a, float b)
{
    x = a;
    y = b;
}

void Button::setSize(float w, float h)
{
    Rec.setSize(sf::Vector2f(w, h));
    RecSize = sf::Vector2f(w, h);
}

void Button::setFillColor(sf::Color color, float ratio)
{
    Rec.setFillColor(color);
    if (ratio > 0)
    {
        if (ratio < 4.5)
            ratio = 4.5;
        Text.setFillColor(getContrastColor(color, ratio));
    }
}

void Button::setOutline(sf::Color color, float thick)
{
    Rec.setOutlineColor(color);
    Rec.setOutlineThickness(-1.0f * thick);
}

// Text ////////////////////////////////////////////////////////////////////////////////////////////////

void Button::setFont(sf::Font &font)
{
    Text.setFont(font);
}

void Button::setFontSize(unsigned int fontsize)
{
    Text.setCharacterSize(fontsize);
}

void Button::setText(sf::String S)
{
    Text.setString(S);
}

void Button::setTextPos()
{
    Text.setOrigin(Text.getGlobalBounds().width / 2, 1.0f * Text.getCharacterSize() / 2);
    Text.setPosition(RecSize.x / 2, RecSize.y / 2);
}

void Button::setTextColor(sf::Color color)
{
    Text.setFillColor(color);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////////

// void Button::processEvent(sf::Event event)
// {
//     if (event.type == sf::Event::MouseButtonPressed)
//     {
//         sf::Vector2i MousePos = getMousePosition();
//         if (event.mouseButton.button == sf::Mouse::Left && mouseOn(MousePos))
//         {

//         }
//     }
// }

// Draw ///////////////////////////////////////////////////////////////////////////////////////////////

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Private ////////////////////////////////////////////////////////////////////////////////////////////

sf::Color Button::getContrastColor(sf::Color color, float ratio)
{
    const float Ratio = ratio;
    float L = (color.r * 299 + color.g * 587 + color.b * 114);
    float L1 = (L + 50) / Ratio - 50;
    float L2 = (L + 50) * Ratio - 50;
    sf::Color color10(L1 / 1000 * 299, L1 / 1000 * 587, L1 / 1000 * 114, 255);
    sf::Color color20(L2 / 1000 * 299, L2 / 1000 * 587, L2 / 1000 * 114, 255);
    if (L2 > 1000)
        return color10;
    if (L1 < 0)
        return color20;
    if (abs(L1 - L) > abs(L2 - L))
        return color10;
    else
        return color20;
}

sf::Vector2i Button::getMousePosition()
{
    sf::Mouse mouse;
    return mouse.getPosition(window);
}

bool Button::mouseOn(sf::Vector2i MousePos)
{
    if (x <= MousePos.x && MousePos.x <= x + RecSize.x &&
        y <= MousePos.y && MousePos.y <= y + RecSize.y)
        return true;
    return false;
}
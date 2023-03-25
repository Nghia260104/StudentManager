#pragma once
#include <SFML/Graphics.hpp>

class TextBox : public sf::Drawable
{
private:
    float x, y;
    sf::Text Text;
    sf::RectangleShape Rec;
    sf::RenderTexture Texture;
    sf::Color color1, color2;

public:
    TextBox()
    {
        setPosition(0, 0);
        setSize(0, 0);
        Text.setCharacterSize(30);
    }

    TextBox(float a, float b, float w, float h);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Sprite sprite(Texture.getTexture());
        sprite.setPosition(sf::Vector2f{x, y});
        target.draw(sprite, states);
    }
    void setPosition(float a, float b)
    {
        x = a;
        y = b;
    }

    void setSize(float w, float h)
    {
        Texture.create((unsigned int) w, (unsigned int) h);
        Rec.setSize(sf::Vector2f{w, h});
        Texture.draw(Rec);
    }

    void setFontSize(unsigned int size)
    {
        Text.setCharacterSize(size);
    }
    void setTextPos()
    {
        Text.setPosition(sf::Vector2f{8, Rec.getSize().y / 2 - 1.0f * Text.getCharacterSize() / 2});
    }
    void setup(float a, float b, float w, float h, unsigned int size)
    {
        setPosition(a, b);
        setSize(w, h);
        setFontSize(size);
        setTextPos();
    }
};
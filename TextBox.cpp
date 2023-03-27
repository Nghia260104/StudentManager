#include <StudentManager.hpp>

TextBox::TextBox()
{
    setPosition(0, 0);
    setSize(0, 0);
    Text.setCharacterSize(30);
    framescounter = 0;
    fps = 60;
    isTyping = 0;
    setColor();
    EdgeOpacity = 0;
    BlinkCursor = 0;
}

TextBox::TextBox(float a, float b, float w, float h)
{
    setPosition(a, b);
    setSize(w, h);
    Text.setCharacterSize(30);
    setText("");
    fps = 60;
    framescounter = 0;
    isTyping = 0;
    setColor();
    EdgeOpacity = 0;
    BlinkCursor = 0;
}

TextBox::TextBox(float a, float b, float w, float h, unsigned int fontsize, float pos)
{
    setPosition(a, b);
    setSize(w, h);
    setFontSize(fontsize);
    setTextPos(pos);
    setText("");
    framescounter = 0;
    fps = 60;
    isTyping = 0;
    setColor();
    EdgeOpacity = 0;
    BlinkCursor = 0;
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(sf::Vector2f{x, y});
    target.draw(sprite, states);
}

void TextBox::TestDraw(sf::RenderWindow &window)
{
    sf::Sprite sprite(Texture.getTexture());
    window.draw(sprite);
}

bool TextBox::mouseOn()
{
    sf::Vector2i Pos = mouse.getPosition();
    sf::Vector2f RecSize = Rec.getSize();
    if (Pos.x >= x && Pos.x <= x + RecSize.x && Pos.y >= y && Pos.y <= y + RecSize.y)
        return true;
    return false;
}

void TextBox::setPosition(float a, float b)
{
    x = a;
    y = b;
}

void TextBox::setSize(float w, float h)
{
    Rec.setSize(sf::Vector2f{w, h});
    Rec.setOutlineThickness(-1.0f);
}

void TextBox::setFontSize(unsigned int fontsize)
{
    Text.setCharacterSize(fontsize);
}

void TextBox::setTextPos(float pos)
{
    Text.setPosition(sf::Vector2f{pos, Rec.getSize().y / 2 - 1.0f * Text.getCharacterSize() / 2});
}

void TextBox::setColor(sf::Color c1, sf::Color c2)
{
    color1 = c1;
    color2 = c2;
    Rec.setFillColor(sf::Color::Transparent);
    if (isTyping)
        Rec.setOutlineColor(color2);
    else
        Rec.setOutlineColor(color1);
}

void TextBox::drawOpacity()
{
    if (isTyping)
        for (int i = 0; i < 10 * EdgeOpacity; i++)
        {
            sf::RectangleShape Tmp(sf::Vector2f{Rec.getSize().x - 0.1f * i, Rec.getSize().y - 0.1f * i});
            Tmp.setPosition(sf::Vector2f{0.1f * i, 0.1f * i});
            Tmp.setOutlineColor(sf::Color(color2.r, color2.g, color2.b, 1.0f * 255 * (float)(1 - i / (10 * EdgeOpacity))));
            Tmp.setOutlineThickness(-0.1f);
            Texture.draw(Tmp);
        }
}

void TextBox::setTyping()
{
    if (mouseOn() && mouse.isButtonPressed(sf::Mouse::Left))
        isTyping = true;
    if (mouseOn() && mouse.isButtonPressed(sf::Mouse::Right))
        isTyping = false;
    if (!mouseOn() && mouse.isButtonPressed(sf::Mouse::Left))
        isTyping = false;
}

void TextBox::setMouseCursor(sf::Window &window)
{
    if (isTyping)
    {
        cursor.loadFromSystem(sf::Cursor::Text);
    }
    else
        cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void TextBox::drawBlinkCursor()
{
    if (isTyping)
    {
        framescounter++;
        if ((framescounter / 60) % 2 == 0)
        {
            sf::RectangleShape Cursor(sf::Vector2f{1.0, Text.getGlobalBounds().height});
            Cursor.setPosition(sf::Vector2f{Text.getPosition().x + Text.getLocalBounds().width, Text.getPosition().y});
            Cursor.setFillColor(Text.getFillColor());
            Texture.draw(Cursor);
        }
        if (framescounter % 120 == 0)
            framescounter = 0;
    }
    else
        framescounter = 0;
}

void TextBox::setText(sf::String S)
{
    Text.setString(S);
}

void TextBox::setFont(const sf::Font &font)
{
    Text.setFont(font);
}

void TextBox::setOpacity(unsigned int thick)
{
    EdgeOpacity = thick;
}

void TextBox::setBlinkCursor()
{
    BlinkCursor = 1;
}

void TextBox::drawTexture()
{
    Texture.create((unsigned int)Rec.getSize().x, (unsigned int)Rec.getSize().y);
    Texture.draw(Rec);
    Texture.draw(Text);
    if (EdgeOpacity > 0)
        drawOpacity();
    if (BlinkCursor)
        drawBlinkCursor();
}

void TextBox::setTextColor(sf::Color color)
{
    Text.setFillColor(color);
}
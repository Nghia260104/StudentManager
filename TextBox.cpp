#include <StudentManager.hpp>

TextBox::TextBox()
{
    setPosition(0, 0);
    setSize(0, 0);
    Text.setCharacterSize(30);
    setText("");
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
    isTyping = 0;
    setColor();
    EdgeOpacity = 0;
    BlinkCursor = 0;
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite(Texture.getTexture());
    // sprite.setScale(1, -1);
    sprite.setPosition(sf::Vector2f{x, y});
    sprite.setTextureRect(sf::IntRect(0, Rec.getSize().y, Rec.getSize().x, -Rec.getSize().y));
    target.draw(sprite, states);
}

bool TextBox::mouseOn(sf::Vector2i MousePos)
{
    sf::Vector2i Pos = MousePos;
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
    Text.setOrigin(sf::Vector2f{0, 1.0f * Text.getCharacterSize() / 2});
    Text.setPosition(sf::Vector2f{pos, Rec.getSize().y / 2});
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
            sf::RectangleShape Tmp(sf::Vector2f{Rec.getSize().x - 0.2f * i, Rec.getSize().y - 0.2f * i});
            Tmp.setPosition(sf::Vector2f{0.1f * i, 0.1f * i});
            Tmp.setOutlineColor(sf::Color(color2.r, color2.g, color2.b, 1.0f * 255 * (10 * EdgeOpacity * 1.0f - 1.0f * i) / (10 * EdgeOpacity * 1.0f)));
            Tmp.setOutlineThickness(-0.1f);
            Texture.draw(Tmp);
        }
}

void TextBox::setTyping(sf::Vector2i MousePos, int Click)
{
    if (mouseOn(MousePos) && Click == 1)
        isTyping = true;
    if (mouseOn(MousePos) && Click == 2)
        isTyping = false;
    if (!mouseOn(MousePos) && Click == 1)
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

void TextBox::drawBlinkCursor(sf::Clock &clock)
{
    if (isTyping)
    {
        if (clock.getElapsedTime().asSeconds() < 1)
        {
            sf::RectangleShape Cursor(sf::Vector2f{1.0, 1.5f * Text.getCharacterSize()});
            Cursor.setOrigin(sf::Vector2f{0.5, 0.75f * Text.getCharacterSize()});
            Cursor.setPosition(sf::Vector2f{Text.getPosition().x + Text.getLocalBounds().width + 1, Rec.getSize().y / 2});
            Cursor.setFillColor(Text.getFillColor());
            Texture.draw(Cursor);
        }
        else
        {
            sf::RectangleShape Cursor(sf::Vector2f{1.0, 1.6f * Text.getCharacterSize()});
            Cursor.setOrigin(sf::Vector2f{0.5, 0.75f * Text.getCharacterSize()});
            Cursor.setPosition(sf::Vector2f{Text.getPosition().x + Text.getLocalBounds().width + 1, Rec.getSize().y / 2});
            Cursor.setFillColor(sf::Color::Transparent);
            Texture.draw(Cursor);
        }
        if (clock.getElapsedTime().asSeconds() > 2)
            clock.restart();
    }
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

void TextBox::drawTexture(sf::Clock &clock)
{
    Texture.create((unsigned int)Rec.getSize().x, (unsigned int)Rec.getSize().y);
    Texture.setSmooth(true);
    Texture.draw(Rec);
    if (EdgeOpacity > 0)
        drawOpacity();
    if (BlinkCursor)
        drawBlinkCursor(clock);
    Texture.draw(Text);
}

void TextBox::setTextColor(sf::Color color)
{
    Text.setFillColor(color);
}
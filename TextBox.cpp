#include <TextBox.hpp>
#include <string>

extern sf::RenderWindow window;

// Constructor ///////////////////////////////////////////////////////////////////////////////////

TextBox::TextBox()
{
    setPosition(0, 0);
    setSize(50.0f, 50.0f);
    setColor();
    setFontSize();
    setTextPos();
    EdgeOpacity = 0;
    AllowTyping = 0;
    HasCaret = 0;
    isTyping = 0;
    Texture.create(50.0f, 50.0f);
    FKey = 0;
    Type = 0;
    id = 0;
    charlength = 1;
    Key = 0;
    limit = INT_MAX;
}

TextBox::TextBox(float a, float b, float w, float h, unsigned int fontsize, sf::Vector2f pos)
{
    setPosition(a, b);
    setSize(w, h);
    setFontSize(fontsize);
    setColor();
    setTextPos(pos);
    EdgeOpacity = 0;
    AllowTyping = 0;
    HasCaret = 0;
    isTyping = 0;
    Texture.create(w, h);
    Rec.setPosition(0, 0);
    FKey = 0;
    Type = 0;
    id = 0;
    charlength = 1;
    Key = 0;
    limit = INT_MAX;
}

// Box ////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TextBox::setPosition(float a, float b)
{
    x = a;
    y = b;
}

void TextBox::setSize(float w, float h)
{
    Rec.setSize(sf::Vector2f(w, h));
}

void TextBox::setColor(sf::Color c1, sf::Color c2)
{
    color1 = c1;
    color2 = c2;
    Rec.setFillColor(sf::Color::White);
    Rec.setOutlineColor(color1);
    Rec.setOutlineThickness(-1.0f);
}

// Text ///////////////////////////////////////////////////////////////////////////////////////////////

void TextBox::setFontSize(unsigned int fontsize)
{
    Text.setCharacterSize(fontsize);
    Text.setOrigin(sf::Vector2f(0, 1.0f * fontsize / 2));
}

void TextBox::setTextPos(float x)
{
    posText = sf::Vector2f(x, 1.0f * Rec.getSize().y / 2);
    Text.setPosition(posText);
}

void TextBox::setTextPos(sf::Vector2f pos)
{
    posText = pos;
    Text.setPosition(posText);
}

void TextBox::setTextColor(sf::Color color)
{
    Text.setFillColor(color);
}

void TextBox::setFont(sf::Font &font)
{
    Text.setFont(font);
}

void TextBox::setText(sf::String S)
{
    Text.setString(S);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////////////////

void TextBox::processEvent(sf::Event event)
{
    if (AllowTyping)
    {
        switch (event.type)
        {
        case sf::Event::MouseButtonPressed:
            Type = Click;
            checkTyping(event);
            updateTypePos();
            drawTexture();
            break;
        case sf::Event::KeyPressed:
            if (isTyping)
            {
                FKey = event.key.code;
                if (FKey == Backspace || FKey == LeftArrow || FKey == RightArrow || FKey == Enter || FKey == Esc)
                {
                    Type = keyPressed;
                    updateText();
                    drawTexture();
                }
            }
            break;
        case sf::Event::TextEntered:
            if (isTyping)
            {
                Type = TextEntered;
                Key = event.text.unicode;
                updateText();
                drawTexture();
            }
            break;
        default:
            break;
        }
    }
    // drawTexture();
}

void TextBox::setTyping()
{
    AllowTyping = 1;
}

void TextBox::setCaret()
{
    HasCaret = 1;
}

sf::RectangleShape TextBox::Caret()
{
    sf::Vector2f CaretSize(sf::Vector2f(1.0f, 1.4f * Text.getCharacterSize()));
    sf::RectangleShape Caret;
    Caret.setSize(CaretSize);
    Caret.setOrigin(0, 0.6f * Text.getCharacterSize());
    Caret.setPosition(sf::Vector2f(1.0f * id * charlength + posText.x, posText.y));
    switch (isTyping)
    {
    case true:
        // Caret.setFillColor(getContrastColor(Text.getFillColor()));
        Caret.setFillColor(Text.getFillColor());
        return Caret;
        break;
    default:
        Caret.setFillColor(sf::Color::White);
        return Caret;
        break;
    }
}

void TextBox::setOpacity(unsigned int thick)
{
    EdgeOpacity = thick;
}

sf::RectangleShape *TextBox::Opacity()
{
    sf::RectangleShape *Tmp;
    Tmp = new sf::RectangleShape[10 * EdgeOpacity];
    if (isTyping)
    {
        for (int i = 0; i < 10 * EdgeOpacity; i++)
        {
            Tmp[i].setSize(sf::Vector2f(Rec.getSize().x - 0.2f * i, Rec.getSize().y - 0.2f * i));
            Tmp[i].setPosition(0.1f * i, 0.1f * i);
            Tmp[i].setFillColor(sf::Color::Transparent);
            float Alpha = 255.f * (10 * (float)EdgeOpacity - (float)i) / (10 * (float)EdgeOpacity);
            Tmp[i].setOutlineColor(sf::Color(color2.r, color2.g, color2.b, Alpha));
            Tmp[i].setOutlineThickness(-0.1f);
        }
    }
    else
        for (int i = 10 * abs(Rec.getOutlineThickness()); i < 10 * EdgeOpacity; i++)
        {
            Tmp[i].setSize(sf::Vector2f(Rec.getSize().x - 0.2f * i, Rec.getSize().y - 0.2f * i));
            Tmp[i].setPosition(0.1f * i, 0.1f * i);
            Tmp[i].setFillColor(sf::Color::Transparent);
            Tmp[i].setOutlineColor(sf::Color::White);
            Tmp[i].setOutlineThickness(-0.1f);
        }
    return Tmp;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(x, y);
    target.draw(sprite);
}

void TextBox::drawTexture()
{
    charlength = (Text.getFont()->getGlyph('A', Text.getCharacterSize(), false)).advance;
    limit = (Rec.getSize().x - posText.x - EdgeOpacity) / charlength;
    Texture.draw(Rec);
    if (EdgeOpacity)
    {
        sf::RectangleShape *Tmp = Opacity();
        for (int i = 0; i < 10 * EdgeOpacity; i++)
            Texture.draw(Tmp[i]);
        delete[] Tmp;
    }
    Texture.draw(Text);
    if (HasCaret)
        Texture.draw(Caret());
    Texture.display();
}

// Private ////////////////////////////////////////////////////////////////////////////////////////////

sf::Vector2i TextBox::getMousePosition()
{
    sf::Mouse mouse;
    return mouse.getPosition(window);
}

bool TextBox::mouseOn(sf::Vector2i MousePos)
{
    if (x <= MousePos.x && MousePos.x <= x + Rec.getSize().x &&
        y <= MousePos.y && MousePos.y <= y + Rec.getSize().y)
        return true;
    return false;
}

void TextBox::checkTyping(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i MousePos = getMousePosition();
        if (event.mouseButton.button == sf::Mouse::Left && mouseOn(MousePos))
            isTyping = true;
        if ((event.mouseButton.button == sf::Mouse::Left && !mouseOn(MousePos)) ||
            event.mouseButton.button == sf::Mouse::Right)
            isTyping = false;
    }
}

sf::Color TextBox::getContrastColor(sf::Color color)
{
    const float Ratio = 8;
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

void TextBox::updateTypePos()
{
    if (Type == Click)
    {
        sf::Vector2i MousePos = getMousePosition();
        int a = (MousePos.x - x - posText.x) / charlength;
        int b = Text.getString().getSize();
        id = a;
        if (a < 0)
            id = 0;
        if (a > b)
            id = b;
        return;
    }
    if (Type == keyPressed)
    {
        if (FKey == LeftArrow)
            id--;
        if (FKey == RightArrow)
            id++;
        if (id < 0)
            id = 0;
        if (id > Text.getString().getSize())
            id = Text.getString().getSize();
        return;
    }
    if (Type == TextEntered && Key != '\b' && Key < 128 && Key != '\n' && Key != '\r')
        id++;
    return;
}

void TextBox::updateText()
{
    if (isTyping)
    {
        if (Type == keyPressed && FKey == Backspace)
        {
            if (id <= 0)
                return;
            std::string S = Text.getString();
            S.erase(id - 1, 1);
            Text.setString(S);
            id--;
            return;
        }
        if (Type == TextEntered && Key < 128 && Key != '\b' && Key != '\n' && Key != '\r')
        {
            if (Text.getString().getSize() < limit)
            {
                sf::String S = Text.getString();
                S.insert(id, (sf::String) static_cast<char>(Key));
                Text.setString(S);
                id++;
            }
            return;
        }
        updateTypePos();
    }
}
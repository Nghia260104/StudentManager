#include <StudentManager.hpp>

extern sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont;
extern sf::RenderWindow window;
extern sf::Color Background;

// Constructor ///////////////////////////////////////////////////////////////////////////////////////////////////

LogIn::LogIn()
{
    // // Background

    // Texture.create(window.getSize().x, window.getSize().y);
    // Texture.setSmooth(true);
    // sf::RectangleShape back((sf::Vector2f)window.getSize());
    // back.setFillColor(Background);
    // Texture.draw(back);

    // // Bound

    // Bound.setSize(sf::Vector2f(800, 400));
    // Bound.setOrigin(400, 200);
    // Bound.setFillColor(Background);
    // Bound.setOutlineColor(sf::Color(25, 89, 34, 255));
    // Bound.setOutlineThickness(1);
    // Bound.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // // Title

    // Title.setString("Log in");
    // Title.setFillColor(sf::Color(25, 89, 34, 255));
    // Title.setFont(RegularFont);
    // Title.setCharacterSize(40);
    // Title.setStyle(sf::Text::Bold);
    // Title.setOrigin(Title.getLocalBounds().width / 2, Title.getLocalBounds().height / 2);
    // Title.setPosition(Bound.getPosition().x, Bound.getPosition().y - 170);

    // Title1.setString("Username: ");
    // Title1.setFillColor(sf::Color::Black);
    // Title1.setFont(RegularFont);
    // Title1.setCharacterSize(15);
    // Title1.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 130);

    // Title2.setString("Password: ");
    // Title2.setFillColor(sf::Color::Black);
    // Title2.setFont(RegularFont);
    // Title2.setCharacterSize(15);
    // Title2.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 30);

    // // Username

    // Username.create(0, 0, 700, 50, 15, sf::Vector2f(8, 25));
    // Username.setCaret();
    // Username.setTyping();
    // Username.setOpacity();
    // Username.setFont(RegularFont);
    // Username.setFillColor(Background);
    // Username.setTextColor();
    // Username.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    // Username.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 100);

    // // Password

    // Password.create(0, 0, 700, 50, 15, sf::Vector2f(8, 25));
    // Password.setCaret();
    // Password.setTyping();
    // Password.setOpacity();
    // Password.setPassword();
    // Password.setFont(RegularFont);
    // Password.setFillColor(Background);
    // Password.setTextColor();
    // Password.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    // Password.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y);
}

void LogIn::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    sf::RectangleShape back((sf::Vector2f)window.getSize());
    back.setFillColor(Background);
    Texture.draw(back);

    // Bound

    Bound.setSize(sf::Vector2f(800, 400));
    Bound.setOrigin(400, 200);
    Bound.setFillColor(Background);
    Bound.setOutlineColor(sf::Color(25, 89, 34, 255));
    Bound.setOutlineThickness(1);
    Bound.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Title

    Title.setString("Log in");
    Title.setFillColor(sf::Color(25, 89, 34, 255));
    Title.setFont(RegularFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setOrigin(Title.getLocalBounds().width / 2, Title.getLocalBounds().height / 2);
    Title.setPosition(Bound.getPosition().x, Bound.getPosition().y - 170);

    Title1.setString("Username: ");
    Title1.setFillColor(sf::Color::Black);
    Title1.setFont(RegularFont);
    Title1.setCharacterSize(15);
    Title1.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 130);

    Title2.setString("Password: ");
    Title2.setFillColor(sf::Color::Black);
    Title2.setFont(RegularFont);
    Title2.setCharacterSize(15);
    Title2.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 30);

    // Username

    Username.create(0, 0, 700, 50, 15, sf::Vector2f(8, 25));
    Username.setCaret();
    Username.setTyping();
    Username.setOpacity();
    Username.setFont(RegularFont);
    Username.setFillColor(Background);
    Username.setTextColor();
    Username.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    Username.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 100);

    // Password

    Password.create(0, 0, 700, 50, 15, sf::Vector2f(8, 25));
    Password.setCaret();
    Password.setTyping();
    Password.setOpacity();
    Password.setPassword();
    Password.setFont(RegularFont);
    Password.setFillColor(Background);
    Password.setTextColor();
    Password.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    Password.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y);

    // First Draw

    FirstDraw();
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////

void LogIn::processEvent(sf::Event event)
{
    Username.processEvent(event);
    Password.processEvent(event);
    drawTexture();
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////

void LogIn::drawTexture()
{
    Texture.draw(Bound);
    Texture.draw(Title);
    Texture.draw(Title1);
    Texture.draw(Username);
    Texture.draw(Title2);
    Texture.draw(Password);
    Texture.display();
}

void LogIn::FirstDraw()
{
    Texture.draw(Bound);
    Texture.draw(Title);
    Texture.draw(Title1);
    Username.drawTexture();
    Texture.draw(Username);
    Texture.draw(Title2);
    Password.drawTexture();
    Texture.draw(Password);
    Texture.display();
}

void LogIn::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}
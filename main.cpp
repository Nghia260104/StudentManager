// #include <SFML/Graphics.hpp>
#include <StudentManager.hpp>
#include <iostream>

class Circle : public sf::Drawable
{
public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Sprite sprite(Texture.getTexture());
        target.draw(sprite, states);
    }

    Circle()
    {
        circle_.setRadius(50.0f);
        Texture.create(200, 200);
        Texture.draw(circle_);
    }

private:
    sf::RenderTexture Texture;
    sf::CircleShape circle_;
    sf::Text text;
};
sf::RenderWindow window;
int Click = 0;
sf::Clock Clock;
sf::Font RegularFont, BoldFont, MediumFont, LightFont, HeavyFont;
sf::Color Background;
sf::Cursor cursor;
LogIn LogInWindow;

// Windows

int main()
{
    // Initialize Window
    window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100),
                  "Student Manager",
                  sf::Style::Default ^ sf::Style::Resize);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    Background = sf::Color::White;

    // Load Fonts
    LoadFonts(RegularFont, BoldFont, MediumFont, LightFont, HeavyFont);

    // Test

    TextBox Test(50, 50, 800, 50, 30, sf::Vector2f(8, 25));
    Test.setCaret();
    Test.setOutlineColor(sf::Color::Black, sf::Color::Cyan);
    Test.setFillColor(sf::Color::Magenta, 8);
    Test.setFont(RegularFont);
    Test.setFontSize(20);
    // Test.setTextColor(sf::Color::Black);
    Test.setOpacity();
    Test.setTyping();
    Test.setText("The quick brown fox jumps over the lazy dog");
    // Test.setPassword();
    // Test.setTextColor(sf::Color::White);

    // LogIn LogInWindow;
    LogInWindow.create();

    ///////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Mouse mouse;
        sf::Vector2i MousePos = mouse.getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
            // Test.processEvent(event);
            LogInWindow.processEvent(event);
        }
        // Circle circle;

        // window.clear(sf::Color::Black);
        // window.draw(circle);
        if (LogInWindow.mouseOn(MousePos))
        {
            cursor.loadFromSystem(sf::Cursor::Text);
            window.setMouseCursor(cursor);
        }
        else
        {
            cursor.loadFromSystem(sf::Cursor::Arrow);
            window.setMouseCursor(cursor);
        }
        window.clear(Background);
        window.draw(LogInWindow);
        window.display();
    }
}
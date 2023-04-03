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
sf::Vector2i MousePos;
sf::Clock clock_;
sf::Font RegularFont, BoldFont, ItalicFont, LightFont, HeavyFont;

int main()
{
    // Initialize Window
    window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100),
                  "Student Manager",
                  sf::Style::Default ^ sf::Style::Resize);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);

    // Load Fonts
    LoadFonts(RegularFont, BoldFont, ItalicFont, LightFont, HeavyFont);

    // Test

    TextBox Test(50, 50, 800, 50, 30, sf::Vector2f(8, 25));
    Test.setCaret();
    Test.setColor(sf::Color::Black, sf::Color::Cyan);
    Test.setFont(RegularFont);
    Test.setFontSize(20);
    Test.setTextColor(sf::Color::Black);
    Test.setOpacity();
    Test.setTyping();
    // Test.setText("The quick brown fox jumps over the lazy dog");
    Test.setPassword();
    // Test.setTextColor(sf::Color::White);

    ///////////////////////////////////////////////////////////////////////////////////////

    Test.drawTexture();
    if (window.isOpen())
        window.draw(Test);
    while (window.isOpen())
    {
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
            Test.processEvent(event);
        }
        // Circle circle;

        // window.clear(sf::Color::Black);
        // window.draw(circle);
        window.clear(sf::Color::White);
        window.draw(Test);
        window.display();
    }
}
// #include <SFML/Graphics.hpp>
#include <StudentManager.hpp>

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
static int Click = 0;
sf::Vector2i MousePos;
sf::Clock clock_;

int main()
{
    // Initialize Window

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100), "Student Manager");
    window.setPosition(sf::Vector2i((int)-window.getSize().x / 192, 0));
    window.setFramerateLimit(60);

    // Load Fonts

    sf::Font RegularFont, BoldFont, ItalicFont, LightFont, HeavyFont;
    LoadFonts(RegularFont, BoldFont, ItalicFont, LightFont, HeavyFont);

    ///////////////////////////////////////////////////////////////////////////////////////

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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                    Click = 1;
                if (event.mouseButton.button == sf::Mouse::Right)
                    Click = 2;
                sf::Mouse mouse;
                MousePos = mouse.getPosition(window);
                clock_.restart();
                break;
            }
        }
        // Circle circle;

        // window.clear(sf::Color::Black);
        // window.draw(circle);
        window.clear(sf::Color::White);
        TextBox Test(20.0f, 20.0f, 100.0f, 50.0f, 15);
        Test.setColor(sf::Color::Black, sf::Color::Green);
        Test.setTyping(MousePos, Click);
        Test.setOpacity();
        Test.setBlinkCursor();
        Test.setMouseCursor(window);
        Test.setText("Tesg");
        Test.setFont(RegularFont);
        Test.setTextColor(sf::Color::Black);
        Test.drawTexture(clock_);
        window.draw(Test);
        // Test.TestDraw(window);
        window.display();
    }
}
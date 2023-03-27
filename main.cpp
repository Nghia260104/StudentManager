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

int main()
{
    // Initialize Window

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Student Manager");
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
            }
        }

        // Circle circle;

        // window.clear(sf::Color::Black);
        // window.draw(circle);
        window.clear(sf::Color::White);
        TextBox Test(20.0f, 20.0f, 100.0f, 50.0f, 15);
        Test.setColor(sf::Color::Black, sf::Color::Green);
        Test.setTyping();
        Test.setOpacity();
        Test.setBlinkCursor();
        Test.setMouseCursor(window);
        Test.setText("Test");
        Test.setFont(RegularFont);
        Test.setTextColor(sf::Color::Black);
        Test.drawTexture();
        window.draw(Test);
        // Test.TestDraw(window);
        window.display();
    }
}
// #include <SFML/Graphics.hpp>
#include <StudentManager.hpp>

class Circle : public sf::Drawable
{
public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(circle_, states);
    }

    Circle()
        : circle_(50.f)
    {}

private:
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

        Circle circle;

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}
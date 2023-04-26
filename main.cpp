// #include <SFML/Graphics.hpp>
#include <StudentManager.hpp>
#include <FrontendGlobal.hpp>
#include <Password.hpp>
#include <CoursesTable.hpp>
#include <StudentWindow.hpp>

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

// Windows
PasswordWindow TestWindow;
CoursesTable Test12;
StudentWindow Test20;
Page pages;
extern List<Backend::Course *> list;

int main()
{
    // Initialize Window
    window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100),
                  "Student Manager",
                  sf::Style::Default ^ sf::Style::Resize);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    LeftWindowWidth = (window.getSize().x * 4) / 5;
    RightWindowWidth = window.getSize().x - LeftWindowWidth;
    BackgroundColor = sf::Color::White;

    // Load Fonts
    LoadFonts(RegularFont, BoldFont, MediumFont, LightFont, HeavyFont);

    // Test

    // for (int i = 0; i < 25; i++)
    // {
    //     Backend::Course *Tmp = new Backend::Course;
    //     list.push_back(Tmp);
    // }

    // LogIn LogInWindow;
    LogInWindow.create();

    // Student Window
    StudentScreen.create();

    // Admin Window
    AdminScreen.create();

    // Password Window
    TestWindow.create();

    List<Backend::Course *> Tmp;
    Backend::Course *Tmp1;
    Tmp1 = new Backend::Course;
    Tmp1->setID("22125066");
    Tmp1->setMaxStudents(40);
    Tmp.push_back(Tmp1);
    // Test12.setFont(RegularFont);
    Test12.create(RegularFont);
    Test12.drawTexture(Tmp, 1);
    Test12.setPosition(100, 100);

    pages.create();
    pages.setPosition(Test12.getPosition().x + 577, Test12.getPosition().y + Test12.getHeight() + 20);
    pages.drawTexture();

    // Test20.create();

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
            if (!LogInWindow.isHidden())
                LogInWindow.processEvent(event);
            if (!StudentScreen.isHidden())
                StudentScreen.processEvent(event);
            if (!AdminScreen.isHidden())
                AdminScreen.processEvent(event);
            // TestWindow.processEvent(event);
            // Test20.processEvent(event);
        }
        // Circle circle;

        // window.clear(sf::Color::Black);
        // window.draw(circle);
        // if (TestWindow.mouseOn(MousePos))
        // {
        //     cursor.loadFromSystem(sf::Cursor::Text);
        //     window.setMouseCursor(cursor);
        // }
        // else
        // {
        //     cursor.loadFromSystem(sf::Cursor::Arrow);
        //     window.setMouseCursor(cursor);
        // }
        window.clear(BackgroundColor);
        // window.clear(sf::Color::Yellow);
        if (!LogInWindow.isHidden())
            window.draw(LogInWindow);
        if (!StudentScreen.isHidden())
            window.draw(StudentScreen);
        if (!AdminScreen.isHidden())
            window.draw(AdminScreen);
        // window.draw(TestWindow);
        // window.draw(Test12);
        // window.draw(pages);
        window.display();
    }
}
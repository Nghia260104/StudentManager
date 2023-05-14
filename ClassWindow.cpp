#include <ClassWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <string>

// Constructor ///////////////////////////////////////////////////////////////////////////////////////

ClassWindow::ClassWindow()
{
}

void ClassWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Class");
    Title.setFillColor(TextColor);
    Title.setFont(Over);
    Title.setCharacterSize(40);
    // Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Create

    Create.create(200, 200, 250, 75, BoldFont, 36, "Create");
    Create.setFillColor(ButtonColor);
    Create.setTextColor(BackgroundColor);
    Create.setCoverColor(ButtonCoverColor);
    Create.setOutline(ButtonColor);

    //// Add Title

    Add.setString("Create class");
    Add.setFillColor(TextColor);
    Add.setFont(Over);
    Add.setCharacterSize(40);
    // Add.setStyle(sf::Text::Bold);
    Add.setPosition(100, 100);

    // Remove

    Remove.create(200, 325, 250, 75, BoldFont, 36, "Remove");
    Remove.setFillColor(ButtonColor);
    Remove.setTextColor(BackgroundColor);
    Remove.setCoverColor(ButtonCoverColor);
    Remove.setOutline(ButtonColor);

    //// Remove Title

    Delete.setString("Remove class");
    Delete.setFillColor(TextColor);
    Delete.setFont(Over);
    Delete.setCharacterSize(40);
    // Delete.setStyle(sf::Text::Bold);
    Delete.setPosition(100, 100);

    // Class Name

    Name.setString("Class name:");
    Name.setFillColor(sf::Color::Black);
    Name.setFont(LightFont);
    Name.setCharacterSize(18);
    Name.setStyle(sf::Text::Bold);
    Name.setPosition(200, 235);

    ClassName.create(0, 0, 150, 50, 24, sf::Vector2f(8, 25));
    ClassName.setCaret();
    ClassName.setTyping();
    ClassName.setOpacity();
    ClassName.setFont(RegularFont);
    ClassName.setFillColor(BackgroundColor);
    ClassName.setTextColor();
    ClassName.setOutlineColor(sf::Color(25, 89, 34, 255), ButtonColor);
    ClassName.setPosition(350, 235);

    // Empty class

    Empty.setFont(RegularFont);
    Empty.setCharacterSize(20);
    Empty.setFillColor(sf::Color(168, 30, 20, 255));
    Empty.setString("Failed: Class name can not be empty!");
    Empty.setPosition(250, 315);

    // Existed class

    Exist.setFont(RegularFont);
    Exist.setCharacterSize(20);
    Exist.setFillColor(sf::Color(168, 30, 20, 255));
    Exist.setString("Failed: Class existed!");
    Exist.setPosition(250, 315);

    // Not found class

    Fail.setFont(RegularFont);
    Fail.setCharacterSize(20);
    Fail.setFillColor(sf::Color(168, 30, 20, 255));
    Fail.setString("Failed: Class not found!");
    Fail.setPosition(250, 315);

    // Add Successfully

    ASuccess.setFont(RegularFont);
    ASuccess.setCharacterSize(20);
    ASuccess.setFillColor(sf::Color(144, 212, 58, 255));
    ASuccess.setString("Create class successfully!");
    ASuccess.setPosition(250, 315);

    // Delete Successfully

    DSuccess.setFont(RegularFont);
    DSuccess.setCharacterSize(20);
    DSuccess.setFillColor(sf::Color(144, 212, 58, 255));
    DSuccess.setString("Remove class successfully!");
    DSuccess.setPosition(250, 315);

    // Confirm button

    Confirm.create(325, 380, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(ButtonColor);
    Confirm.setTextColor(BackgroundColor);
    Confirm.setCoverColor(ButtonCoverColor);
    Confirm.setOutline(ButtonColor);

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////

void ClassWindow::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Create.drawTexture();
    Texture.draw(Create);
    Remove.drawTexture();
    Texture.draw(Remove);
    ClassName.drawTexture();
    Confirm.drawTexture();
    Texture.display();
}

void ClassWindow::drawTexture(Layer &layer)
{
    Texture.draw(Background);
    if (layer == Cls)
    {
        Texture.draw(Title);
        Texture.draw(Create);
        Texture.draw(Remove);
    }
    if (layer == ACls)
    {
        Texture.draw(Add);
        Texture.draw(Name);
        Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (fail == emptyname)
            Texture.draw(Empty);
        if (fail == existed)
            Texture.draw(Exist);
        if (!fail)
            Texture.draw(ASuccess);
    }
    if (layer == DCls)
    {
        Texture.draw(Delete);
        Texture.draw(Name);
        Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (fail == notFound)
            Texture.draw(Fail);
        if (!fail)
            Texture.draw(DSuccess);
    }
    Texture.display();
}

void ClassWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Cls)
    {
        drawTexture(layer);
        Texture.draw(Create);
        Texture.draw(Remove);
        if (Create.isPressed(event))
        {
            layer = ACls;
            clearLine();
            drawTexture(layer);
            return;
        }
        if (Remove.isPressed(event))
        {
            layer = DCls;
            clearLine();
            drawTexture(layer);
            return;
        }
    }
    if (layer == ACls)
    {
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (ClassName.getText() == "")
                fail = emptyname;
            else if (!Backend::Class::createClass(ClassName.getText()))
                fail = existed;
            drawTexture(layer);
        }
    }
    if (layer == DCls)
    {
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!Backend::Class::deleteClass(ClassName.getText()))
                fail = notFound;
            drawTexture(layer);
        }
    }
}

bool ClassWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == ACls || layer == DCls)
        return (ClassName.mouseOn(MousePos));
    return false;
}

void ClassWindow::clearLine()
{
    fail = Clear;
    ClassName.erase();
}
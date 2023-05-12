#include <AddStaffMember.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

AddStaffMember::AddStaffMember()
{
}

void AddStaffMember::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Add Staff member");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Subtitle

    Subtitle.setFillColor(sf::Color::Black);
    Subtitle.setFont(RegularFont);
    Subtitle.setCharacterSize(20);
    Subtitle.setString("Social ID (Username):");
    Subtitle.setPosition(200, 200);

    Username.create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
    Username.setPosition(200, 235);
    Username.setNumber();
    Username.setCaret();
    Username.setTyping();
    Username.setOpacity();
    Username.setFont(RegularFont);
    Username.setFillColor(BackgroundColor);
    Username.setTextColor();
    Username.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);

    // Fail type 1 : Empty cell

    Fail1.setFont(RegularFont);
    Fail1.setCharacterSize(20);
    Fail1.setFillColor(sf::Color(168, 30, 20, 255));
    Fail1.setString("Failed: Cells can not be empty!");
    Fail1.setPosition(250, 300);

    // Fail type 2 : Staff existed

    Fail2.setFont(RegularFont);
    Fail2.setCharacterSize(20);
    Fail2.setFillColor(sf::Color(168, 30, 20, 255));
    Fail2.setString("Failed: Staff member existed!");
    Fail2.setPosition(250, 300);

    // Success

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(144, 212, 58, 255));
    Success.setString("Add Staff member successfully!");
    Success.setPosition(250, 300);

    // Confirm Button

    Confirm.create(300, 340, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////////////

void AddStaffMember::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle);
    Texture.draw(Username);
    if (fail == 0)
        Texture.draw(Success);
    if (fail == empty)
        Texture.draw(Fail1);
    if (fail == existed)
        Texture.draw(Fail2);
    Texture.draw(Confirm);
    Texture.display();
}

void AddStaffMember::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle);
    Username.drawTexture();
    Texture.draw(Username);
    Confirm.drawTexture();
    Texture.draw(Confirm);
    Texture.display();
}

void AddStaffMember::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////

void AddStaffMember::processEvent(sf::Event event)
{
    if (Username.checkEvent(event))
        Texture.draw(Username);
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        if (!Username.getText().getSize())
            fail = empty;
        else if (!Backend::StaffMember::createStaffMember(Username.getText()))
            fail = existed;
        drawTexture();
    }
}

bool AddStaffMember::mouseOn(const sf::Vector2i &MousePos)
{
    return Username.mouseOn(MousePos);
}

void AddStaffMember::setMouseCursor(const sf::Vector2i &MousePos)
{
    sf::Cursor cursor;
    if (mouseOn(MousePos))
    {
        cursor.loadFromSystem(sf::Cursor::Text);
        window.setMouseCursor(cursor);
    }
}

void AddStaffMember::clearLine()
{
    fail = Clear;
    Username.erase();
    drawTexture();
}
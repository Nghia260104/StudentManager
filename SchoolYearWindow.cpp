#include <SchoolYearWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <string>

// Constructor ///////////////////////////////////////////////////////////////////////////////////////

SchoolYearWindow::SchoolYearWindow()
{
}

void SchoolYearWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("School year");
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

    Add.setString("Create school year");
    Add.setFillColor(TextColor);
    Add.setFont(Over);
    Add.setCharacterSize(40);
    // Add.setStyle(sf::Text::Bold);
    Add.setPosition(100, 100);

    // Remove

    Remove.create(200, 325, 250, 75, BoldFont, 36, "Delete");
    Remove.setFillColor(ButtonColor);
    Remove.setTextColor(BackgroundColor);
    Remove.setCoverColor(ButtonCoverColor);
    Remove.setOutline(ButtonColor);

    //// Remove Title

    Delete.setString("Delete School Year");
    Delete.setFillColor(TextColor);
    Delete.setFont(Over);
    Delete.setCharacterSize(40);
    // Delete.setStyle(sf::Text::Bold);
    Delete.setPosition(100, 100);

    // Start year

    FirstYear.setString("Start year:");
    FirstYear.setFillColor(sf::Color::Black);
    FirstYear.setFont(LightFont);
    FirstYear.setCharacterSize(18);
    FirstYear.setStyle(sf::Text::Bold);
    FirstYear.setPosition(200, 235);

    Start.create(0, 0, 100, 50, 24, sf::Vector2f(8, 25));
    Start.setCaret();
    Start.setTyping();
    Start.setOpacity();
    Start.setFont(RegularFont);
    Start.setFillColor(BackgroundColor);
    Start.setTextColor();
    Start.setOutlineColor(sf::Color(25, 89, 34, 255), ButtonColor);
    Start.setPosition(350, 235);
    Start.setNumber();
    Start.setLimit(4);

    // Fail

    Fail.setFont(RegularFont);
    Fail.setCharacterSize(20);
    Fail.setFillColor(sf::Color(168, 30, 20, 255));
    Fail.setString("Failed: Invalid school year!");
    Fail.setPosition(235, 315);

    // School year existed

    Fail2.setFont(RegularFont);
    Fail2.setCharacterSize(20);
    Fail2.setFillColor(sf::Color(168, 30, 20, 255));
    Fail2.setString("Failed: School year existed!");
    Fail2.setPosition(235, 315);

    // Not found school year

    Fail1.setFont(RegularFont);
    Fail1.setCharacterSize(20);
    Fail1.setFillColor(sf::Color(168, 30, 20, 255));
    Fail1.setString("Failed: School year not found!");
    Fail1.setPosition(235, 315);

    // Add Successfully

    ASuccess.setFont(RegularFont);
    ASuccess.setCharacterSize(20);
    ASuccess.setFillColor(sf::Color(144, 212, 58, 255));
    ASuccess.setString("Create school year successfully!");
    ASuccess.setPosition(235, 315);

    // Delete Successfully

    DSuccess.setFont(RegularFont);
    DSuccess.setCharacterSize(20);
    DSuccess.setFillColor(sf::Color(144, 212, 58, 255));
    DSuccess.setString("Delete school year successfully!");
    DSuccess.setPosition(235, 315);

    // Confirm button

    Confirm.create(325, 375, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(ButtonColor);
    Confirm.setTextColor(BackgroundColor);
    Confirm.setCoverColor(ButtonCoverColor);
    Confirm.setOutline(ButtonColor);

    // First Draw

    FirstDraw();

    // Setup

    check = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////

void SchoolYearWindow::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Create.drawTexture();
    Texture.draw(Create);
    Remove.drawTexture();
    Texture.draw(Remove);
    Start.drawTexture();
    Confirm.drawTexture();
    Texture.display();
}

void SchoolYearWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == ScY)
    {
        Texture.draw(Title);
        Texture.draw(Create);
        Texture.draw(Remove);
    }
    if (layer == AScY)
    {
        Texture.draw(Add);
        Texture.draw(FirstYear);
        Texture.draw(Start);
        Texture.draw(Confirm);
        if (check == fail)
            Texture.draw(Fail);
        if (check == existed)
            Texture.draw(Fail2);
        if (check == done)
            Texture.draw(ASuccess);
    }
    if (layer == DScY)
    {
        Texture.draw(Delete);
        Texture.draw(FirstYear);
        Texture.draw(Start);
        Texture.draw(Confirm);
        if (check == fail)
            Texture.draw(Fail);
        if (check == notFound)
            Texture.draw(Fail1);
        if (check == done)
            Texture.draw(DSuccess);
    }
    Texture.display();
}

void SchoolYearWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////

void SchoolYearWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == ScY)
    {
        drawTexture(layer);
        Texture.draw(Create);
        Texture.draw(Remove);
        if (Create.isPressed(event))
        {
            layer = AScY;
            clearLine();
            drawTexture(layer);
            return;
        }
        if (Remove.isPressed(event))
        {
            layer = DScY;
            clearLine();
            drawTexture(layer);
            return;
        }
    }
    if (layer == AScY)
    {
        if (Start.checkEvent(event))
            Texture.draw(Start);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            check = done;
            if (Start.getText() == "")
                check = fail;
            else if (!Backend::SchoolYear::createSchoolYear(std::stoi((std::string)Start.getText())))
                check = existed;
            else
                Backend::setActiveSchoolYear(&(Backend::g_schoolYears.back()));
            drawTexture(layer);
        }
    }
    if (layer == DScY)
    {
        if (Start.checkEvent(event))
            Texture.draw(Start);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            check = done;
            if (Start.getText() == "")
                check = fail;
            else if (!Backend::SchoolYear::deleteSchoolYear(std::stoi((std::string)Start.getText())))
                check = notFound;
            else if (Backend::g_schoolYears.empty())
                Backend::activeSchoolYear = nullptr;
            else
                Backend::activeSchoolYear = &Backend::g_schoolYears.back();
            drawTexture(layer);
        }
    }
}

bool SchoolYearWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == AScY || layer == DScY)
        return (Start.mouseOn(MousePos));
    return false;
}

void SchoolYearWindow::clearLine()
{
    check = Clear;
    Start.erase();
}
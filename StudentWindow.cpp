#include <StudentWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

// Constructor ///////////////////////////////////////////////////////////////////////////////

StudentWindow::StudentWindow()
{
}

void StudentWindow::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(LeftWindowWidth, window.getSize().y));
    Background.setFillColor(BackgroundColor);

    // Back Button

    Back.create(0, 0, 60, 40, BoldFont, 30, "<");
    Back.setFillColor(ButtonColor);
    Back.setTextColor(BackgroundColor);
    Back.setCoverColor(ButtonCoverColor);
    Back.setOutline(ButtonColor);
    Back.setTextPos(16);

    // Home // sf::Color(9, 66, 55, 255)
    //// View Course Button

    viewCourse.create(150, 150, 300, 75, BoldFont, 30, "View Courses");
    viewCourse.setFillColor(ButtonColor);
    viewCourse.setTextColor(BackgroundColor);
    viewCourse.setCoverColor(ButtonCoverColor);

    //// View Scoreboard Button

    viewScoreboard.create(150, 250, 300, 75, BoldFont, 30, "View Scoreboard");
    viewScoreboard.setFillColor(ButtonColor);
    viewScoreboard.setTextColor(BackgroundColor);
    viewScoreboard.setCoverColor(ButtonCoverColor);

    // Account Window
    //// Rectangle

    RightSide.setSize(sf::Vector2f(RightWindowWidth, window.getSize().y));
    RightSide.setFillColor(RightSideColor);
    RightSide.setPosition(LeftWindowWidth, 0);

    //// Name

    AccountName.setPosition(LeftWindowWidth + 25, 50);
    AccountName.setFillColor(TextColor);
    AccountName.setString("Temp"); // Backend::activeUser->getName();
    AccountName.setFont(Calibri);

    //// View Profile Button

    viewProfile.create(LeftWindowWidth + 72, 150, 250, 50, MediumFont, 24, "View Profile");
    viewProfile.setFillColor(TextColor);
    viewProfile.setCoverColor(TextCoverColor);
    viewProfile.setTextColor(BackgroundColor);
    viewProfile.setOutline(TextColor);

    //// Change Password Button

    changePassword.create(LeftWindowWidth + 72, 225, 250, 50, MediumFont, 24, "Change Password");
    changePassword.setFillColor(TextColor);
    changePassword.setCoverColor(TextCoverColor);
    changePassword.setTextColor(BackgroundColor);
    changePassword.setOutline(TextColor);

    //// Log out Button

    LogOut.create(LeftWindowWidth + 72, 300, 250, 50, MediumFont, 24, "Log out");
    LogOut.setFillColor(TextColor);
    LogOut.setCoverColor(TextCoverColor);
    LogOut.setTextColor(BackgroundColor);
    LogOut.setOutline(TextColor);

    // View Course Window

    Courses.create(RegularFont);
    Courses.setPosition(100, 75);

    // View Scoreboard Window

    Scoreboard.create(RegularFont);
    Scoreboard.setPosition(100, 75);

    // Change Password Window

    Password.create();

    // Profile window

    profile.create();

    // Pages Button

    pages.create();

    // First Draw

    // FirstDraw();

    // Setup

    hidden = 1;
    layer.lvl = Home;
    NumPage = 0;
    TotalPage = 0;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////

void StudentWindow::FirstDraw()
{
    Texture.draw(Background);
    Back.drawTexture();
    // Texture.draw(Back);
    viewCourse.drawTexture();
    Texture.draw(viewCourse);
    viewScoreboard.drawTexture();
    Texture.draw(viewScoreboard);
    Texture.draw(RightSide);
    Texture.draw(AccountName);
    viewProfile.drawTexture();
    Texture.draw(viewProfile);
    changePassword.drawTexture();
    Texture.draw(changePassword);
    LogOut.drawTexture();
    Texture.draw(LogOut);
    Texture.display();
}

void StudentWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(viewProfile);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
    if (layer.lvl == Home)
    {
        Texture.draw(viewCourse);
        Texture.draw(viewScoreboard);
    }
    if (layer.lvl == Function && layer.type == Crs)
    {
        Texture.draw(Courses);
        Texture.draw(pages);
    }
    if (layer.lvl == Function && layer.type == Scb)
    {
        Texture.draw(Scoreboard);
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Texture.draw(Password);
    }
    if (layer.lvl == Function && layer.type == Prf)
    {
        Texture.draw(profile);
    }
    if (layer.lvl)
        Texture.draw(Back);
}

void StudentWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////

void StudentWindow::processEvent(sf::Event event)
{
    if (LogOut.isPressed(event))
    {
        layer.lvl = 0;
        layer.type = 0;
        drawTexture();
        Backend::activeUser->logOut();
        Hide();
        LogInWindow.show();
    }
    if (changePassword.isPressed(event))
    {
        layer.lvl = Function;
        layer.type = Pass;
        Password.clearLine();
        drawTexture();
    }
    if (viewProfile.isPressed(event))
    {
        layer.lvl = Function;
        layer.type = Prf;
        profile.drawTexture();
        drawTexture();
    }
    if (layer.lvl && (Back.isPressed(event) || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        // if (layer.lvl == Function && layer.type == Pass)
        //     Password.clearLine();
        // if (layer.lvl)
        layer.lvl--;
        drawTexture();
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Password.processEvent(event);
        Texture.draw(Password);
    }
    if (layer.lvl)
        Texture.draw(Back);
    if (layer.lvl == Home)
    {
        Texture.draw(viewCourse);
        Texture.draw(viewScoreboard);
        if (viewCourse.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Crs;
            NumPage = 1;
            TotalPage = ((courseInfos->size()) ? (courseInfos->size() / MAX_ROW + (bool)(courseInfos->size() % MAX_ROW)) : 1);
            Courses.drawTexture(*courseInfos, 1);
            pages.setPage(NumPage, TotalPage);
            pages.setPosition(607 + Courses.getPosition().x, Courses.getPosition().y + Courses.getHeight() + 20);
            drawTexture();
        }
        if (viewScoreboard.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Scb;
            NumPage = 1;
            TotalPage = ((courseInfos->size()) ? (courseInfos->size() / MAX_ROW + (bool)(courseInfos->size() % MAX_ROW)) : 1);
            Scoreboard.drawTexture(*courseInfos, 1);
            pages.setPage(NumPage, TotalPage);
            pages.setPosition(520 + Scoreboard.getPosition().x, Scoreboard.getPosition().y + Scoreboard.getHeight() + 20);
            drawTexture();
        }
    }
    if (layer.lvl == Function && layer.type == Crs)
    {
        bool Check = 0;
        pages.processEvent(event, NumPage, TotalPage, Check);
        // if (pages.isPressed(event, NumPage, TotalPage))
        if (Check)
        {
            Courses.drawTexture(*courseInfos, NumPage);
            drawTexture();
        }
        Texture.draw(pages);
    }
    if (layer.lvl == Function && layer.type == Scb)
    {
        bool Check = 0;
        pages.processEvent(event, NumPage, TotalPage, Check);
        // if (pages.isPressed(event, NumPage, TotalPage))
        if (Check)
        {
            Scoreboard.drawTexture(*courseInfos, NumPage);
            drawTexture();
        }
        Texture.draw(pages);
    }
    Texture.draw(viewProfile);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
}

bool StudentWindow::mouseOn(const sf::Vector2i &MousePos)
{
    if (!hidden)
    {
        if (layer.lvl == Function && layer.type == Pass)
            return Password.mouseOn(MousePos);
    }
    return false;
}

void StudentWindow::Show()
{
    AccountName.setString(Backend::activeUser->getName());
    courseInfos = &dynamic_cast<Backend::Student *>(Backend::activeUser)->courseInfos();
    FirstDraw();
    hidden = 0;
}

void StudentWindow::Hide()
{
    hidden = 1;
}

bool StudentWindow::isHidden()
{
    return hidden;
}
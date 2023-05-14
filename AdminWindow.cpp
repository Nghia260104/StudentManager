#include <AdminWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

AdminWindow::AdminWindow()
{
}

void AdminWindow::create()
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
    //// Add Staff members

    AddStaff.create(150, 150, 450, 75, BoldFont, 30, "Add Staff Member");
    AddStaff.setFillColor(ButtonColor);
    AddStaff.setTextColor(BackgroundColor);
    AddStaff.setCoverColor(ButtonCoverColor);
    AddStaff.setOutline(ButtonColor);

    //// Delete Staff members

    DeleteStaff.create(150, 250, 450, 75, BoldFont, 30, "Delete Staff Member");
    DeleteStaff.setFillColor(ButtonColor);
    DeleteStaff.setTextColor(BackgroundColor);
    DeleteStaff.setCoverColor(ButtonCoverColor);
    DeleteStaff.setOutline(ButtonColor);

    ////// Add Staff Window

    AddWindow.create();

    ////// Delete Staff Window

    DeleteWindow.create();

    // Account Window
    //// Rectangle

    RightSide.setSize(sf::Vector2f(RightWindowWidth, window.getSize().y));
    RightSide.setFillColor(RightSideColor);
    RightSide.setPosition(LeftWindowWidth, 0);

    //// Name

    AccountName.setPosition(LeftWindowWidth + 25, 50);
    AccountName.setFillColor(TextColor);
    AccountName.setString("Admin");
    AccountName.setFont(Calibri);

    //// Change Password Button

    changePassword.create(LeftWindowWidth + 72, 150, 250, 50, MediumFont, 24, "Change password");
    changePassword.setFillColor(TextColor);
    changePassword.setCoverColor(TextCoverColor);
    changePassword.setTextColor(BackgroundColor);
    changePassword.setOutline(TextColor);

    //// Log out Button

    LogOut.create(LeftWindowWidth + 72, 225, 250, 50, MediumFont, 24, "Log out");
    LogOut.setFillColor(TextColor);
    LogOut.setCoverColor(TextCoverColor);
    LogOut.setTextColor(BackgroundColor);
    LogOut.setOutline(TextColor);

    // Change Password Window

    Password.create();

    // First Draw

    FirstDraw();

    // Setup

    hidden = 1;
    layer.lvl = Home;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////

void AdminWindow::FirstDraw()
{
    Texture.draw(Background);
    Back.drawTexture();
    AddStaff.drawTexture();
    Texture.draw(AddStaff);
    DeleteStaff.drawTexture();
    Texture.draw(DeleteStaff);
    Texture.draw(RightSide);
    Texture.draw(AccountName);
    changePassword.drawTexture();
    Texture.draw(changePassword);
    LogOut.drawTexture();
    Texture.draw(LogOut);
    Texture.display();
}

void AdminWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
    if (layer.lvl == Home)
    {
        Texture.draw(AddStaff);
        Texture.draw(DeleteStaff);
    }
    if (layer.lvl == Function && layer.type == Add)
    {
        Texture.draw(AddWindow);
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Texture.draw(Password);
    }
    if (layer.lvl == Function && layer.type == Delete)
    {
        Texture.draw(DeleteWindow);
    }
    if (layer.lvl)
        Texture.draw(Back);
}

void AdminWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc /////////////////////////////////////////////////////////////////////////////////////////////

void AdminWindow::processEvent(sf::Event event)
{
    if (layer.lvl)
        Texture.draw(Back);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
    if (LogOut.isPressed(event))
    {
        layer.lvl = 0;
        layer.type = 0;
        drawTexture();
        Hide();
        Backend::activeUser->logOut();
        LogInWindow.show();
    }
    if (changePassword.isPressed(event))
    {
        layer.lvl = Function;
        layer.type = Pass;
        Password.clearLine();
        drawTexture();
    }
    if (layer.lvl && (Back.isPressed(event) || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        layer.lvl--;
        drawTexture();
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Password.processEvent(event);
        Texture.draw(Password);
    }
    if (layer.lvl == Function && layer.type == Add)
    {
        AddWindow.processEvent(event);
        Texture.draw(AddWindow);
    }
    if (layer.lvl == Function && layer.type == Delete)
    {
        DeleteWindow.processEvent(event);
        Texture.draw(DeleteWindow);
    }
    if (layer.lvl == Home)
    {
        Texture.draw(AddStaff);
        Texture.draw(DeleteStaff);
        if (AddStaff.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Add;
            AddWindow.clearLine();
            drawTexture();
        }
        if (DeleteStaff.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Delete;
            DeleteWindow.clearLine();
            drawTexture();
        }
    }
    if (layer.lvl)
        Texture.draw(Back);
}

bool AdminWindow::mouseOn(const sf::Vector2i &MousePos)
{
    if (!hidden)
    {
        if (layer.lvl == Function && layer.type == Add)
            return AddWindow.mouseOn(MousePos);
        if (layer.lvl == Function && layer.type == Pass)
            return Password.mouseOn(MousePos);
        if (layer.lvl == Function && layer.type == Delete)
            return DeleteWindow.mouseOn(MousePos);
    }
    return false;
}

void AdminWindow::Show()
{
    hidden = 0;
}

void AdminWindow::Hide()
{
    hidden = 1;
}

bool AdminWindow::isHidden()
{
    return hidden;
}
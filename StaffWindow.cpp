#include <StaffWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

// Constructor /////////////////////////////////////////////////////////////////////////////

StaffWindow::StaffWindow()
{
}

void StaffWindow::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(LeftWindowWidth, window.getSize().y));
    Background.setFillColor(BackgroundColor);

    // Back Button

    Back.create(0, 0, 60, 40, RegularFont, 25, "<-");
    Back.setFillColor(sf::Color(60, 60, 60, 255));
    Back.setTextColor(sf::Color::White);
    Back.setCoverColor(sf::Color(55, 55, 55, 200));
    Back.setTextPos(16);

    // School Year

    SchoolYear.create(150, 150, 300, 75, BoldFont, 30, "School year");
    SchoolYear.setFillColor(sf::Color(9, 66, 55, 255));
    SchoolYear.setTextColor(sf::Color::White);
    SchoolYear.setCoverColor(sf::Color(30, 100, 70, 200));

    //// School Year window

    SchoolYearScreen.create();

    // Semester

    Semester.create(150, 250, 300, 75, BoldFont, 30, "Semester");
    Semester.setFillColor(sf::Color(9, 66, 55, 255));
    Semester.setTextColor(sf::Color::White);
    Semester.setCoverColor(sf::Color(30, 100, 70, 200));

    //// Semester window

    SemesterScreen.create();

    // Add Course

    addCourse.create(150, 350, 300, 75, BoldFont, 30, "Create course");
    addCourse.setFillColor(sf::Color(9, 66, 55, 255));
    addCourse.setTextColor(sf::Color::White);
    addCourse.setCoverColor(sf::Color(30, 100, 70, 200));

    //// Course window

    AddCourseScreen.create();

    // Class

    Class.create(500, 150, 300, 75, BoldFont, 30, "Class");
    Class.setFillColor(sf::Color(9, 66, 55, 255));
    Class.setTextColor(sf::Color::White);
    Class.setCoverColor(sf::Color(30, 100, 70, 200));

    //// Class window

    ClassScreen.create();

    // Add student

    Student.create(500, 250, 300, 75, BoldFont, 30, "Students");
    Student.setFillColor(sf::Color(9, 66, 55, 255));
    Student.setTextColor(sf::Color::White);
    Student.setCoverColor(sf::Color(30, 100, 70, 200));

    //// Add student window

    SetStudentScreen.create();

    // Account Window
    //// Rectangle

    RightSide.setSize(sf::Vector2f(RightWindowWidth, window.getSize().y));
    RightSide.setFillColor(sf::Color(9, 66, 55, 255));
    RightSide.setPosition(LeftWindowWidth, 0);

    //// Name

    AccountName.setPosition(LeftWindowWidth + 25, 50);
    AccountName.setFillColor(sf::Color(248, 117, 26, 255));
    AccountName.setString("Staff member"); // Backend::activeUser->getName();
    AccountName.setFont(RegularFont);

    // //// View Profile

    // {
    //     // Button
    //     viewProfile.create(LeftWindowWidth + 72, 150, 250, 50, RegularFont, 24, "View Profile");
    //     viewProfile.setFillColor(sf::Color(248, 117, 26, 255));
    //     viewProfile.setCoverColor(sf::Color(240, 110, 20, 200));
    //     viewProfile.setTextColor(sf::Color(9, 66, 55, 255));

    //     // Window
    //     profile.create();
    // }

    //// Change Password

    {
        // Button
        {
            changePassword.create(LeftWindowWidth + 72, 225, 250, 50, RegularFont, 24, "Change Password");
            changePassword.setFillColor(sf::Color(248, 117, 26, 255));
            changePassword.setCoverColor(sf::Color(240, 110, 20, 200));
            changePassword.setTextColor(sf::Color(9, 66, 55, 255));
        }

        // Window
        Password.create();
    }

    //// Log out Button

    LogOut.create(LeftWindowWidth + 72, 300, 250, 50, MediumFont, 24, "Log out");
    LogOut.setFillColor(sf::Color(248, 117, 26, 255));
    LogOut.setCoverColor(sf::Color(240, 110, 20, 200));
    LogOut.setTextColor(sf::Color(9, 66, 55, 255));

    // View class
    {
        // Button

        viewClass.create(LeftWindowWidth + 72, 450, 250, 50, MediumFont, 24, "View classes");
        viewClass.setFillColor(sf::Color(248, 117, 26, 255));
        viewClass.setCoverColor(sf::Color(240, 110, 20, 200));
        viewClass.setTextColor(sf::Color(9, 66, 55, 255));

        // View Class window

        ViewClassScreen.create();
    }

    // View Course
    {
        // Button
        {
            viewCourse.create(LeftWindowWidth + 72, 525, 250, 50, MediumFont, 24, "View courses");
            viewCourse.setFillColor(sf::Color(248, 117, 26, 255));
            viewCourse.setCoverColor(sf::Color(240, 110, 20, 200));
            viewCourse.setTextColor(sf::Color(9, 66, 55, 255));
        }

        // View Course Window

        ViewCourseScreen.create();
    }

    // First Draw

    FirstDraw();

    // Setup

    hidden = 1;
    layer = Layer(0, 0);
}

// Draw ///////////////////////////////////////////////////////////////////////////////////////////

void StaffWindow::FirstDraw()
{
    Back.drawTexture();
    SchoolYear.drawTexture();
    Texture.draw(SchoolYear);
    Class.drawTexture();
    Texture.draw(Class);
    Semester.drawTexture();
    Student.drawTexture();
    addCourse.drawTexture();
    Texture.draw(RightSide);
    Texture.draw(AccountName);
    changePassword.drawTexture();
    Texture.draw(changePassword);
    // viewProfile.drawTexture();
    // Texture.draw(viewProfile);
    LogOut.drawTexture();
    Texture.draw(LogOut);
    viewClass.drawTexture();
    Texture.draw(viewClass);
    viewCourse.drawTexture();
    Texture.draw(viewCourse);
    Texture.display();
}

void StaffWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
    Texture.draw(viewClass);
    Texture.draw(viewCourse);
    // Texture.draw(RightSide);
    // AccountName.setString(Backend::activeUser->getName());
    // Texture.draw(AccountName);

    if (layer == Home)
    {
        Texture.draw(SchoolYear);
        if (Backend::activeSchoolYear)
            Texture.draw(Semester);
        if (Backend::activeSemester)
            Texture.draw(addCourse);
        Texture.draw(Class);
        if (Backend::g_classes.size())
            Texture.draw(Student);
    }
    if (layer == ScY || layer == AScY || layer == DScY)
    {
        SchoolYearScreen.drawTexture(layer);
        Texture.draw(SchoolYearScreen);
    }
    if (layer == Cls || layer == ACls || layer == DCls)
    {
        ClassScreen.drawTexture(layer);
        Texture.draw(ClassScreen);
    }
    if (layer == Smt || layer == ASmt || layer == DSmt)
    {
        SemesterScreen.drawTexture(layer);
        Texture.draw(SemesterScreen);
    }
    if (layer == Std || layer == LStd || layer == RStd || layer == AStdM)
    {
        SetStudentScreen.drawTexture(layer);
        Texture.draw(SetStudentScreen);
    }
    if (layer == ACrs)
    {
        AddCourseScreen.drawTexture();
        Texture.draw(AddCourseScreen);
    }
    if (layer == Crs || layer == CrsF || layer == UpdCrs ||
        layer == CrsAStd || layer == CrsRStd || layer == CrsVStd ||
        layer == CrsScb || layer == CrsUpdScb)
    {
        ViewCourseScreen.drawTexture(layer);
        Texture.draw(ViewCourseScreen);
    }
    if (layer == VCls || layer == ClsStd || layer == ClsUpd || layer == ClsScb)
    {
        ViewClassScreen.drawTexture(layer);
        Texture.draw(ViewClassScreen);
    }
    if (layer == Pass)
    {
        Password.drawTexture();
        Texture.draw(Password);
    }
    if (layer != Home)
        Texture.draw(Back);
    Texture.display();
}

void StaffWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////////

void StaffWindow::processEvent(sf::Event event)
{
    if (layer != Home)
        Texture.draw(Back);
    Texture.draw(changePassword);
    Texture.draw(LogOut);
    Texture.draw(viewClass);
    Texture.draw(viewCourse);
    if (LogOut.isPressed(event))
    {
        layer = Home;
        drawTexture();
        Backend::activeUser->logOut();
        Hide();
        LogInWindow.show();
        return;
    }
    if (changePassword.isPressed(event))
    {
        layer = Pass;
        Password.clearLine();
        Password.drawTexture();
        drawTexture();
        return;
    }
    // if (viewProfile.isPressed(event))
    // {
    //     layer = Prf;
    //     profile.drawTexture();
    //     drawTexture();
    //     return;
    // }
    if (viewCourse.isPressed(event))
    {
        layer = Crs;
        ViewCourseScreen.FirstDraw();
        drawTexture();
        return;
    }
    if (viewClass.isPressed(event))
    {
        layer = VCls;
        ViewClassScreen.FirstDraw(Backend::g_classes);
        drawTexture();
        return;
    }
    if (layer == Home)
    {
        Texture.draw(SchoolYear);
        Texture.draw(Class);
        if (Backend::activeSchoolYear)
        {
            Texture.draw(Semester);
            if (Semester.isPressed(event))
            {
                layer = Smt;
                SemesterScreen.clearLine();
                SemesterScreen.drawTexture(layer);
                drawTexture();
                return;
            }
        }
        if (!Backend::g_classes.empty())
        {
            Texture.draw(Student);
            if (Student.isPressed(event))
            {
                layer = Std;
                SetStudentScreen.clearLine();
                SetStudentScreen.FirstDraw();
                drawTexture();
                return;
            }
        }
        if (Backend::activeSemester)
        {
            Texture.draw(addCourse);
            if (addCourse.isPressed(event))
            {
                layer = ACrs;
                AddCourseScreen.clearLine();
                AddCourseScreen.FirstDraw();
                drawTexture();
                return;
            }
        }
        if (SchoolYear.isPressed(event))
        {
            layer = ScY;
            SchoolYearScreen.clearLine();
            SchoolYearScreen.drawTexture(layer);
            drawTexture();
            return;
        }
        if (Class.isPressed(event))
        {
            layer = Cls;
            ClassScreen.clearLine();
            ClassScreen.drawTexture(layer);
            drawTexture();
            return;
        }
    }
    if (layer == ScY || layer == AScY || layer == DScY)
    {
        SchoolYearScreen.processEvent(event, layer);
        Texture.draw(SchoolYearScreen);
    }
    if (layer == Cls || layer == ACls || layer == DCls)
    {
        ClassScreen.processEvent(event, layer);
        Texture.draw(ClassScreen);
    }
    if (layer == Smt || layer == ASmt || layer == DSmt)
    {
        SemesterScreen.processEvent(event, layer);
        Texture.draw(SemesterScreen);
    }
    if (layer == Std || layer == LStd || layer == RStd || layer == AStdM)
    {
        SetStudentScreen.processEvent(event, layer);
        Texture.draw(SetStudentScreen);
    }
    if (layer == ACrs)
    {
        AddCourseScreen.processEvent(event);
        Texture.draw(AddCourseScreen);
    }
    if (layer == Pass)
    {
        Password.processEvent(event);
        Texture.draw(Password);
    }
    if (layer == Crs || layer == CrsF || layer == UpdCrs ||
        layer == CrsAStd || layer == CrsRStd || layer == CrsVStd ||
        layer == CrsScb || layer == CrsUpdScb)
    {
        ViewCourseScreen.processEvent(event, layer);
        Texture.draw(ViewCourseScreen);
    }
    if (layer == VCls || layer == ClsStd || layer == ClsUpd || layer == ClsScb)
    {
        ViewClassScreen.processEvent(event, layer);
        Texture.draw(ViewClassScreen);
    }
    // if (layer == Prf)
    //     Texture.draw(profile);

    if (layer != Home)
    {
        Texture.draw(Back);
        if (Back.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            if (layer == ScY || layer == Cls || layer == Smt || layer == Std ||
                layer == ACrs || layer == Crs || layer == Pass || layer == VCls || layer == Prf)
            {
                layer = Home;
            }
            if (layer == AScY || layer == DScY)
                layer = ScY;
            if (layer == ACls || layer == DCls)
                layer = Cls;
            if (layer == ASmt || layer == DSmt)
                layer = Smt;
            if (layer == LStd)
                layer = Std;
            if (layer == AStdM || layer == RStd)
            {
                layer = LStd;
                SetStudentScreen.clearLine();
            }
            if (layer == CrsF)
            {
                ViewCourseScreen.clearLine();
                ViewCourseScreen.resetFail();
                layer = Crs;
                ViewCourseScreen.drawTexture(layer);
            }
            if (layer == UpdCrs || layer == CrsAStd || layer == CrsRStd || layer == CrsVStd || layer == CrsScb)
            {
                layer = CrsF;
                ViewCourseScreen.resetFail();
                ViewCourseScreen.drawTexture(layer);
            }
            if (layer == CrsUpdScb)
            {
                layer = CrsScb;
                ViewCourseScreen.drawTexture(layer);
            }
            if (layer == ClsStd)
            {
                ViewClassScreen.clearLine();
                layer = VCls;
                ViewClassScreen.drawTexture(layer);
            }
            if (layer == ClsUpd || layer == ClsScb)
            {
                layer = ClsStd;
                ViewClassScreen.drawTexture(layer);
            }

            drawTexture();
            return;
        }
    }
}

bool StaffWindow::mouseOn(const sf::Vector2i &MousePos)
{
    if (!hidden)
    {
        if (layer == Pass)
            return Password.mouseOn(MousePos);
        return (SchoolYearScreen.mouseOn(MousePos, layer) ||
                ClassScreen.mouseOn(MousePos, layer) ||
                SemesterScreen.mouseOn(MousePos, layer) ||
                SetStudentScreen.mouseOn(MousePos, layer) ||
                AddCourseScreen.mouseOn(MousePos, layer) ||
                ViewCourseScreen.mouseOn(MousePos, layer) ||
                ViewClassScreen.mouseOn(MousePos, layer));
    }
    return false;
}

void StaffWindow::Show()
{
    hidden = 0;
    AccountName.setString(Backend::activeUser->getSocialID());
    drawTexture();
}

void StaffWindow::Hide()
{
    hidden = 1;
}

bool StaffWindow::isHidden()
{
    return hidden;
}
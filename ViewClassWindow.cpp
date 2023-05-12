#include <ViewClassWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <sstream>
#include <iomanip>

ViewClassWindow::ViewClassWindow()
{
}

void ViewClassWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(window.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Classes");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Class name

    ClassInput.setString("Class name: ");
    ClassInput.setFillColor(sf::Color::Black);
    ClassInput.setFont(LightFont);
    ClassInput.setCharacterSize(18);
    ClassInput.setStyle(sf::Text::Bold);
    ClassInput.setPosition(200, 200);

    ClassName.create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
    ClassName.setCaret();
    ClassName.setTyping();
    ClassName.setOpacity();
    ClassName.setFont(RegularFont);
    ClassName.setFillColor(BackgroundColor);
    ClassName.setTextColor();
    ClassName.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    ClassName.setPosition(400, 195);

    ClassConfirm.create(750, 195, 150, 50, RegularFont, 18, "Confirm");
    ClassConfirm.setFillColor(sf::Color(60, 60, 60, 255));
    ClassConfirm.setTextColor(sf::Color::White);
    ClassConfirm.setCoverColor(sf::Color(55, 55, 55, 200));

    // Fail : Empty course

    ClassEmptyFail.setFont(RegularFont);
    ClassEmptyFail.setCharacterSize(20);
    ClassEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
    ClassEmptyFail.setString("Failed: Class name can not be empty!");
    ClassEmptyFail.setPosition(250, 265);

    // Fail : Class not found

    ClassFail.setFont(RegularFont);
    ClassFail.setCharacterSize(20);
    ClassFail.setFillColor(sf::Color(168, 30, 20, 255));
    ClassFail.setString("Failed: Class not found!");
    ClassFail.setPosition(250, 265);

    // Button Class

    ClassList.create(6, 5, 180, 50, 30, 30, RegularFont, 18);
    ClassList.setPosition(200, 300);
    ClassList.setFillColor(sf::Color(25, 89, 34, 255));
    ClassList.setTextColor(sf::Color::White);
    ClassList.setCoverColor(sf::Color(50, 120, 60, 255));

    // Pages

    ClsPages.create();
    ClsPages.setPosition(550 + ClassList.getPosition().x, ClassList.getPosition().y + ClassList.getHeight() + 30);

    // List of students

    StudentList.create(RegularFont);
    StudentList.setPosition(100, 100);

    StdPages.create();
    StdPages.setPosition(StudentList.getPosition().x + StudentList.getWidth() / 2 - 90,
                         StudentList.getPosition().y + StudentList.getHeight() + 30);

    Function.create(MAX_ROW, 2, 150, 35, 0, 0, RegularFont, 16);
    Function.setColString(0, "Update");
    Function.setColString(1, "Scoreboard");
    Function.setPosition(StudentList.getPosition().x + StudentList.getWidth() + 20,
                         StudentList.getPosition().y + 110);
    Function.setTextColor(sf::Color::Black);
    Function.setFillColor(sf::Color::Cyan);

    // Update student's info

    Update.create();

    // Scoreboard

    Scoreboard.create(RegularFont);
    Scoreboard.setPosition(100, 100);

    GPATitle.setString("GPA:");
    GPATitle.setFillColor(sf::Color::Black);
    GPATitle.setFont(RegularFont);
    GPATitle.setCharacterSize(18);
    GPATitle.setPosition(Scoreboard.getPosition().x + 350, Scoreboard.getPosition().y + 20);

    GPA.create(Scoreboard.getPosition().x + 400, Scoreboard.getPosition().y + 10, 100, 35, RegularFont, 18, "");
    GPA.setTextColor(sf::Color::Black);

    ScbPages.create();
    ScbPages.setPosition(Scoreboard.getPosition().x + Scoreboard.getWidth() / 2 - 90,
                         Scoreboard.getPosition().y + Scoreboard.getHeight() + 30);

    // Pre-draw

    Predraw();

    // Setup

    fail = Clear;
}

// Draw ///////////////////////////////////////////////////////////////////////////////////////////////

void ViewClassWindow::Predraw()
{
    ClassName.drawTexture();
    ClassConfirm.drawTexture();
}

void ViewClassWindow::FirstDraw(const List<Backend::Class> &list)
{
    clearLine();
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(ClassInput);
    Texture.draw(ClassName);
    Texture.draw(ClassConfirm);
    ClassList.drawTexture(list, 1);
    ClsNumPage = 1;
    ClsTotalPage = (list.size() ? list.size() / MAX_CLS + (bool)(list.size() % MAX_CLS) : 1);
    ClsPages.setPage(ClsNumPage, ClsTotalPage);
    Texture.draw(ClassList);
    Texture.draw(ClsPages);
    Texture.display();
}

void ViewClassWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == VCls)
    {
        Texture.draw(Title);
        Texture.draw(ClassInput);
        Texture.draw(ClassName);
        Texture.draw(ClassList);
        Texture.draw(ClassConfirm);
        Texture.draw(ClsPages);
        if (fail == ClsNotFound)
            Texture.draw(ClassFail);
        if (fail == ClsEmpty)
            Texture.draw(ClassEmptyFail);
    }
    if (layer == ClsStd)
    {
        Texture.draw(StudentList);
        Texture.draw(Function);
        Texture.draw(StdPages);
    }
    if (layer == ClsUpd)
    {
        Texture.draw(Update);
    }
    if (layer == ClsScb)
    {
        Texture.draw(Scoreboard);
        Texture.draw(GPATitle);
        Texture.draw(GPA);
        Texture.draw(ScbPages);
    }
    Texture.display();
}

void ViewClassWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////

void ViewClassWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == VCls)
    {
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        Texture.draw(ClassConfirm);
        Texture.draw(ClassList);
        if (ClassList.isPressed(event))
        {
            CurClass = Backend::g_classes.find_if(
                [&](const Backend::Class &a) -> bool
                {
                    return a.getID() == ClassList.getText();
                });
            // std::cerr << (CurClass  == Backend::g_classes.end()) << std::endl;
            // std::cerr << CurClass->getID() << std::endl;
            // for (const Backend::Student *student : CurClass->students())
            // {
            //     std::cerr << student << std::endl;
            // }
            // std::cerr << "\nG_STUDENTS" << std::endl;
            // for (const Backend::Student &student : Backend::g_students)
            // {
            //     std::cerr << &student << std::endl;
            // }
            StudentList.setTitle(ClassList.getText());
            // for (const Backend::Student *student : (*CurClass).students())
            // {
            //     std::cerr << student->getID() << ' '
            //               << student->getClass()->getID() << ' '
            //               << student->getName() << ' '
            //               << Backend::Student::genderToString(student->getGender()) << ' '
            //               << Backend::Student::dateToString(student->getDateOfBirth()) << std::endl;
            // }
            StudentList.drawTexture((*CurClass).students(), 1);
            StdNumPage = 1;
            StdTotalPage = ((*CurClass).students().size() ? (*CurClass).students().size() / MAX_ROW + (bool)((*CurClass).students().size() % MAX_ROW) : 1);
            Function.drawTexture((*CurClass).students().size(), 1);
            StdPages.setPage(StdNumPage, StdTotalPage);
            layer = ClsStd;
            drawTexture(layer);
            return;
        }
        Texture.draw(ClsPages);
        bool Check = 0;
        ClsPages.processEvent(event, ClsNumPage, ClsTotalPage, Check);
        if (Check)
        {
            ClassList.drawTexture(Backend::g_classes, ClsNumPage);
            drawTexture(layer);
        }
        if (ClassConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!ClassName.getText().getSize())
                fail = ClsEmpty;
            CurClass = Backend::g_classes.find_if(
                [&](const Backend::Class &a) -> bool
                {
                    return a.getID() == ClassName.getText();
                });
            if (fail != ClsEmpty && CurClass == Backend::g_classes.end())
                fail = ClsNotFound;
            else if (!fail)
            {
                StudentList.setTitle(ClassName.getText());
                StudentList.drawTexture((*CurClass).students(), 1);
                StdNumPage = 1;
                StdTotalPage = ((*CurClass).students().size() ? (*CurClass).students().size() / MAX_ROW + (bool)((*CurClass).students().size() % MAX_ROW) : 1);
                Function.drawTexture((*CurClass).students().size(), 1);
                StdPages.setPage(StdNumPage, StdTotalPage);
                layer = ClsStd;
            }
            drawTexture(layer);
            return;
        }
    }
    if (layer == ClsStd)
    {
        Texture.draw(Function);
        if (Function.isPressed(event))
        {
            // std::cerr << Function.getRow() << std::endl;
            CurStd = *(CurClass->students().begin() + (StdNumPage - 1) * MAX_ROW + Function.getRow());
            if (Function.getText() == "Update")
            {
                Update.FirstDraw(CurStd);
                layer = ClsUpd;
                drawTexture(layer);
                return;
            }
            if (Function.getText() == "Scoreboard")
            {
                Scoreboard.setTitle((*CurStd).getID());
                Scoreboard.drawTexture((*CurStd).courseInfos(), 1);
                ScbNumPage = 1;
                ScbTotalPage = ((*CurStd).courseInfos().size() ? (*CurStd).courseInfos().size() / MAX_ROW + (bool)((*CurStd).courseInfos().size() % MAX_ROW) : 1);
                ScbPages.setPage(ScbNumPage, ScbTotalPage);
                float Sum = 0;
                int credits = 0;
                for (auto i = (*CurStd).courseInfos().begin(); i != (*CurStd).courseInfos().end(); ++i)
                {
                    Sum += (*i).studentInfo->totalMark * (*i).course->getNumberOfCredits();
                    credits += (*i).course->getNumberOfCredits();
                }
                std::stringstream s;
                s << std::fixed << std::setprecision(2) << (Sum / credits);
                std::string Tmp = s.str();
                GPA.setText(Tmp);
                GPA.setTextPos();
                GPA.drawTexture();
                layer = ClsScb;
                drawTexture(layer);
                return;
            }
        }
        Texture.draw(StdPages);
        bool Check = 0;
        StdPages.processEvent(event, StdNumPage, StdTotalPage, Check);
        if (Check)
        {
            StudentList.drawTexture((*CurClass).students(), StdNumPage);
            Function.drawTexture((*CurClass).students().size(), StdNumPage);
            drawTexture(layer);
        }
    }
    if (layer == ClsUpd)
    {
        Update.processEvent(event);
        Texture.draw(Update);
    }
    if (layer == ClsScb)
    {
        Texture.draw(ScbPages);
        bool Check = 0;
        ScbPages.processEvent(event, ScbNumPage, ScbTotalPage, Check);
        if (Check)
        {
            Scoreboard.drawTexture((*CurStd).courseInfos(), ScbNumPage);
            Texture.draw(Scoreboard);
        }
    }
}

bool ViewClassWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == VCls)
        return ClassName.mouseOn(MousePos);
    if (layer == ClsUpd)
        return Update.mouseOn(MousePos);
    return false;
}

void ViewClassWindow::resetFail()
{
    fail = Clear;
}

void ViewClassWindow::clearLine()
{
    resetFail();
    ClassName.erase();
}
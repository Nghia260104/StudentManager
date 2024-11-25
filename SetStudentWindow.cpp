#include <SetStudentWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <string>

SetStudentWindow::SetStudentWindow()
{
}

void SetStudentWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Student");
    Title.setFillColor(TextColor);
    Title.setFont(Over);
    Title.setCharacterSize(40);
    // Title.setStyle(sf::Text::Bold);
    Title.setPosition(70, 70);

    // Add

    Add.create(150, 150, 300, 75, BoldFont, 30, "Add");
    Add.setFillColor(ButtonColor);
    Add.setTextColor(BackgroundColor);
    Add.setCoverColor(ButtonCoverColor);
    Add.setOutline(ButtonColor);

    // Load from file

    FromFile.create(150, 250, 300, 75, BoldFont, 30, "Load from file");
    FromFile.setFillColor(ButtonColor);
    FromFile.setTextColor(BackgroundColor);
    FromFile.setCoverColor(ButtonCoverColor);
    FromFile.setOutline(ButtonColor);

    Tutorial.setString("(Press this button to load info from all <Classname>.csv)");
    Tutorial.setFillColor(TextColor);
    Tutorial.setFont(LightFont);
    Tutorial.setCharacterSize(20);
    Tutorial.setStyle(sf::Text::Bold);
    Tutorial.setPosition(150, 350);

    // Remove

    Remove.create(500, 150, 300, 75, BoldFont, 30, "Remove");
    Remove.setFillColor(ButtonColor);
    Remove.setTextColor(BackgroundColor);
    Remove.setCoverColor(ButtonCoverColor);
    Remove.setOutline(ButtonColor);

    // Fail : Add File fail

    FailFile.setFont(RegularFont);
    FailFile.setCharacterSize(20);
    FailFile.setFillColor(sf::Color(168, 30, 20, 255));
    FailFile.setString("Load info from file failed!");
    FailFile.setPosition(150, 400);

    // Success

    FileAdd.setFont(RegularFont);
    FileAdd.setCharacterSize(20);
    FileAdd.setFillColor(sf::Color(144, 212, 58, 255));
    FileAdd.setString("Load info successfully!");
    FileAdd.setPosition(150, 400);

    // Add title

    AddTitle.setString("Add student");
    AddTitle.setFillColor(TextColor);
    AddTitle.setFont(Over);
    AddTitle.setCharacterSize(40);
    // AddTitle.setStyle(sf::Text::Bold);
    AddTitle.setPosition(100, 100);

    // Remove title

    RemoveTitle.setString("Remove student");
    RemoveTitle.setFillColor(TextColor);
    RemoveTitle.setFont(Over);
    RemoveTitle.setCharacterSize(40);
    // RemoveTitle.setStyle(sf::Text::Bold);
    RemoveTitle.setPosition(100, 100);

    // Class name

    InputClass.setString("Class name: ");
    InputClass.setFillColor(TextColor);
    InputClass.setFont(RegularFont);
    InputClass.setCharacterSize(18);
    // InputClass.setStyle(sf::Text::Bold);
    InputClass.setPosition(200, 200);

    ClassName.create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
    ClassName.setCaret();
    ClassName.setTyping();
    ClassName.setOpacity();
    ClassName.setFont(RegularFont);
    ClassName.setFillColor(BackgroundColor);
    ClassName.setTextColor();
    ClassName.setOutlineColor(sf::Color(25, 89, 34, 255), ButtonColor);
    ClassName.setPosition(400, 195);

    ClassConfirm.create(700, 195, 150, 50, RegularFont, 18, "Confirm");
    ClassConfirm.setFillColor(ButtonColor);
    ClassConfirm.setTextColor(BackgroundColor);
    ClassConfirm.setCoverColor(ButtonCoverColor);
    ClassConfirm.setOutline(ButtonColor);

    // Fail : Empty class

    EmptyClassFail.setFont(RegularFont);
    EmptyClassFail.setCharacterSize(20);
    EmptyClassFail.setFillColor(sf::Color(168, 30, 20, 255));
    EmptyClassFail.setString("Failed: Class name can not be empty!");
    EmptyClassFail.setPosition(250, 265);

    // Fail : Class not found

    FoundFail.setFont(RegularFont);
    FoundFail.setCharacterSize(20);
    FoundFail.setFillColor(sf::Color(168, 30, 20, 255));
    FoundFail.setString("Failed: Class not found!");
    FoundFail.setPosition(250, 265);

    // Button class

    ClassList.create(6, 5, 180, 50, 30, 30, RegularFont, 18);
    ClassList.setPosition(200, 300);
    ClassList.setFillColor(ButtonColor);
    ClassList.setTextColor(BackgroundColor);
    ClassList.setCoverColor(ButtonCoverColor);
    ClassList.setOutlineColor(ButtonColor);

    // Pages

    pages.create();
    pages.setPosition(ClassList.getWidth() / 2 + ClassList.getPosition().x - 90, ClassList.getPosition().y + ClassList.getHeight() + 30);

    // Function window

    Class.setString("");
    Class.setFillColor(TextColor);
    Class.setFont(Helvetica);
    Class.setCharacterSize(40);
    // Class.setStyle(sf::Text::Bold);
    Class.setPosition(100, 100);

    // Infomation cells

    Subtitle = new sf::Text[numCell];
    Cell = new TextBox[numCell];

    for (int i = 0; i < numCell; i++)
    {
        Subtitle[i].setFillColor(sf::Color::Black);
        Subtitle[i].setFont(RegularFont);
        Subtitle[i].setCharacterSize(20);
    }

    // Cells
    {
        // Student ID
        {
            Subtitle[0].setString("Student ID:");
            Subtitle[0].setPosition(300, 200);

            Cell[0].create(0, 0, 350, 50, 18, sf::Vector2f(8, 25));
            Cell[0].setPosition(300, 235);
            Cell[0].setNumber();
        }
        // Social ID
        {
            Subtitle[1].setString("Social ID:");
            Subtitle[1].setPosition(700, 200);

            Cell[1].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[1].setPosition(700, 235);
            Cell[1].setNumber();
        }
        // First Name
        {
            Subtitle[2].setString("First name:");
            Subtitle[2].setPosition(300, 300);

            Cell[2].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[2].setPosition(300, 335);
        }
        // Last Name
        {
            Subtitle[3].setString("Last name:");
            Subtitle[3].setPosition(900, 300);

            Cell[3].create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
            Cell[3].setPosition(900, 335);
        }
        // Gender
        {
            Subtitle[4].setString("Gender:");
            Subtitle[4].setPosition(300, 400);

            Cell[4].create(0, 0, 100, 50, 18, sf::Vector2f(8, 25));
            Cell[4].setPosition(300, 435);

            // Male
            {
                Male.create(450, 398, 70, 30, RegularFont, 16, "Male");
                Male.setFillColor(ButtonColor);
                Male.setTextColor(BackgroundColor);
                Male.setCoverColor(ButtonCoverColor);
                Male.setOutline(ButtonColor);
            }
            // Female
            {
                Female.create(550, 398, 70, 30, RegularFont, 16, "Female");
                Female.setFillColor(ButtonColor);
                Female.setTextColor(BackgroundColor);
                Female.setCoverColor(ButtonCoverColor);
                Female.setOutline(ButtonColor);
            }
        }
        // Date of Birth
        {
            DOB.setString("Date of Birth");
            DOB.setPosition(300, 500);
            DOB.setFillColor(sf::Color::Black);
            DOB.setFont(RegularFont);
            DOB.setCharacterSize(20);

            // Day
            {
                Subtitle[5].setString("Day:");
                Subtitle[5].setPosition(350, 555);

                Cell[5].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[5].setPosition(450, 550);
                Cell[5].setLimit(2);
                Cell[5].setNumber();
            }
            // Month
            {
                Subtitle[6].setString("Month:");
                Subtitle[6].setPosition(350, 625);

                Cell[6].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[6].setPosition(450, 620);
                Cell[6].setLimit(2);
                Cell[6].setNumber();
            }
            // Year
            {
                Subtitle[7].setString("Year:");
                Subtitle[7].setPosition(350, 695);

                Cell[7].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[7].setPosition(450, 690);
                Cell[7].setLimit(4);
                Cell[7].setNumber();
            }
        }
    }

    // Setup for all cells

    for (int i = 0; i < numCell; i++)
    {
        if (i != 4)
        {
            Cell[i].setCaret();
            Cell[i].setTyping();
            Cell[i].setOpacity();
        }
        Cell[i].setFont(RegularFont);
        Cell[i].setFillColor(BackgroundColor);
        Cell[i].setTextColor();
        Cell[i].setOutlineColor(sf::Color(25, 89, 34, 255), ButtonColor);
    }

    // Add
    {
        // Fail : Empty cell

        EmptyFail.setFont(RegularFont);
        EmptyFail.setCharacterSize(20);
        EmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        EmptyFail.setString("Failed: Cells can not be empty!");
        EmptyFail.setPosition(400, 780);

        // Fail : Invalid Date type

        DateFail.setFont(RegularFont);
        DateFail.setCharacterSize(20);
        DateFail.setFillColor(sf::Color(168, 30, 20, 255));
        DateFail.setString("Failed: Invalid Date!");
        DateFail.setPosition(400, 780);

        // Fail : Existed Student

        ExistFail.setFont(RegularFont);
        ExistFail.setCharacterSize(20);
        ExistFail.setFillColor(sf::Color(168, 30, 20, 255));
        ExistFail.setString("Failed: Student existed!");
        ExistFail.setPosition(400, 780);

        // Success

        ManualAdd.setFont(RegularFont);
        ManualAdd.setCharacterSize(20);
        ManualAdd.setFillColor(sf::Color(144, 212, 58, 255));
        ManualAdd.setString("Add Student successfully!");
        ManualAdd.setPosition(400, 780);

        // Confirm Button

        StudentConfirm.create(650, 850, 150, 50, BoldFont, 24, "Confirm");
        StudentConfirm.setFillColor(ButtonColor);
        StudentConfirm.setTextColor(BackgroundColor);
        StudentConfirm.setCoverColor(ButtonCoverColor);
        StudentConfirm.setOutline(ButtonColor);
    }

    // Remove
    {
        // Fail : Empty cell

        RemoveEmptyFail.setFont(RegularFont);
        RemoveEmptyFail.setCharacterSize(20);
        RemoveEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveEmptyFail.setString("Failed: Student ID can not be empty!");
        RemoveEmptyFail.setPosition(300, 310);

        // Fail : Not found student

        RemoveFoundFail.setFont(RegularFont);
        RemoveFoundFail.setCharacterSize(20);
        RemoveFoundFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveFoundFail.setString("Failed: Not found student!");
        RemoveFoundFail.setPosition(300, 310);

        // Success

        RemoveSuccess.setFont(RegularFont);
        RemoveSuccess.setCharacterSize(20);
        RemoveSuccess.setFillColor(sf::Color(144, 212, 58, 255));
        RemoveSuccess.setString("Remove Student successfully!");
        RemoveSuccess.setPosition(300, 310);

        // Confirm Button

        RemoveConfirm.create(375, 340, 150, 50, BoldFont, 24, "Confirm");
        RemoveConfirm.setFillColor(ButtonColor);
        RemoveConfirm.setTextColor(BackgroundColor);
        RemoveConfirm.setCoverColor(ButtonCoverColor);
        RemoveConfirm.setOutline(ButtonColor);
    }

    // Pre-draw

    Prepare();

    // Setup

    fail = Clear;
    NumPage = 0;
    TotalPage = 0;
    type = 0;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetStudentWindow::Prepare()
{
    Add.drawTexture();
    Remove.drawTexture();
    FromFile.drawTexture();
    ClassName.drawTexture();
    ClassConfirm.drawTexture();
    Male.drawTexture();
    Female.drawTexture();
    for (int i = 0; i < numCell; i++)
        Cell[i].drawTexture();
    StudentConfirm.drawTexture();
    RemoveConfirm.drawTexture();

    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Add);
    Texture.draw(Remove);
    Texture.draw(FromFile);
    Texture.draw(Tutorial);
    Texture.display();
}

void SetStudentWindow::FirstDraw()
{
    Texture.draw(Background);
    if (Temp)
        Texture.draw(*Temp);
    Texture.draw(InputClass);
    Texture.draw(ClassName);
    Texture.draw(ClassConfirm);
    NumPage = 1;
    TotalPage = ((Backend::g_classes.size()) ? (Backend::g_classes.size() / MAX_CELL + (bool)(Backend::g_classes.size() % MAX_CELL)) : 1);
    ClassList.drawTexture(Backend::g_classes, 1);
    pages.setPage(NumPage, TotalPage);
    Texture.draw(ClassList);
    Texture.draw(pages);
}

void SetStudentWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == Std)
    {
        Texture.draw(Title);
        Texture.draw(Add);
        Texture.draw(Remove);
        Texture.draw(FromFile);
        Texture.draw(Tutorial);
        if (fail == AddFileFail)
            Texture.draw(FailFile);
        if (!fail)
            Texture.draw(FileAdd);
    }
    if (layer == LStd)
    {
        if (Temp)
            Texture.draw(*Temp);
        Texture.draw(InputClass);
        Texture.draw(ClassName);
        Texture.draw(ClassConfirm);
        if (fail == EmptyClass)
            Texture.draw(EmptyClassFail);
        if (fail == notFound)
            Texture.draw(FoundFail);
        Texture.draw(ClassList);
        Texture.draw(pages);
    }
    if (layer == AStdM)
    {
        Texture.draw(Class);
        for (int i = 0; i < numCell; i++)
        {
            Texture.draw(Subtitle[i]);
            Texture.draw(Cell[i]);
        }
        Texture.draw(Male);
        Texture.draw(Female);
        Texture.draw(DOB);
        Texture.draw(StudentConfirm);
        if (fail == empty)
            Texture.draw(EmptyFail);
        if (fail == date)
            Texture.draw(DateFail);
        if (fail == existed)
            Texture.draw(ExistFail);
        if (!fail)
            Texture.draw(ManualAdd);
    }
    if (layer == RStd)
    {
        Texture.draw(Class);
        Texture.draw(Subtitle[0]);
        Texture.draw(Cell[0]);
        Texture.draw(RemoveConfirm);
        if (fail == emptyremove)
            Texture.draw(RemoveEmptyFail);
        if (fail == notFoundStd)
            Texture.draw(RemoveFoundFail);
        if (!fail)
            Texture.draw(RemoveSuccess);
    }
    Texture.display();
}

void SetStudentWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetStudentWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Std)
    {
        Texture.draw(Add);
        Texture.draw(FromFile);
        Texture.draw(Remove);
        if (FromFile.isPressed(event))
        {
            fail = 0;
            if (!Backend::Class::loadClasses())
                fail = AddFileFail;
            drawTexture(layer);
        }
        if (Add.isPressed(event))
        {
            layer = LStd;
            clearLine();
            type = add;
            Temp = &AddTitle;
            drawTexture(layer);
            return;
        }
        if (Remove.isPressed(event))
        {
            layer = LStd;
            clearLine();
            type = remove;
            Temp = &RemoveTitle;
            drawTexture(layer);
            return;
        }
    }
    if (layer == LStd)
    {
        // Texture.draw(Background);
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        if (ClassList.isPressed(event))
        {
            CurClass = Backend::g_classes.find_if(
                [&](const Backend::Class &a) -> bool
                {
                    return a.getID() == ClassList.getText();
                });
            Class.setString(ClassList.getText());
            if (type == add)
                layer = AStdM;
            if (type == remove)
                layer = RStd;
            clearLine();
            drawTexture(layer);
            return;
        }
        Texture.draw(ClassList);
        Texture.draw(pages);
        bool Check = 0;
        pages.processEvent(event, NumPage, TotalPage, Check);
        if (Check)
        {
            ClassList.drawTexture(Backend::g_classes, NumPage);
            drawTexture(layer);
        }
        Texture.draw(ClassConfirm);
        if (ClassConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (ClassName.getText() == "")
                fail = EmptyClass;
            CurClass = Backend::g_classes.find_if(
                [&](const Backend::Class &a) -> bool
                {
                    return a.getID() == ClassName.getText();
                });
            if (fail != empty && CurClass == Backend::g_classes.end())
                fail = notFound;
            else if (!fail)
            {
                Class.setString(ClassName.getText());
                if (type == add)
                    layer = AStdM;
                if (type == remove)
                    layer = RStd;
                clearLine();
            }
            drawTexture(layer);
            return;
        }
    }
    if (layer == AStdM)
    {
        for (int i = 0; i < numCell; i++)
            if (Cell[i].checkEvent(event))
                Texture.draw(Cell[i]);
        Texture.draw(Male);
        Texture.draw(Female);
        if (Male.isPressed(event))
        {
            Cell[4].setText(Male.getText());
            Cell[4].drawTexture();
            Texture.draw(Cell[4]);
        }
        if (Female.isPressed(event))
        {
            Cell[4].setText(Female.getText());
            Cell[4].drawTexture();
            Texture.draw(Cell[4]);
        }
        Texture.draw(StudentConfirm);
        if (StudentConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            bool check = 1;
            for (int i = 0; i < numCell; i++)
                check &= (bool)(Cell[i].getText().getSize());
			Backend::Date Tmp(std::stoi(Cell[7].getText().getSize() ? std::string(Cell[7].getText()) : "0"),
							  std::stoi(Cell[6].getText().getSize() ? std::string(Cell[6].getText()) : "0"),
							  std::stoi(Cell[5].getText().getSize() ? std::string(Cell[5].getText()) : "0"));
            if (!check)
                fail = empty;
            else if (!Tmp.isValidDate())
                fail = date;
            else if (!Backend::Student::createStudent(Cell[0].getText()))
                fail = existed;
            else
            {
                Backend::Student &Std = Backend::g_students.back();
                Std.setSocialID(Cell[1].getText());
                Std.setFirstName(Cell[2].getText());
                Std.setLastName(Cell[3].getText());
                Std.setGender(Cell[4].getText());
                Std.setDateOfBirth(Tmp);
                CurClass->addStudent(&Std);
            }
            drawTexture(layer);
            return;
        }
    }
    if (layer == RStd)
    {
        if (Cell[0].checkEvent(event))
            Texture.draw(Cell[0]);
        Texture.draw(RemoveConfirm);
        if (RemoveConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!Cell[0].getText().getSize())
                fail = emptyremove;
            else if (!Backend::Student::deleteStudent(Cell[0].getText()))
                fail = notFoundStd;
            drawTexture(layer);
        }
    }
}

bool SetStudentWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == LStd)
        return ClassName.mouseOn(MousePos);
    if (layer == AStdM)
    {
        bool check = 0;
        for (int i = 0; i < numCell; i++)
            check |= Cell[i].mouseOn(MousePos);
        return check;
    }
    if (layer == RStd)
        return Cell[0].mouseOn(MousePos);
    return false;
}

void SetStudentWindow::clearLine()
{
    ClassName.erase();
    for (int i = 0; i < numCell; i++)
        Cell[i].erase();
    fail = Clear;
}

void SetStudentWindow::resetFail()
{
    fail = Clear;
}

// Destructor /////////////////////////////////////////////////////////////////////////////////////////////////////////

SetStudentWindow::~SetStudentWindow()
{
    delete[] Subtitle;
    delete[] Cell;
}

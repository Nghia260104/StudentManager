#include <UpdateStudentWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

UpdateStudentWindow::UpdateStudentWindow()
{
}

void UpdateStudentWindow::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(window.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Update student's info");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

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
                Male.setFillColor(sf::Color(25, 89, 34, 255));
                Male.setTextColor(sf::Color::White);
                Male.setCoverColor(sf::Color(20, 85, 30, 200));
            }
            // Female
            {
                Female.create(550, 398, 70, 30, RegularFont, 16, "Female");
                Female.setFillColor(sf::Color(25, 89, 34, 255));
                Female.setTextColor(sf::Color::White);
                Female.setCoverColor(sf::Color(20, 85, 30, 200));
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
        Cell[i].setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    }

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

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(144, 212, 58, 255));
    Success.setString("Update student's info successfully!");
    Success.setPosition(400, 780);

    // Confirm Button

    Confirm.create(650, 850, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // // Pre-draw

    // Prepare();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////

void UpdateStudentWindow::Prepare()
{
}

void UpdateStudentWindow::FirstDraw(Backend::Student *student)
{
    Texture.draw(Background);
    Texture.draw(Title);
    Male.drawTexture();
    Female.drawTexture();
    Confirm.drawTexture();
    Texture.draw(Male);
    Texture.draw(Female);
    Texture.draw(DOB);
    Texture.draw(Confirm);
    CurStd = student;
    Cell[0].setText(student->getID());
    Cell[1].setText(student->getSocialID());
    Cell[2].setText(student->getFirstName());
    Cell[3].setText(student->getLastName());
    Cell[4].setText(Backend::Account::genderToString(student->getGender()));
    Cell[5].setText(std::to_string(student->getDateOfBirth().day));
    Cell[6].setText(std::to_string(student->getDateOfBirth().month));
    Cell[7].setText(std::to_string(student->getDateOfBirth().year));
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].drawTexture();
        Texture.draw(Subtitle[i]);
        Texture.draw(Cell[i]);
    }
    Texture.display();
}

void UpdateStudentWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Male);
    Texture.draw(Female);
    Texture.draw(DOB);
    Texture.draw(Confirm);
    for (int i = 0; i < numCell; i++)
    {
        Texture.draw(Subtitle[i]);
        Texture.draw(Cell[i]);
    }
    if (fail == empty)
        Texture.draw(EmptyFail);
    if (fail == date)
        Texture.draw(DateFail);
    if (fail == existed)
        Texture.draw(ExistFail);
    if (!fail)
        Texture.draw(Success);
    Texture.display();
}

void UpdateStudentWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////

void UpdateStudentWindow::processEvent(sf::Event event)
{
    for (int i = 0; i < numCell; i++)
        if (Cell[i].checkEvent(event))
            Texture.draw(Cell[i]);
    Texture.draw(Female);
    Texture.draw(Male);
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        bool check = 1;
        for (int i = 0; i < numCell; i++)
            check &= (bool)(Cell[i].getText().getSize());
        Date Tmp(std::stoi(std::string(Cell[6].getText())),
                 std::stoi(std::string(Cell[5].getText())),
                 std::stoi(std::string(Cell[4].getText())));
        if (!check)
            fail = empty;
        else if (!Tmp.isValidDate())
            fail = date;
        else if (CurStd->getID() != Cell[0].getText() &&
                 Backend::g_students.find_if(
                     [&](const Backend::Student &a) -> bool
                     {
                         return (a.getID() == CurStd->getID());
                     }) != Backend::g_students.end())
            fail = existed;
        if (!fail)
        {
            CurStd->setID(Cell[0].getText());
            CurStd->setSocialID(Cell[1].getText());
            CurStd->setFirstName(Cell[2].getText());
            CurStd->setLastName(Cell[3].getText());
            CurStd->setGender(Cell[4].getText());
            CurStd->setDateOfBirth(Tmp);
        }
        drawTexture();
    }
}

bool UpdateStudentWindow::mouseOn(const sf::Vector2i &MousePos)
{
    bool check = 0;
    for (int i = 0; i < numCell; i++)
        check |= Cell[i].mouseOn(MousePos);
    return check;
}

void UpdateStudentWindow::resetFail()
{
    fail = Clear;
}

// Destructor ///////////////////////////////////////////////////////////////////////////////

UpdateStudentWindow::~UpdateStudentWindow()
{
    delete[] Subtitle;
    delete[] Cell;
}
#include <SemesterWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <Date.hpp>

// Constructor /////////////////////////////////////////////////////////////////////////////////////////////

SemesterWindow::SemesterWindow()
{
}

void SemesterWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Semester");
    Title.setFillColor(TextColor);
    Title.setFont(Over);
    Title.setCharacterSize(40);
    // Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Create

    AddSemester.create(200, 200, 250, 75, BoldFont, 36, "Create");
    AddSemester.setFillColor(ButtonColor);
    AddSemester.setTextColor(BackgroundColor);
    AddSemester.setCoverColor(ButtonCoverColor);
    AddSemester.setOutline(ButtonColor);

    //// Add Title

    Add.setString("Create semester");
    Add.setFillColor(TextColor);
    Add.setFont(Over);
    Add.setCharacterSize(40);
    // Add.setStyle(sf::Text::Bold);
    Add.setPosition(100, 100);

    // Remove

    DeleteSemester.create(200, 325, 250, 75, BoldFont, 36, "Remove");
    DeleteSemester.setFillColor(ButtonColor);
    DeleteSemester.setTextColor(BackgroundColor);
    DeleteSemester.setCoverColor(ButtonCoverColor);
    DeleteSemester.setOutline(ButtonColor);

    //// Remove Title

    Delete.setString("Delete semester");
    Delete.setFillColor(TextColor);
    Delete.setFont(Over);
    Delete.setCharacterSize(40);
    // Delete.setStyle(sf::Text::Bold);
    Delete.setPosition(100, 100);

    // Add semester
    {
        // Subtitle

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
            // Semester
            {
                Subtitle[0].setString("Semester:");
                Subtitle[0].setPosition(300, 200);

                Cell[0].create(0, 0, 30, 30, 18, sf::Vector2f(8, 15));
                Cell[0].setPosition(420, 198);

                // S1
                {
                    s1.create(480, 198, 30, 30, RegularFont, 16, "1");
                    s1.setFillColor(ButtonColor);
                    s1.setTextColor(BackgroundColor);
                    s1.setCoverColor(ButtonCoverColor);
                    s1.setOutline(ButtonColor);
                }
                // S2
                {
                    s2.create(530, 198, 30, 30, RegularFont, 16, "2");
                    s2.setFillColor(ButtonColor);
                    s2.setTextColor(BackgroundColor);
                    s2.setCoverColor(ButtonCoverColor);
                    s3.setOutline(ButtonColor);
                }
                // S3
                {
                    s3.create(580, 198, 30, 30, RegularFont, 16, "3");
                    s3.setFillColor(ButtonColor);
                    s3.setTextColor(BackgroundColor);
                    s3.setCoverColor(ButtonCoverColor);
                    s3.setOutline(ButtonColor);
                }
            }

            // School year
            {
                SCY.setFillColor(sf::Color::Black);
                SCY.setFont(RegularFont);
                SCY.setCharacterSize(20);
                SCY.setString("School year:");
                SCY.setPosition(300, 300);

                SchoolYear.create(450, 298, 100, 30, RegularFont, 18, "");
                SchoolYear.setTextColor(sf::Color::Black);
                SchoolYear.setFillColor(BackgroundColor);
            }

            // Start Date
            {
                StartDate.setFillColor(sf::Color::Black);
                StartDate.setFont(RegularFont);
                StartDate.setCharacterSize(20);
                StartDate.setString("Start date");
                StartDate.setPosition(300, 375);

                // Day
                {
                    Subtitle[1].setString("Day:");
                    Subtitle[1].setPosition(350, 430);

                    Cell[1].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[1].setPosition(410, 425);
                    Cell[1].setLimit(2);
                    Cell[1].setNumber();
                }
                // Month
                {
                    Subtitle[2].setString("Month:");
                    Subtitle[2].setPosition(530, 430);

                    Cell[2].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[2].setPosition(630, 425);
                    Cell[2].setLimit(2);
                    Cell[2].setNumber();
                }
                // Year
                {
                    Subtitle[3].setString("Year:");
                    Subtitle[3].setPosition(750, 430);

                    Cell[3].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[3].setPosition(850, 425);
                    Cell[3].setLimit(4);
                    Cell[3].setNumber();
                }
            }

            // End date
            {
                EndDate.setFillColor(sf::Color::Black);
                EndDate.setFont(RegularFont);
                EndDate.setCharacterSize(20);
                EndDate.setString("End date");
                EndDate.setPosition(300, 490);

                // Day
                {
                    Subtitle[4].setString("Day:");
                    Subtitle[4].setPosition(350, 545);

                    Cell[4].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[4].setPosition(410, 540);
                    Cell[4].setLimit(2);
                    Cell[4].setNumber();
                }
                // Month
                {
                    Subtitle[5].setString("Month:");
                    Subtitle[5].setPosition(530, 545);

                    Cell[5].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[5].setPosition(630, 540);
                    Cell[5].setLimit(2);
                    Cell[5].setNumber();
                }
                // Year
                {
                    Subtitle[6].setString("Year:");
                    Subtitle[6].setPosition(750, 545);

                    Cell[6].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                    Cell[6].setPosition(850, 540);
                    Cell[6].setLimit(4);
                    Cell[6].setNumber();
                }
            }
        }

        // Setup for all cells

        for (int i = 0; i < numCell; i++)
        {
            if (i != 0)
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

        // Fail type 1 : Empty cell

        EmptyFail.setFont(RegularFont);
        EmptyFail.setCharacterSize(20);
        EmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        EmptyFail.setString("Failed: Cells can not be empty!");
        EmptyFail.setPosition(400, 610);

        // Fail type 2 : Existed

        ExistFail.setFont(RegularFont);
        ExistFail.setCharacterSize(20);
        ExistFail.setFillColor(sf::Color(168, 30, 20, 255));
        ExistFail.setString("Failed: Semester existed!");
        ExistFail.setPosition(400, 610);

        // Fail type 3 : Invalid Date type

        DateFail.setFont(RegularFont);
        DateFail.setCharacterSize(20);
        DateFail.setFillColor(sf::Color(168, 30, 20, 255));
        DateFail.setString("Failed: Invalid Date!");
        DateFail.setPosition(400, 610);

        // Add success

        ASuccess.setFont(RegularFont);
        ASuccess.setCharacterSize(20);
        ASuccess.setFillColor(sf::Color(144, 212, 58, 255));
        ASuccess.setString("Add semester successfully!");
        ASuccess.setPosition(400, 610);

        // Confirm Button

        AddConfirm.create(580, 650, 150, 50, BoldFont, 24, "Confirm");
        AddConfirm.setFillColor(ButtonColor);
        AddConfirm.setTextColor(BackgroundColor);
        AddConfirm.setCoverColor(ButtonCoverColor);
        AddConfirm.setOutline(ButtonColor);
    }

    // Fail : Semester not found

    FoundFail.setFont(RegularFont);
    FoundFail.setCharacterSize(20);
    FoundFail.setFillColor(sf::Color(168, 30, 20, 255));
    FoundFail.setString("Failed: Semester not found!");
    FoundFail.setPosition(350, 370);

    // Delete Success

    DSuccess.setFont(RegularFont);
    DSuccess.setCharacterSize(20);
    DSuccess.setFillColor(sf::Color(144, 212, 58, 255));
    DSuccess.setString("Delete semester successfully!");
    DSuccess.setPosition(350, 370);

    // Delete confirm button

    DeleteConfirm.create(425, 410, 150, 50, BoldFont, 24, "Confirm");
    DeleteConfirm.setFillColor(ButtonColor);
    DeleteConfirm.setTextColor(BackgroundColor);
    DeleteConfirm.setCoverColor(ButtonCoverColor);
    DeleteConfirm.setOutline(ButtonColor);

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw ////////////////////////////////////////////////////////////////////////////////////////////////////////

void SemesterWindow::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    AddSemester.drawTexture();
    Texture.draw(AddSemester);
    DeleteSemester.drawTexture();
    Texture.draw(DeleteSemester);
    for (int i = 0; i < numCell; i++)
        Cell[i].drawTexture();
    s1.drawTexture();
    s2.drawTexture();
    s3.drawTexture();
    AddConfirm.drawTexture();
    DeleteConfirm.drawTexture();
    Texture.display();
}

void SemesterWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == Smt)
    {
        Texture.draw(Title);
        Texture.draw(AddSemester);
        Texture.draw(DeleteSemester);
    }
    if (layer == ASmt)
    {
        Texture.draw(Add);
        for (int i = 0; i < numCell; i++)
        {
            Texture.draw(Subtitle[i]);
            Texture.draw(Cell[i]);
        }
        Texture.draw(s1);
        Texture.draw(s2);
        Texture.draw(s3);
        Texture.draw(SCY);
        Texture.draw(SchoolYear);
        Texture.draw(StartDate);
        Texture.draw(EndDate);
        Texture.draw(AddConfirm);
        if (fail == empty)
            Texture.draw(EmptyFail);
        if (fail == date)
            Texture.draw(DateFail);
        if (fail == existed)
            Texture.draw(ExistFail);
        if (!fail)
            Texture.draw(ASuccess);
    }
    if (layer == DSmt)
    {
        Texture.draw(Delete);
        Texture.draw(Subtitle[0]);
        Texture.draw(Cell[0]);
        Texture.draw(s1);
        Texture.draw(s2);
        Texture.draw(s3);
        Texture.draw(SCY);
        Texture.draw(SchoolYear);
        Texture.draw(DeleteConfirm);
        if (fail == empty)
            Texture.draw(EmptyFail);
        if (fail == notFound)
            Texture.draw(FoundFail);
        if (!fail)
            Texture.draw(DSuccess);
    }
    Texture.display();
}

void SemesterWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SemesterWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Smt)
    {
        drawTexture(layer);
        // Texture.draw(Background);
        Texture.draw(AddSemester);
        Texture.draw(DeleteSemester);
        if (AddSemester.isPressed(event))
        {
            layer = ASmt;
            clearLine();
            SchoolYear.setText(std::to_string(Backend::activeSchoolYear->getStartYear()));
            SchoolYear.setTextPos();
            SchoolYear.drawTexture();
            drawTexture(layer);
            return;
        }
        if (DeleteSemester.isPressed(event))
        {
            layer = DSmt;
            clearLine();
            SchoolYear.setText(std::to_string(Backend::activeSchoolYear->getStartYear()));
            SchoolYear.setTextPos();
            SchoolYear.drawTexture();
            drawTexture(layer);
            return;
        }
    }
    if (layer == ASmt)
    {
        for (int i = 1; i < numCell; i++)
            if (Cell[i].checkEvent(event))
                Texture.draw(Cell[i]);
        Texture.draw(s1);
        Texture.draw(s2);
        Texture.draw(s3);
        if (s1.isPressed(event))
        {
            Cell[0].setText(s1.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        if (s2.isPressed(event))
        {
            Cell[0].setText(s2.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        if (s3.isPressed(event))
        {
            Cell[0].setText(s3.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        Texture.draw(AddConfirm);
        if (AddConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            bool Check = 1;
            for (int i = 0; i < numCell; i++)
                Check &= (bool)Cell[i].getText().getSize();
            Backend::Date TmpStart(std::stoi(Cell[3].getText().getSize() ? std::string(Cell[3].getText()) : "0"),
                                   std::stoi(Cell[2].getText().getSize() ? std::string(Cell[2].getText()) : "0"),
                                   std::stoi(Cell[1].getText().getSize() ? std::string(Cell[1].getText()) : "0"));
            Backend::Date TmpEnd(std::stoi(Cell[6].getText().getSize() ? std::string(Cell[6].getText()) : "0"),
                                 std::stoi(Cell[5].getText().getSize() ? std::string(Cell[5].getText()) : "0"),
                                 std::stoi(Cell[4].getText().getSize() ? std::string(Cell[4].getText()) : "0"));
            if (!Check)
                fail = empty;
            else if (!TmpStart.isValidDate() || !TmpEnd.isValidDate() ||
                     !(TmpStart.year - Backend::activeSchoolYear->getStartYear() == 0 ||
                       TmpStart.year - Backend::activeSchoolYear->getStartYear() == 1) ||
                     !(TmpEnd.year - Backend::activeSchoolYear->getStartYear() == 0 ||
                       TmpEnd.year - Backend::activeSchoolYear->getStartYear() == 1) ||
                     (TmpStart > TmpEnd))
                fail = date;
            else if (!Backend::Semester::createSemester(std::stoi(std::string(Cell[0].getText())),
                                                        Backend::activeSchoolYear->getStartYear()))
                fail = existed;
            drawTexture(layer);
        }
    }
    if (layer == DSmt)
    {
        Texture.draw(s1);
        Texture.draw(s2);
        Texture.draw(s3);
        if (s1.isPressed(event))
        {
            Cell[0].setText(s1.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        if (s2.isPressed(event))
        {
            Cell[0].setText(s2.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        if (s3.isPressed(event))
        {
            Cell[0].setText(s3.getText());
            Cell[0].drawTexture();
            Texture.draw(Cell[0]);
        }
        Texture.draw(DeleteConfirm);
        if (DeleteConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (Cell[0].getText() == "")
                fail = empty;
            else if (!Backend::Semester::deleteSemester(std::stoi((std::string)Cell[0].getText()),
                                                        Backend::activeSchoolYear->getStartYear()))
                fail = notFound;
            drawTexture(layer);
        }
    }
}

bool SemesterWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == ASmt)
    {
        bool check = 0;
        for (int i = 1; i < numCell; i++)
            check |= Cell[i].mouseOn(MousePos);
        return check;
    }
    return false;
}

void SemesterWindow::clearLine()
{
    for (int i = 0; i < numCell; i++)
        Cell[i].erase();
    fail = Clear;
}

SemesterWindow::~SemesterWindow()
{
    delete[] Subtitle;
    delete[] Cell;
}

#include <ViewCourseWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <iomanip>

ViewCourseWindow::ViewCourseWindow()
{
}

void ViewCourseWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Courses");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Course name

    CourseInput.setString("Course name: ");
    CourseInput.setFillColor(sf::Color::Black);
    CourseInput.setFont(LightFont);
    CourseInput.setCharacterSize(18);
    CourseInput.setStyle(sf::Text::Bold);
    CourseInput.setPosition(200, 200);

    CourseName.create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
    CourseName.setCaret();
    CourseName.setTyping();
    CourseName.setOpacity();
    CourseName.setFont(RegularFont);
    CourseName.setFillColor(BackgroundColor);
    CourseName.setTextColor();
    CourseName.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    CourseName.setPosition(400, 195);

    CourseConfirm.create(750, 195, 150, 50, RegularFont, 18, "Confirm");
    CourseConfirm.setFillColor(sf::Color(60, 60, 60, 255));
    CourseConfirm.setTextColor(sf::Color::White);
    CourseConfirm.setCoverColor(sf::Color(55, 55, 55, 200));

    // Fail : Empty course

    CourseEmptyFail.setFont(RegularFont);
    CourseEmptyFail.setCharacterSize(20);
    CourseEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
    CourseEmptyFail.setString("Failed: Course name can not be empty!");
    CourseEmptyFail.setPosition(250, 265);

    // Fail : Class not found

    CourseFail.setFont(RegularFont);
    CourseFail.setCharacterSize(20);
    CourseFail.setFillColor(sf::Color(168, 30, 20, 255));
    CourseFail.setString("Failed: Course not found!");
    CourseFail.setPosition(250, 265);

    // Button Course

    CourseList.create(6, 5, 180, 50, 30, 30, RegularFont, 18);
    CourseList.setPosition(200, 300);
    CourseList.setFillColor(sf::Color(25, 89, 34, 255));
    CourseList.setTextColor(sf::Color::White);
    CourseList.setCoverColor(sf::Color(50, 120, 60, 255));

    // Pages

    pages.create();
    pages.setPosition(CourseList.getPosition().x + CourseList.getWidth() / 2 - 90, CourseList.getPosition().y + CourseList.getHeight() + 30);

    // Function window
    {
        Course.setString("");
        Course.setFillColor(sf::Color::Black);
        Course.setFont(LightFont);
        Course.setCharacterSize(40);
        Course.setStyle(sf::Text::Bold);
        Course.setPosition(70, 70);

        Update.create(150, 150, 300, 75, BoldFont, 30, "Update info");
        Update.setFillColor(sf::Color(9, 66, 55, 255));
        Update.setTextColor(sf::Color::White);
        Update.setCoverColor(sf::Color(30, 100, 70, 200));

        Delete.create(1100, 850, 300, 75, BoldFont, 30, "Delete course");
        Delete.setFillColor(sf::Color(9, 66, 55, 255));
        Delete.setTextColor(sf::Color::White);
        Delete.setCoverColor(sf::Color(30, 100, 70, 200));

        // Delete
        {
            // Caution

            Caution.setFont(RegularFont);
            Caution.setCharacterSize(20);
            Caution.setFillColor(sf::Color(168, 30, 20, 255));
            Caution.setString("Are you sure to delete this course!");
            Caution.setPosition(800, 800);

            // Success

            DeleteSuccess.setFont(RegularFont);
            DeleteSuccess.setCharacterSize(20);
            DeleteSuccess.setFillColor(sf::Color(168, 30, 20, 255));
            DeleteSuccess.setString("Delete course successfully!");
            DeleteSuccess.setPosition(800, 800);
        }

        AddStudent.create(500, 150, 300, 75, BoldFont, 30, "Add student");
        AddStudent.setFillColor(sf::Color(9, 66, 55, 255));
        AddStudent.setTextColor(sf::Color::White);
        AddStudent.setCoverColor(sf::Color(30, 100, 70, 200));

        RemoveStudent.create(500, 250, 300, 75, BoldFont, 30, "Remove student");
        RemoveStudent.setFillColor(sf::Color(9, 66, 55, 255));
        RemoveStudent.setTextColor(sf::Color::White);
        RemoveStudent.setCoverColor(sf::Color(30, 100, 70, 200));

        viewStudent.create(500, 350, 300, 75, BoldFont, 30, "List of students");
        viewStudent.setFillColor(sf::Color(9, 66, 55, 255));
        viewStudent.setTextColor(sf::Color::White);
        viewStudent.setCoverColor(sf::Color(30, 100, 70, 200));

        viewScoreboard.create(850, 150, 300, 75, BoldFont, 30, "Scoreboard");
        viewScoreboard.setFillColor(sf::Color(9, 66, 55, 255));
        viewScoreboard.setTextColor(sf::Color::White);
        viewScoreboard.setCoverColor(sf::Color(30, 100, 70, 200));
    }

    // Update course infomation

    UpdateCourseScreen.create();

    // Add student window
    {
        // Title

        AddTitle.setString("Add a student");
        AddTitle.setFillColor(sf::Color::Black);
        AddTitle.setFont(LightFont);
        AddTitle.setCharacterSize(40);
        AddTitle.setStyle(sf::Text::Bold);
        AddTitle.setPosition(100, 100);

        // Fail : Empty cell

        AddEmptyFail.setFont(RegularFont);
        AddEmptyFail.setCharacterSize(20);
        AddEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        AddEmptyFail.setString("Failed: Student ID can not be empty!");
        AddEmptyFail.setPosition(200, 265);

        // Fail : Student has been already added

        AddFail.setFont(RegularFont);
        AddFail.setCharacterSize(20);
        AddFail.setFillColor(sf::Color(168, 30, 20, 255));
        AddFail.setString("Failed: Student has been already added!");
        AddFail.setPosition(200, 265);

        // Fail : Student does not exist

        AddNotFound.setFont(RegularFont);
        AddNotFound.setCharacterSize(20);
        AddNotFound.setFillColor(sf::Color(168, 30, 20, 255));
        AddNotFound.setString("Failed: Student does not exist!");
        AddNotFound.setPosition(200, 265);

        // Success

        AddSuccess.setFont(RegularFont);
        AddSuccess.setCharacterSize(20);
        AddSuccess.setFillColor(sf::Color(144, 212, 58, 255));
        AddSuccess.setString("Add student successfully!");
        AddSuccess.setPosition(200, 265);
    }

    // Remove student window
    {
        // Title

        RemoveTitle.setString("Remove a student");
        RemoveTitle.setFillColor(sf::Color::Black);
        RemoveTitle.setFont(LightFont);
        RemoveTitle.setCharacterSize(40);
        RemoveTitle.setStyle(sf::Text::Bold);
        RemoveTitle.setPosition(100, 100);

        // Fail : Empty cell

        RemoveEmptyFail.setFont(RegularFont);
        RemoveEmptyFail.setCharacterSize(20);
        RemoveEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveEmptyFail.setString("Failed: Student ID can not be empty!");
        RemoveEmptyFail.setPosition(200, 265);

        // Fail : Student not found

        RemoveFail.setFont(RegularFont);
        RemoveFail.setCharacterSize(20);
        RemoveFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveFail.setString("Failed: Student not found!");
        RemoveFail.setPosition(200, 265);

        // Success

        RemoveSuccess.setFont(RegularFont);
        RemoveSuccess.setCharacterSize(20);
        RemoveSuccess.setFillColor(sf::Color(144, 212, 58, 255));
        RemoveSuccess.setString("Remove student successfully!");
        RemoveSuccess.setPosition(200, 265);
    }

    // Add and remove window
    {
        // Student ID

        StdTitle.setString("Student ID:");
        StdTitle.setFillColor(sf::Color::Black);
        StdTitle.setFont(RegularFont);
        StdTitle.setCharacterSize(20);
        StdTitle.setPosition(200, 200);

        StdID.create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
        StdID.setCaret();
        StdID.setTyping();
        StdID.setOpacity();
        StdID.setFont(RegularFont);
        StdID.setFillColor(BackgroundColor);
        StdID.setTextColor();
        StdID.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
        StdID.setPosition(375, 188);
        StdID.setNumber();

        // Confirm

        StdConfirm.create(275, 300, 150, 50, RegularFont, 18, "Confirm");
        StdConfirm.setFillColor(sf::Color(9, 66, 55, 255));
        StdConfirm.setTextColor(sf::Color::White);
        StdConfirm.setCoverColor(sf::Color(30, 100, 70, 200));
    }

    // List of students

    StudentList.create(RegularFont);
    StudentList.setPosition(250, 100);

    StdPages.create();
    StdPages.setPosition(StudentList.getPosition().x + StudentList.getWidth() / 2 - 90,
                         StudentList.getPosition().y + StudentList.getHeight() + 30);

    // Scoreboard

    CourseScoreboardTable.create(RegularFont);
    CourseScoreboardTable.setPosition(100, 100);

    ScbPages.create();
    ScbPages.setPosition(CourseScoreboardTable.getPosition().x + CourseScoreboardTable.getWidth() / 2 - 40,
                         CourseScoreboardTable.getPosition().y + CourseScoreboardTable.getHeight() + 30);

    UpdateScb.create(15, 1, 100, 35, 0, 0, RegularFont, 16);
    UpdateScb.setPosition(100 + CourseScoreboardTable.getWidth(), 210);
    UpdateScb.setColString(0, "Update");
    UpdateScb.setFillColor(sf::Color::Cyan);

    // Update Scoreboard
    {
        // Title

        UpdateScbTitle.setString("Update student's result");
        UpdateScbTitle.setFillColor(sf::Color::Black);
        UpdateScbTitle.setFont(LightFont);
        UpdateScbTitle.setCharacterSize(40);
        UpdateScbTitle.setStyle(sf::Text::Bold);
        UpdateScbTitle.setPosition(100, 100);

        CurStd.setString("");
        CurStd.setFillColor(sf::Color::Black);
        CurStd.setFont(LightFont);
        CurStd.setCharacterSize(28);
        CurStd.setStyle(sf::Text::Bold);
        CurStd.setPosition(180, 180);

        MarkTitle = new sf::Text[numMark];
        Mark = new TextBox[numMark];

        for (int i = 0; i < numMark; i++)
        {
            MarkTitle[i].setFillColor(sf::Color::Black);
            MarkTitle[i].setFont(RegularFont);
            MarkTitle[i].setCharacterSize(20);
        }

        // Mid term
        {
            MarkTitle[0].setString("Midterm:");
            MarkTitle[0].setPosition(250, 300);

            Mark[0].create(0, 0, 80, 50, 18, sf::Vector2f(8, 25));
            Mark[0].setPosition(400, 290);
            Mark[0].setFloatNumber();
        }

        // Final
        {
            MarkTitle[1].setString("Final:");
            MarkTitle[1].setPosition(250, 365);

            Mark[1].create(0, 0, 80, 50, 18, sf::Vector2f(8, 25));
            Mark[1].setPosition(400, 355);
            Mark[1].setFloatNumber();
        }

        // Other
        {
            MarkTitle[2].setString("Other:");
            MarkTitle[2].setPosition(250, 430);

            Mark[2].create(0, 0, 80, 50, 18, sf::Vector2f(8, 25));
            Mark[2].setPosition(400, 420);
            Mark[2].setFloatNumber();
        }

        // Total
        {
            MarkTitle[3].setString("Total:");
            MarkTitle[3].setPosition(250, 495);

            Mark[3].create(0, 0, 80, 50, 18, sf::Vector2f(8, 25));
            Mark[3].setPosition(400, 485);
            Mark[3].setFloatNumber();
        }

        // Setup for all cells

        for (int i = 0; i < numMark; i++)
        {
            Mark[i].setLimit(4);
            Mark[i].setCaret();
            Mark[i].setTyping();
            Mark[i].setOpacity();
            Mark[i].setFont(RegularFont);
            Mark[i].setFillColor(BackgroundColor);
            Mark[i].setTextColor();
            Mark[i].setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
        }

        // Fail : Mark invalid

        MarkUpdFail.setFont(RegularFont);
        MarkUpdFail.setCharacterSize(20);
        MarkUpdFail.setFillColor(sf::Color(168, 30, 20, 255));
        MarkUpdFail.setString("Failed: Mark can not over 10!");
        MarkUpdFail.setPosition(250, 550);

        // Success

        MarkUpdSuccess.setFont(RegularFont);
        MarkUpdSuccess.setCharacterSize(20);
        MarkUpdSuccess.setFillColor(sf::Color(144, 212, 58, 255));
        MarkUpdSuccess.setString("Update result successfully!");
        MarkUpdSuccess.setPosition(250, 550);

        // Confirm

        MarkConfirm.create(320, 580, 150, 50, RegularFont, 18, "Confirm");
        MarkConfirm.setFillColor(sf::Color(9, 66, 55, 255));
        MarkConfirm.setTextColor(sf::Color::White);
        MarkConfirm.setCoverColor(sf::Color(30, 100, 70, 200));
    }

    // Pre-draw

    Predraw();

    // Setup

    fail = Clear;
    NumPage = 0;
    TotalPage = 0;
    StdNumPage = 0;
    StdTotalPage = 0;
    ScbNumPage = 0;
    ScbTotalPage = 0;
    type = 0;
}

// Draw ////////////////////////////////////////////////////////////////////////////////////////////////////

void ViewCourseWindow::Predraw()
{
    CourseName.drawTexture();
    CourseConfirm.drawTexture();

    Update.drawTexture();
    Delete.drawTexture();
    AddStudent.drawTexture();
    RemoveStudent.drawTexture();
    viewStudent.drawTexture();
    viewScoreboard.drawTexture();

    StdID.drawTexture();
    StdConfirm.drawTexture();

    for (int i = 0; i < numMark; i++)
        Mark[i].drawTexture();
    MarkConfirm.drawTexture();
}

void ViewCourseWindow::FirstDraw()
{
    clearLine();
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(CourseInput);
    Texture.draw(CourseName);
    Texture.draw(CourseConfirm);
    CourseList.drawTexture(Backend::g_courses, 1);
    NumPage = 1;
    TotalPage = ((Backend::g_courses.size())
                     ? (Backend::g_courses.size() / MAX_CRS + (bool)(Backend::g_courses.size() % MAX_CRS))
                     : 1);
    pages.setPage(NumPage, TotalPage);
    Texture.draw(CourseList);
    Texture.draw(pages);
    Texture.display();
}

void ViewCourseWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == Crs)
    {
        Texture.draw(Title);
        Texture.draw(CourseInput);
        Texture.draw(CourseName);
        Texture.draw(CourseConfirm);
        if (fail == CrsEmpty)
            Texture.draw(CourseEmptyFail);
        if (fail == CrsNotFound)
            Texture.draw(CourseFail);
        Texture.draw(CourseList);
        Texture.draw(pages);
    }
    if (layer == CrsF)
    {
        Texture.draw(Course);
        Texture.draw(Update);
        Texture.draw(Delete);
        if (fail == warning)
            Texture.draw(Caution);
        if (!fail)
            Texture.draw(DeleteSuccess);
        Texture.draw(AddStudent);
        Texture.draw(RemoveStudent);
        Texture.draw(viewStudent);
        Texture.draw(viewScoreboard);
    }
    if (layer == UpdCrs)
    {
        Texture.draw(UpdateCourseScreen);
    }
    if (layer == CrsAStd)
    {
        Texture.draw(AddTitle);
        Texture.draw(StdTitle);
        Texture.draw(StdID);
        Texture.draw(StdConfirm);
        if (fail == AddExist)
            Texture.draw(AddFail);
        if (fail == StdnotFound)
            Texture.draw(AddNotFound);
        if (fail == Addempty)
            Texture.draw(AddEmptyFail);
        if (!fail)
            Texture.draw(AddSuccess);
    }
    if (layer == CrsRStd)
    {
        Texture.draw(RemoveTitle);
        Texture.draw(StdTitle);
        Texture.draw(StdID);
        Texture.draw(StdConfirm);
        if (fail == RmvNotFound)
            Texture.draw(RemoveFail);
        if (fail == RmvEmpty)
            Texture.draw(RemoveEmptyFail);
        if (!fail)
            Texture.draw(RemoveSuccess);
    }
    if (layer == CrsVStd)
    {
        Texture.draw(StudentList);
        Texture.draw(StdPages);
    }
    if (layer == CrsScb)
    {
        Texture.draw(CourseScoreboardTable);
        Texture.draw(UpdateScb);
        Texture.draw(ScbPages);
    }
    if (layer == CrsUpdScb)
    {
        Texture.draw(UpdateScbTitle);
        Texture.draw(CurStd);
        for (int i = 0; i < numMark; i++)
        {
            Texture.draw(MarkTitle[i]);
            Texture.draw(Mark[i]);
        }
        Texture.draw(MarkConfirm);
        if (fail == markFail)
            Texture.draw(MarkUpdFail);
        if (!fail)
            Texture.draw(MarkUpdSuccess);
    }
    Texture.display();
}

void ViewCourseWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////////

void ViewCourseWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Crs)
    {
        if (CourseName.checkEvent(event))
            Texture.draw(CourseName);
        Texture.draw(CourseConfirm);
        Texture.draw(CourseList);
        Texture.draw(pages);
        bool Check = 0;
        pages.processEvent(event, NumPage, TotalPage, Check);
        if (Check)
        {
            CourseList.drawTexture(Backend::g_courses, NumPage);
            drawTexture(layer);
        }
        if (CourseList.isPressed(event))
        {
            CurCourse = Backend::g_courses.find_if(
                [&](const Backend::Course &a) -> bool
                {
                    return a.getID() == CourseList.getText();
                });
            Course.setString(CourseList.getText());
            layer = CrsF;
            resetFail();
            New = Backend::activeSemester->courses().find_if(
                      [&](Backend::Course *const &a) -> bool
                      {
                          return a->getID() == CurCourse->getID();
                      }) != Backend::activeSemester->courses().end();
            drawTexture(layer);
            return;
        }
        if (CourseConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!CourseName.getText().getSize())
                fail = CrsEmpty;
            CurCourse = Backend::g_courses.find_if(
                [&](const Backend::Course &a) -> bool
                {
                    return a.getID() == CourseName.getText();
                });
            if (fail != CrsEmpty && CurCourse == Backend::g_courses.end())
                fail = CrsNotFound;
            else if (!fail)
            {
                Course.setString(CourseName.getText());
                layer = CrsF;
                resetFail();
                New = Backend::activeSemester->courses().find_if(
                          [&](Backend::Course *const &a) -> bool
                          {
                              return a->getID() == CurCourse->getID();
                          }) != Backend::activeSemester->courses().end();
            }
            drawTexture(layer);
            return;
        }
    }
    if (layer == CrsF)
    {
        Texture.draw(viewStudent);
        if (viewStudent.isPressed(event))
        {
            layer = CrsVStd;
            StudentList.drawTexture(CurCourse->studentInfos(), 1);
            StdNumPage = 1;
            StdTotalPage = (CurCourse->studentInfos().size() ? CurCourse->studentInfos().size() / MAX_STD +
                                                                   (bool)(CurCourse->studentInfos().size() % MAX_STD)
                                                             : 1);
            StdPages.setPage(StdNumPage, StdTotalPage);
            drawTexture(layer);
            return;
        }
        Texture.draw(viewScoreboard);
        if (viewScoreboard.isPressed(event))
        {
            layer = CrsScb;
            CourseScoreboardTable.drawTexture(CurCourse->studentInfos(), 1);
            ScbNumPage = 1;
            ScbTotalPage = (CurCourse->studentInfos().size() ? CurCourse->studentInfos().size() / MAX_STD +
                                                                   (bool)(CurCourse->studentInfos().size() % MAX_STD)
                                                             : 1);
            ScbPages.setPage(ScbNumPage, ScbTotalPage);
            UpdateScb.drawTexture(CurCourse->studentInfos().size(), 1);
            drawTexture(layer);
            return;
        }
        if (New)
        {
            Texture.draw(Update);
            Texture.draw(Delete);
            Texture.draw(AddStudent);
            Texture.draw(RemoveStudent);
            if (Update.isPressed(event))
            {
                layer = UpdCrs;
                resetFail();
                UpdateCourseScreen.FirstDraw((*CurCourse));
                drawTexture(layer);
                return;
            }
            if (Delete.isPressed(event))
            {
                if (fail == Clear)
                    fail = warning;
                else if (fail == warning)
                {
                    fail = Clear;
                    Backend::Course::deleteCourse(CurCourse->getID());
                    FirstDraw();
                    layer = Crs;
                }
                drawTexture(layer);
                return;
            }
            if (AddStudent.isPressed(event))
            {
                type = add;
                layer = CrsAStd;
                resetFail();
                StdID.erase();
                drawTexture(layer);
                return;
            }
            if (RemoveStudent.isPressed(event))
            {
                type = del;
                layer = CrsRStd;
                resetFail();
                StdID.erase();
                drawTexture(layer);
                return;
            }
        }
    }
    if (layer == UpdCrs)
    {
        UpdateCourseScreen.processEvent(event);
        Texture.draw(UpdateCourseScreen);
    }
    if (layer == CrsAStd)
    {
        if (StdID.checkEvent(event))
            Texture.draw(StdID);
        Texture.draw(StdConfirm);
        if (StdConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!StdID.getText().getSize())
                fail = Addempty;
            else
            {
                List<Backend::Student>::iterator Std = Backend::g_students.find_if(
                    [&](const Backend::Student &a) -> bool
                    { return a.getID() == StdID.getText(); });
                if (Std == Backend::g_students.end())
                    fail = StdnotFound;
                else if (!CurCourse->addStudent(&*Std))
                    fail = AddExist;
            }
            drawTexture(layer);
            return;
        }
    }
    if (layer == CrsRStd)
    {
        if (StdID.checkEvent(event))
            Texture.draw(StdID);
        Texture.draw(StdConfirm);
        if (StdConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!StdID.getText().getSize())
                fail = RmvEmpty;
            else if (!CurCourse->removeStudent(&*(Backend::g_students.find_if([&](const Backend::Student &a) -> bool
                                                                              { return a.getID() == StdID.getText(); }))))
                fail = RmvNotFound;
            drawTexture(layer);
            return;
        }
    }
    if (layer == CrsVStd)
    {
        bool Check = 0;
        StdPages.processEvent(event, StdNumPage, StdTotalPage, Check);
        if (Check)
        {
            StudentList.drawTexture(CurCourse->studentInfos(), StdNumPage);
            drawTexture(layer);
        }
        Texture.draw(StdPages);
    }
    if (layer == CrsScb)
    {
        bool Check = 0;
        ScbPages.processEvent(event, ScbNumPage, ScbTotalPage, Check);
        if (Check)
        {
            CourseScoreboardTable.drawTexture(CurCourse->studentInfos(), ScbNumPage);
            UpdateScb.drawTexture(CurCourse->studentInfos().size(), ScbNumPage);
            drawTexture(layer);
        }
        if (UpdateScb.isPressed(event))
        {
            layer = CrsUpdScb;
            auto Std = CurCourse->studentInfos().begin() + (ScbNumPage - 1) * MAX_STD + UpdateScb.getRow();
            CurStd.setString((*Std).student->getID());
            resetFail();
            std::stringstream s;
            s << (*Std).midtermMark;
            Mark[0].setText(s.str());
            s.str("");
            s << (*Std).finalMark;
            Mark[1].setText(s.str());
            s.str("");
            s << (*Std).otherMark;
            Mark[2].setText(s.str());
            s.str("");
            s << (*Std).totalMark;
            Mark[3].setText(s.str());

            for (int i = 0; i < numMark; i++)
            {
                Mark[i].drawTexture();
                std::cerr << (std::string)Mark[i].getText() << " ";
            }
            drawTexture(layer);
            return;
        }
        Texture.draw(UpdateScb);
        Texture.draw(ScbPages);
    }
    if (layer == CrsUpdScb)
    {
        for (int i = 0; i < numMark; i++)
            if (Mark[i].checkEvent(event))
                Texture.draw(Mark[i]);
        Texture.draw(MarkConfirm);
        if (MarkConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            for (int i = 0; i < numMark; i++)
            {
                float TmpMark;
                if (!Mark[i].getText().getSize())
                    TmpMark = 0;
                else
                    TmpMark = std::stof((std::string)Mark[i].getText());
                if (TmpMark > 10)
                    fail = markFail;
            }
            if (!fail)
            {
                auto Std = CurCourse->studentInfos().begin() + (ScbNumPage - 1) * MAX_STD + UpdateScb.getRow();
                (*Std).midtermMark = std::stof((std::string)Mark[0].getText());
                (*Std).finalMark = std::stof((std::string)Mark[1].getText());
                (*Std).otherMark = std::stof((std::string)Mark[2].getText());
                (*Std).totalMark = std::stof((std::string)Mark[3].getText());
            }
            drawTexture(layer);
        }
    }
}

bool ViewCourseWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == Crs)
        return CourseName.mouseOn(MousePos);
    if (layer == UpdCrs)
        return UpdateCourseScreen.mouseOn(MousePos, layer);
    if (layer == CrsAStd || layer == CrsRStd)
        return StdID.mouseOn(MousePos);
    if (layer == CrsUpdScb)
    {
        bool Check = 0;
        for (int i = 0; i < numMark; i++)
            Check |= Mark[i].mouseOn(MousePos);
        return Check;
    }
    return false;
}

void ViewCourseWindow::clearLine()
{
    resetFail();
    CourseName.erase();
}

void ViewCourseWindow::resetFail()
{
    fail = Clear;
}

ViewCourseWindow::~ViewCourseWindow()
{
    delete[] Mark;
    delete[] MarkTitle;
}
#include <CourseScoreboard.hpp>
#include <FrontendGlobal.hpp>
#include <string>
#include <sstream>
#include <iomanip>

// Constructor

CourseScoreboard::CourseScoreboard()
{
    x = 0;
    y = 0;
}

void CourseScoreboard::create(sf::Font &font)
{
    // Setup

    numRow = 1;
    height = 35;
    Cell = new TextBox[numCell];
    width = new int[numCell];
    pos = new int[numCell];

    // Title

    Title.setString("Scoreboard");
    Title.setFont(RegularFont);
    Title.setFillColor(sf::Color::Black);
    Title.setPosition(0, 0);
    Title.setCharacterSize(30);

    // First Row

    for (int i = 0; i < numCell; i++)
        Cell[i].setFontSize(18);
    width[0] = 70;
    width[1] = 100;
    width[2] = 120;
    width[3] = 450;
    width[4] = 100;
    width[5] = 100;
    width[6] = 100;
    width[7] = 100;
    pos[0] = 0;
    for (int i = 1; i < numCell; i++)
        pos[i] = pos[i - 1] + width[i - 1];
    for (int i = 0; i < numCell; i++)
    {
        // Cell[i].setFillColor(BackgroundColor);
        Cell[i].setFontSize(15);
        Cell[i].createTexture(width[i], height);
        Cell[i].setSize(width[i], height);
        Cell[i].setPosition(pos[i] + Offset_x, Offset_y);
        Cell[i].setTextPos();
        Cell[i].setTextColor(sf::Color::Black);
    }
    setFont(font);
    Cell[0].setText("No");
    Cell[1].setText("Class");
    Cell[2].setText("Student ID");
    Cell[3].setText("Student name");
    Cell[4].setText("Midterm");
    Cell[4].setCenter();
    Cell[5].setText("Final");
    Cell[5].setCenter();
    Cell[6].setText("Other");
    Cell[6].setCenter();
    Cell[7].setText("Total");
    Cell[7].setCenter();

    // Background

    Background.setSize(sf::Vector2f(pos[7] + width[7] + Offset_x, Offset_y + (MAX_ROW + 1) * height));
    Background.setFillColor(BackgroundColor);
    Texture.draw(Background);
    Texture.draw(Title);

    Background.setSize(sf::Vector2f(pos[7] + width[7], height * MAX_ROW));
    Background.setPosition(Offset_x, height + Offset_y);

    // Texture

    Texture.create(pos[7] + width[7] + Offset_x, Offset_y + (MAX_ROW + 1) * height);
    Texture.draw(Title);
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].drawTexture();
        Texture.draw(Cell[i]);
    }
    Texture.display();
}

// Text /////////////////////////////////////////////////////////////////////////////////

void CourseScoreboard::setFont(sf::Font &font)
{
    for (int i = 0; i < numCell; i++)
        Cell[i].setFont(font);
}

void CourseScoreboard::drawTexture(const List<Backend::Student::CourseInfo> &list, int page)
{
    int steps = min(list.size() - (page - 1) * MAX_ROW, MAX_ROW);
    numRow = steps + 1;
    auto Tmp = list.begin() + (page - 1) * MAX_ROW;
    Texture.draw(Background);
    std::stringstream s;
    for (int i = 0; i < steps; ++i)
    {
        Cell[0].setText(std::to_string((page - 1) * MAX_ROW + i + 1));
        Cell[1].setText((*Tmp).studentInfo->student->getClass()->getID());
        Cell[2].setText((*Tmp).studentInfo->student->getID());
        Cell[3].setText((*Tmp).studentInfo->student->getName());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).studentInfo->midtermMark;
        Cell[4].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).studentInfo->finalMark;
        Cell[5].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).studentInfo->otherMark;
        Cell[6].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).studentInfo->totalMark;
        Cell[7].setText(s.str());
        // Cell[4].setText(std::to_string((*Tmp).studentInfo->midtermMark));
        // Cell[5].setText(std::to_string((*Tmp).studentInfo->finalMark));
        // Cell[6].setText(std::to_string((*Tmp).studentInfo->otherMark));
        // Cell[7].setText(std::to_string((*Tmp).studentInfo->totalMark));
        for (int j = 0; j < numCell; j++)
        {
            if (j > 3)
                Cell[j].setCenter();
            else
                Cell[j].setTextPos();
            Cell[j].setPosition(pos[j] + Offset_x, Offset_y + (i + 1) * height);
            Cell[j].drawTexture();
            Texture.draw(Cell[j]);
        }

        ++Tmp;
    }
    Texture.display();
}

void CourseScoreboard::drawTexture(const List<Backend::Course::StudentInfo> &list, int page)
{
    int steps = min(list.size() - (page - 1) * MAX_ROW, MAX_ROW);
    numRow = steps + 1;
    auto Tmp = list.begin() + (page - 1) * MAX_ROW;
    Texture.draw(Background);
    std::stringstream s;
    for (int i = 0; i < steps; ++i)
    {
        Cell[0].setText(std::to_string((page - 1) * MAX_ROW + i + 1));
        Cell[1].setText((*Tmp).student->getClass()->getID());
        Cell[2].setText((*Tmp).student->getID());
        Cell[3].setText((*Tmp).student->getName());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).midtermMark;
        Cell[4].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).finalMark;
        Cell[5].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).otherMark;
        Cell[6].setText(s.str());
        s.str("");
        s << std::fixed << std::setprecision(2) << (*Tmp).totalMark;
        Cell[7].setText(s.str());
        // Cell[4].setText(std::to_string((*Tmp).midtermMark));
        // Cell[5].setText(std::to_string((*Tmp).finalMark));
        // Cell[6].setText(std::to_string((*Tmp).otherMark));
        // Cell[7].setText(std::to_string((*Tmp).totalMark));
        for (int j = 0; j < numCell; j++)
        {
            if (j > 3)
                Cell[j].setCenter();
            else
                Cell[j].setTextPos();
            Cell[j].setPosition(pos[j] + Offset_x, Offset_y + (i + 1) * height);
            Cell[j].drawTexture();
            Texture.draw(Cell[j]);
        }

        ++Tmp;
    }
    Texture.display();
}

void CourseScoreboard::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    // sprite.setTextureRect(sf::IntRect(0, 0, pos[numCell - 1] + width[numCell - 1], height * numRow));
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int CourseScoreboard::getHeight() const
{
    return Offset_y + height * (MAX_ROW + 1);
}

int CourseScoreboard::getWidth() const
{
    return pos[7] + width[7] + Offset_x;
}

sf::Vector2f CourseScoreboard::getPosition() const
{
    return sf::Vector2f(x, y);
}

int CourseScoreboard::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

void CourseScoreboard::setPosition(float a, float b)
{
    x = a;
    y = b;
}

// Destructor ////////////////////////////////////////////////////////////////////////////////////

CourseScoreboard::~CourseScoreboard()
{
    delete[] Cell;
    delete[] width;
    delete[] pos;
}

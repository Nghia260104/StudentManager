#pragma once
#include <TextBox.hpp>
#include <ButtonTable.hpp>
#include <StudentTable.hpp>
#include <CourseScoreboard.hpp>
#include <UpdateCourseWindow.hpp>
#include <Layer.hpp>
#include <Page.hpp>
#include <Course.hpp>

class ViewCourseWindow : public sf::Drawable
{
public:
    // Constructor

    ViewCourseWindow();
    void create();

    // Draw

    void Predraw();
    void FirstDraw();
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void clearLine();
    void resetFail();

    // Destructor

    ~ViewCourseWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, CourseInput;
    TextBox CourseName;
    Button CourseConfirm;
    sf::Text CourseFail, CourseEmptyFail;
    const int CrsNotFound = 10, CrsEmpty = 11;
    bool New = 0;
    ButtonTable CourseList;
    Page pages;
    int NumPage, TotalPage;
    List<Backend::Course>::iterator CurCourse;

    sf::Text Course;
    Button Update;
    Button Delete;
    Button AddStudent;
    Button RemoveStudent;
    Button viewStudent;
    Button viewScoreboard;

    // Delete Course

    sf::Text Caution, DeleteSuccess;
    static constexpr int warning = 4;

    // Update Course Information

    UpdateCourseWindow UpdateCourseScreen;

    // Add student

    sf::Text AddTitle;
    sf::Text AddFail, AddNotFound, AddEmptyFail, AddSuccess;
    const int AddExist = 5, Addempty = 6, StdnotFound = 10;

    // Remove student

    sf::Text RemoveTitle;
    sf::Text RemoveFail, RemoveEmptyFail, RemoveSuccess;
    const int RmvNotFound = 7, RmvEmpty = 8;

    // Add and remove window

    sf::Text StdTitle;
    TextBox StdID;
    Button StdConfirm;
    int type;
    const int add = 1, del = 2;

    // List of students

    StudentTable StudentList;
    Page StdPages;
    int StdNumPage, StdTotalPage;

    // Scoreboard

    CourseScoreboard CourseScoreboardTable;
    Page ScbPages;
    int ScbNumPage, ScbTotalPage;
    ButtonTable UpdateScb;

    // Update Scoreboard

    sf::Text UpdateScbTitle;
    sf::Text CurStd;
    sf::Text *MarkTitle;
    sf::Text MarkUpdFail, MarkUpdSuccess;
    TextBox *Mark;
    Button MarkConfirm;
    const int numMark = 4, markFail = 9;

    // Common

    int fail;
    const int Clear = INT_MAX, MAX_CRS = 30, MAX_STD = 15;
    const Layer Crs = Layer(1, 150),
                CrsF = Layer(2, 150),
                UpdCrs = Layer(3, 150),
                CrsAStd = Layer(3, 160),
                CrsRStd = Layer(3, 170),
                CrsVStd = Layer(3, 180),
                CrsScb = Layer(3, 190),
                CrsUpdScb = Layer(4, 190);
};
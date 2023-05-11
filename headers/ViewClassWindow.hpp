#pragma once
#include <TextBox.hpp>
#include <ButtonTable.hpp>
#include <StudentTable.hpp>
#include <PersonalScoreboard.hpp>
#include <UpdateStudentWindow.hpp>
#include <Layer.hpp>
#include <Page.hpp>
#include <Class.hpp>

class ViewClassWindow : public sf::Drawable
{
public:
    // Constructor

    ViewClassWindow();
    void create();

    // Draw

    void Predraw();
    void FirstDraw(const List<Backend::Class> &list);
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void resetFail();
    void clearLine();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, ClassInput;
    TextBox ClassName;
    Button ClassConfirm;
    sf::Text ClassFail, ClassEmptyFail;
    const int ClsNotFound = 1, ClsEmpty = 2;
    ButtonTable ClassList;
    Page ClsPages;
    int ClsNumPage, ClsTotalPage;
    List<Backend::Class>::iterator CurClass;
    const int MAX_CLS = 30;

    // List of students

    StudentTable StudentList;
    ButtonTable Function;
    Page StdPages;
    int StdNumPage, StdTotalPage;
    Backend::Student *CurStd;
    const int MAX_ROW = 15;

    // Update Student Information

    UpdateStudentWindow Update;

    // View student's scoreboard

    PersonalScoreboard Scoreboard;
    sf::Text GPATitle;
    Button GPA;
    Page ScbPages;
    int ScbNumPage, ScbTotalPage;

    // Common

    int fail;
    const int Clear = INT_MAX;
    const Layer VCls = Layer(1, 250),
                ClsStd = Layer(2, 250),
                ClsUpd = Layer(3, 250),
                ClsScb = Layer(3, 300);
};
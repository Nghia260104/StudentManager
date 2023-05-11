#pragma once
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>
#include <Course.hpp>

class UpdateCourseWindow : public sf::Drawable
{
public:
    // Constructor

    UpdateCourseWindow();
    void create();

    // Draw

    void Prepare();
    void FirstDraw(Backend::Course &course);
    void drawTexture();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void clearLine();

    // Destructor

    ~UpdateCourseWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, Smt, ScY, *Subtitle, EmptyFail, ClassFail, ExistFail, ZeroFail, Success;
    Button Semester;
    Button SchoolYear;
    TextBox *Cell;
    Button Confirm;
    Button *DoW;
    Button *Session;
    Backend::Course *CurCourse;
    int fail;
    const int numCell = 8, numDoW = 6, numSes = 4,
              empty = 1, ClassNotFound = 2, existed = 3, zero = 4, Clear = INT_MAX;
    const Layer UpdCrs = Layer(3, 150);
};
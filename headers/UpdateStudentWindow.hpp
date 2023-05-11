#pragma once
#include <TextBox.hpp>
#include <ButtonTable.hpp>
#include <Student.hpp>

class UpdateStudentWindow : public sf::Drawable
{
public:
    // Constructor

    UpdateStudentWindow();
    void create();

    // Draw

    void Prepare();
    void FirstDraw(Backend::Student *student);
    void drawTexture();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void clearLine();
    void resetFail();

    // Destructor

    ~UpdateStudentWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, Success, EmptyFail, DateFail, ExistFail, DOB;
    sf::Text *Subtitle;
    TextBox *Cell;
    Button Male, Female;
    Button Confirm;
    Backend::Student *CurStd = nullptr;
    int fail;
    const int numCell = 8,
              empty = 1, date = 2, existed = 3,
              Clear = INT_MAX;
};
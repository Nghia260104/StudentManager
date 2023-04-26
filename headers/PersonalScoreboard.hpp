#include <SFML/Graphics.hpp>
#include <FrontendGlobal.hpp>
#include <TextBox.hpp>

class PersonalScoreboard : public sf::Drawable
{
public:
    // Constructor

    PersonalScoreboard();
    void create();

    // Text

    void setFont(sf::Font &font);

    // Draw

    // void drawTexture()

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    float x, y;
    int size, *width, *pos, height, numRow;
    const int numCell = 5, MAX_ROW = 15;
    TextBox *Cell;
    sf::RenderTexture Texture;
    int min(int x, int y);
};

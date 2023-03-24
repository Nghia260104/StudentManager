// As its name, it's the main
#include <StudentManagement.hpp>

void getString(std::string &s, bool &check)
{
    if (check)
        return;
    char c = ' ';
    while (!check && (c = (char)GetCharPressed()))
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            check = 1;
            return;
        }
        // if (c == '\r')
        // {
        //     check = 1;
        //     return;
        // }
        s += c;
    }
    // std::cin.ignore();
}

int main(void)
{
    // Initialize Window

    int ScreenWidth = 800;
    int ScreenHeight = 680;
    raylib::Window window;
    InitializeWindow(window, ScreenWidth, ScreenHeight);

    // Load Font into variables

    raylib::Font RegularFont, BoldFont, MediumFont, LightFont, SemiBoldFont;
    LoadFonts(RegularFont, BoldFont, MediumFont, LightFont, SemiBoldFont);

    /////////////////////////////////////////////////////////////////////////////////////

    std::string S = "Test" + std::to_string(RegularFont.baseSize);
    textbox q;
    // q.Text = S;
    bool GotString = 0;
    while (!window.ShouldClose())
    {
        window.BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);
            q.setup(ScreenWidth / 2, ScreenHeight / 2, 100.0f, 75.0f);
            q.font(RegularFont);
            q.MouseCursor();
            q.CheckTyping();
            q.Edge(BLACK, GREEN);
            getString(q.Text, GotString);
            q.WriteText(BLACK);
        }
        window.EndDrawing();
    }
    q.~textbox();
    RegularFont.Unload();
    BoldFont.Unload();
    window.Close();
    return 0;
}

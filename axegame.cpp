#include <raylib.h>
#include <iostream>

using namespace std;
int main()
{
    int width{1350};
    int height{800};

    // Circle coordinates
    int circle_x{675};
    int circle_y{400};
    int radius{100};

    // Values for rectangle
    int pos_x{300};
    int pos_y{0};
    int rec_width{50};
    int rec_height{50};

    InitWindow(width, height, "Axe Master");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Game logic begins
        DrawCircle(circle_x, circle_y, radius, BLUE);
        DrawRectangle(pos_x, pos_y, rec_width, rec_height, RED);

        // Move the axe
        if (pos_y < 800)
            pos_y += 10;
        if (IsKeyDown(KEY_D) && circle_x < 1350)
        {
            circle_x = circle_x + 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x = circle_x - 10;
        }

        // Game logic ends
        EndDrawing();
    }
}
#include <raylib.h>
#include <iostream>

using namespace std;
int main()
{
    int width{720};
    int height{480};

    // Circle coordinates
    int radius{25};
    int circle_x{720 - radius};
    int circle_y{200};

    // Circle edges
    int l_circle_x{circle_x - radius};
    int r_circle_x{circle_x + radius};
    int u_circle_y{circle_y - radius};
    int b_circle_y{circle_y + radius};

    // Values for rectangle
    int pos_x{300};
    int pos_y{0};
    int axe_length{50};
    int direction{10};
    // axe edges
    int l_axe_x{pos_x};
    int r_axe_x{pos_x + axe_length};
    int u_axe_y{pos_y};
    int b_axe_y{pos_y + axe_length};

    // collision
    bool collision_with_an_axe = (b_axe_y >= u_circle_y) &&
                                 (u_axe_y <= b_circle_y) &&
                                 (l_axe_x <= r_circle_x) &&
                                 (r_axe_x >= l_circle_x);

    InitWindow(width, height, "Axe Master");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_an_axe)
        {
            DrawText("Game Over!", 360, 100, 23, RED);
        }
        else
        {

            // Update the edges
            l_circle_x = circle_x - radius;
            r_circle_x = circle_x + radius;
            u_circle_y = circle_y - radius;
            b_circle_y = circle_y + radius;

            l_axe_x = pos_x;
            r_axe_x = pos_x + axe_length;
            u_axe_y = pos_y;
            b_axe_y = pos_y + axe_length;

            // Update collision
            collision_with_an_axe = (b_axe_y >= u_circle_y) &&
                                    (u_axe_y <= b_circle_y) &&
                                    (l_axe_x <= r_circle_x) &&
                                    (r_axe_x >= l_circle_x);

            // Game logic begins
            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawRectangle(pos_x, pos_y, axe_length, axe_length, RED);

            // Move the axe
            pos_y += direction;
            if (pos_y > height || pos_y < 0)
            {
                direction = -direction;
            }
            if (IsKeyDown(KEY_D) && (circle_x + radius) < width)
            {
                circle_x = circle_x + 10;
            }
            if (IsKeyDown(KEY_A) && (circle_x - radius) > 0)
            {
                circle_x = circle_x - 10;
            }

            // Game logic ends
        }
        EndDrawing();
    }
}
#include <raylib.h>
#include <iostream>

using namespace std;
int main()
{
    int width = 1350;
    int height = 800;
    bool isEating{false};
    int milesToDisneyLand{100};
    InitWindow(width, height, "Hello World");
    while (true)
    {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
}
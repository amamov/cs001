#include <iostream>

using namespace std;

enum Colors
{
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE
};

void printColor(Colors color)
{
    switch (color)
    {
    case COLOR_BLACK:
        cout << "Black" << endl;
        break;
    case COLOR_WHITE:
        cout << "White" << endl;
        break;
    case COLOR_RED:
        cout << "Red" << endl;
        break;
    case COLOR_GREEN:
        cout << "Green" << endl;
        break;
    case COLOR_BLUE:
        cout << "Blue" << endl;
        break;
    default:
        cout << "Unknown" << endl;
        break;
    }
}

int main()
{
    printColor(COLOR_GREEN);
    return 0;
}

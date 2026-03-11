#include "Canvas.h"
#include <iostream>

int main() {
    Canvas cv(60, 20);

    cv.FillRect(2, 2, 12, 8, '+');
    cv.DrawRect(2, 2, 12, 8, 'B');

    cv.FillCircle(45, 10, 5, 'o');
    cv.DrawCircle(45, 10, 5, '@');

    cv.DrawLine(5, 18, 55, 18, '-');
    cv.DrawLine(0, 0, 59, 19, 'X');

    cv.SetPoint(30, 10, '!');

    cv.Print();

    cv.Clear();
    cv.SetPoint(0, 0, 'C');
    cv.Print();

    return 0;
}
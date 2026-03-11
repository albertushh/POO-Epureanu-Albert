#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char* [height];
    for (int i = 0; i < height; ++i) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j) {
            SetPoint(j, i, ch);
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int dx = 0;
    int dy = ray;
    int d = 3 - 2 * ray;
    while (dy >= dx) {
        SetPoint(x + dx, y + dy, ch); SetPoint(x - dx, y + dy, ch);
        SetPoint(x + dx, y - dy, ch); SetPoint(x - dx, y - dy, ch);
        SetPoint(x + dy, y + dx, ch); SetPoint(x - dy, y + dx, ch);
        SetPoint(x + dy, y - dx, ch); SetPoint(x - dy, y - dx, ch);
        if (d < 0) d = d + 4 * dx + 6;
        else {
            d = d + 4 * (dx - dy) + 10;
            dy--;
        }
        dx++;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = y - ray; i <= y + ray; i++) {
        for (int j = x - ray; j <= x + ray; j++) {
            if ((j - x) * (j - x) + (i - y) * (i - y) <= ray * ray) {
                SetPoint(j, i, ch);
            }
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = std::abs(x2 - x1);
    int dy = -std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << "\n";
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}
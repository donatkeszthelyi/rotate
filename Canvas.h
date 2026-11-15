#ifndef CANVAS_H
#define CANVAS_H

#include <cmath>
#include <iostream>
#include <vector>

class Point {
private:
    float x;
    float y;
    float z;

public:
    Point(float x, float y, float z) : x(x / z), y(y / z), z(z) {};

    void rotate(float angle);

    friend class Canvas;
};

class Canvas {
private:
    int width;
    int height;
    std::vector<Point> points;

public:
    Canvas(int width, int height) : width(width * 2), height(height) {};

    void addPoint(Point point);
    void render();
    void rotate(float angle);
};

#endif

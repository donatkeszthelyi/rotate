#include "Canvas.h"

using namespace std;

void Canvas::addPoint(Point point) { points.push_back(point); }

void Canvas::render() {
    cout << "\033[2J\033[1;1H";

    vector<vector<char>> screen(height, vector<char>(width, ' '));

    float cameraDistance = 10.0;

    for (const Point &point : points) {
        float depth = point.z + cameraDistance;

        if (depth <= 0.1)
            continue;

        float projectedX = point.x * cameraDistance / depth;
        float projectedY = point.y * cameraDistance / depth;

        int screenX = round(projectedX * 2 + width / 2);
        int screenY = round(-projectedY + height / 2);

        if (screenX >= 0 && screenX < width && screenY >= 0 && screenY < height) {
            screen[screenY][screenX] = '*';
        }
    }
    for (const auto &row : screen) {
        for (char pixel : row) {
            cout << pixel;
        }
        cout << endl;
    }
}

void Point::rotate(float angle) {
    const float radians = angle * (M_PI / 180.0f);

    float c = cos(radians);
    float s = sin(radians);

    float oldX = x;
    float oldZ = z;

    x = oldX * c - oldZ * s;
    z = oldX * s + oldZ * c;
}

void Canvas::rotate(float angle) {
    for (Point &point : points) {
        point.rotate(angle);
    }
}

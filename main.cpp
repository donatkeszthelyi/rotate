#include "Canvas.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {
    using namespace std::this_thread;
    using namespace std::chrono;
    Canvas canvas(21, 21);
    Point aa(-3, -3, 2);
    Point ab(-3, 3, 2);
    Point ac(3, -3, 2);
    Point ad(3, 3, 2);

    canvas.addPoint(aa);
    canvas.addPoint(ab);
    canvas.addPoint(ac);
    canvas.addPoint(ad);

    Point ba(-3, -3, -2);
    Point bb(-3, 3, -2);
    Point bc(3, -3, -2);
    Point bd(3, 3, -2);

    canvas.addPoint(ba);
    canvas.addPoint(bb);
    canvas.addPoint(bc);
    canvas.addPoint(bd);

    while (true) {
        canvas.render();
        canvas.rotate(10);
        sleep_for(milliseconds(100));
    }
    return 0;
}

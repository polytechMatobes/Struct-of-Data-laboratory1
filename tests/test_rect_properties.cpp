#include <cassert>
#include <iostream>
#include "../src/rect.hpp"

int main() {
    Rect r(0, 10, 0, 20);

    assert(r.getWidth() == 10);
    assert(r.getHeight() == 20);
    assert(r.getSquare() == 200);

    r.setWidth(50);
    assert(r.getWidth() == 50);
    assert(r.getSquare() == 1000);

    r.setHeight(5);
    assert(r.getHeight() == 5);
    assert(r.getSquare() == 250);

    std::cout << "Test Rect Properties: PASSED" << std::endl;
    return 0;
}

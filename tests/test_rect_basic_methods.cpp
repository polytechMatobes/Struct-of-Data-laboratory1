#include <cassert>
#include <iostream>
#include "../src/rect.hpp"

int main() {
    Rect r1(0, 10, 0, 20);
    assert(r1.getLeft() == 0);
    assert(r1.getRight() == 10);

    r1.setAll(5, 15, 25, 5);
    assert(r1.getLeft() == 5);
    assert(r1.getBottom() == 5);

    std::cout << "Test Rect Basic Methods: PASSED" << std::endl;
    return 0;
}

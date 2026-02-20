#include <cassert>
#include <iostream>
#include "../src/rect.hpp"

int main() {
    Rect r(10, 20, 20, 10);

    r.move(5, -5); 
    assert(r.getLeft() == 15);
    assert(r.getBottom() == 5);
    assert(r.getWidth() == 10);

    r.inflate(2);
    assert(r.getLeft() == 13);
    assert(r.getRight() == 27);
    assert(r.getWidth() == 14);

    std::cout << "Test Rect Operations: PASSED" << std::endl;
    return 0;
}

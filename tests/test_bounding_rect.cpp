#include <cassert>
#include <iostream>
#include <algorithm>
#include "../src/rect.hpp"

int main() {
    Rect r1(0, 10, 10, 0);
    Rect r2(5, 15, 15, 5);
    
    Rect res1 = boundingRect(r1, r2);
    
    assert(res1.getLeft() == 0);
    assert(res1.getRight() == 15);
    assert(res1.getTop() == 15);
    assert(res1.getBottom() == 0);

    Rect r3(50, 10, 5, 25); 
    Rect r4(20, 30, 10, 15);

    Rect res2 = boundingRect(r3, r4);

    assert(res2.getLeft() == 10);
    assert(res2.getRight() == 50);

    std::cout << "Test Bounding Rect: PASSED" << std::endl;
    return 0;
}

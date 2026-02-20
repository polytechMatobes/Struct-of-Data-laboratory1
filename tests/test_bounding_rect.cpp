#include <cassert>
#include <iostream>
#include <algorithm>
#include "../src/rect.hpp"

int main() {
    // Тест 1: Объединение двух обычных прямоугольников
    // r1: (0, 10, 10, 0) -> L=0, R=10, T=10, B=0
    // r2: (5, 15, 15, 5) -> L=5, R=15, T=15, B=5
    Rect r1(0, 10, 10, 0);
    Rect r2(5, 15, 15, 5);
    
    Rect res1 = boundingRect(r1, r2);
    
    assert(res1.getLeft() == 0);   // min(0, 5)
    assert(res1.getRight() == 15); // max(10, 15)
    assert(res1.getTop() == 15);   // max(10, 15)
    assert(res1.getBottom() == 0); // min(0, 5)

    // Тест 2: "Перепутанные" координаты (Задание 4.3)
    // Пользователь ввел r3 так, что Left > Right
    // r3: Left=50, Right=10, Top=5, Bottom=25
    Rect r3(50, 10, 5, 25); 
    Rect r4(20, 30, 10, 15);

    Rect res2 = boundingRect(r3, r4);

    // Чтобы этот тест прошел, функция boundingRect должна учитывать,
    // что r3.getLeft() на самом деле может быть БОЛЬШЕ, чем r3.getRight()
    // Ожидаем честный минимум и максимум среди всех четырех иксов:
    // X-координаты: 50, 10, 20, 30 -> min=10, max=50
    assert(res2.getLeft() == 10);
    assert(res2.getRight() == 50);

    std::cout << "Test Bounding Rect: PASSED" << std::endl;
    return 0;
}

#pragma once
#include <iostream>

class Rect {
int left;
int right;
int top;
int bottom;

public:
    Rect() {
        left = 0;
        right = 0;
        top = 0;
        bottom = 0;
        std::cout << "Вызван конструктор по умолчанию: " << this << std::endl;
    }

    Rect(int a, int b, int c, int d) {
        left = std::min(a, b);
        right = std::max(a, b);
        top = std::max(c, d);
        bottom = std::min(c, d);
        std::cout << "Вызван конструктор с параметрами: " << this << std::endl;
    }

    ~Rect(){std::cout << "Объект Rect уничтожен: " << this << std::endl;}

    Rect(const Rect& other):left(other.left), right(other.right), top(other.top), bottom(other.bottom){
        left = other.left;
        right = other.right;
        top = other.top;
        bottom = other.bottom;
        std::cout << "Вызван конструктор копирования объектов: " << this << std::endl;
    }

    int getLeft() const {return left;}
    int getRight() const {return right;}
    int getTop() const {return top;}
    int getBottom() const {return bottom;}
    void setAll(int a, int b, int c, int d){
        left = a;
        right = b;
        top = c;
        bottom = d;
    }
    void inflate(int amount){
        left -= amount;
        right += amount;
        top += amount;
        bottom -= amount;
    }

    void inflate(int dw, int dh){
        inflate(dw, dw, dh, dh);
    }

    void inflate(int dLeft, int dRight, int dTop, int dBottom){
        left += dLeft;
        right += dRight;
        top += dTop;
        bottom += dBottom;
    }

    void move(int dx = 0, int dy = 0){
        left += dx;
        right += dx;
        top += dy;
        bottom += dy;
    }

    int getWidth() const {return std::abs(right - left);}
    int getHeight() const {return std::abs(top - bottom);}
    int getSquare() const {return (getWidth() * getHeight());}

    void setWidth(int width){ right = left + width;}
    void setHeight(int height){ top = bottom + height;}
};

Rect boundingRect(const Rect& r1, const Rect& r2);
void printRect(Rect &r);



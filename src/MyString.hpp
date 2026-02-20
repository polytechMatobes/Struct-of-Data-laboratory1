#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <cstring>

class MyString {
private:
    char* m_data; // Указатель на динамическую память

    // Вспомогательный метод для глубокого копирования
    void copyFrom(const char* str);

public:
    // Конструкторы
    MyString();
    MyString(const char* str);
    
    // Правило трех: если есть деструктор, нужны конструктор копирования и оператор присваивания
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);

    // Деструктор
    ~MyString();

    // Методы
    char get(int i) const;
    void set(int i, char c);
    void setNewString(const char* str);
    void print() const;
    void readLine();
};

#endif

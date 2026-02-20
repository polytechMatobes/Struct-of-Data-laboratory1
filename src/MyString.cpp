#include "MyString.hpp"

// Вспомогательный метод для управления памятью
void MyString::copyFrom(const char* str) {
    if (str == nullptr) {
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

// Конструктор по умолчанию
MyString::MyString() {
    copyFrom("");
}

// Конструктор со строкой C-style
MyString::MyString(const char* str) {
    copyFrom(str);
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    copyFrom(other.m_data);
}

// Оператор присваивания
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_data; // Освобождаем старый ресурс
        copyFrom(other.m_data); // Берем новый
    }
    return *this;
}

// Деструктор — освобождаем память
MyString::~MyString() {
    delete[] m_data;
}

char MyString::get(int i) const {
    if (i < 0 || i >= (int)strlen(m_data)) return '\0';
    return m_data[i];
}

void MyString::set(int i, char c) {
    if (i >= 0 && i < (int)strlen(m_data)) {
        m_data[i] = c;
    }
}

void MyString::setNewString(const char* str) {
    delete[] m_data; // Старая память больше не нужна
    copyFrom(str);   // Выделяем новую нужного размера
}

void MyString::print() const {
    std::cout << m_data << std::endl;
}

// Реализация чтения строки неопределенной длины
void MyString::readLine() {
    delete[] m_data;
    
    int capacity = 16;
    int length = 0;
    char* buffer = new char[capacity];
    char ch;

    // Читаем посимвольно до переноса строки или конца файла
    while (std::cin.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            // Расширяем буфер в 2 раза
            capacity *= 2;
            char* newBuffer = new char[capacity];
            memcpy(newBuffer, buffer, length);
            delete[] buffer;
            buffer = newBuffer;
        }
        buffer[length++] = ch;
    }
    buffer[length] = '\0'; // Завершающий ноль

    // Чтобы не тратить лишнюю память, "подрежем" массив до реального размера
    m_data = new char[length + 1];
    strcpy(m_data, buffer);
    delete[] buffer;
}
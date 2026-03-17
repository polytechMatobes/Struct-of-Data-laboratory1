#include "MyString.hpp"


void MyString::copyFrom(const char* str) {
    if (str == nullptr) {
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}


MyString::MyString() {
    copyFrom("");
}

MyString::MyString(const char* str) {
    copyFrom(str);
}


MyString::MyString(const MyString& other) {
    copyFrom(other.m_data);
}


MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] m_data;
        copyFrom(other.m_data); 
    }
    std::cout << "Оператор = вызван" << std::endl;

    return *this;
}

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
    delete[] m_data; 
    copyFrom(str);   
}

void MyString::print() const {
    std::cout << m_data << std::endl;
}

void MyString::readLine() {
    delete[] m_data;
    
    int capacity = 16;
    int length = 0;
    char* buffer = new char[capacity];
    char ch;

    while (std::cin.get(ch) && ch != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char* newBuffer = new char[capacity];
            memcpy(newBuffer, buffer, length);
            delete[] buffer;
            buffer = newBuffer;
        }
        buffer[length++] = ch;
    }
    buffer[length] = '\0';

    m_data = new char[length + 1];
    strcpy(m_data, buffer);
    delete[] buffer;
}
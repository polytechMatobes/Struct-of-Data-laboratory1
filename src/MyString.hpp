#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <cstring>

class MyString {
private:
    char* m_data; 

   
    void copyFrom(const char* str);

public:
 
    MyString();
    MyString(const char* str);
    
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);

  
    ~MyString();

   
    char get(int i) const;
    void set(int i, char c);
    void setNewString(const char* str);
    void print() const;
    void readLine();
};

#endif

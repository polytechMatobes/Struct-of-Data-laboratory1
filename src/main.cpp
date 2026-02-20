#include <iostream>
#include "MyString.hpp"
#include "barrel.hpp"
//#include "matrix.hpp"
#include "rect.hpp"


int main() {
    {
        Rect r1(0, 4, 5 ,8), r2(2, 5, 5, 1);
        Rect r3 = boundingRect(r1, r2);
        printRect(r3);
        // Rect r;
        // std::cout << r.getLeft() << "; " << r.getRight() << '\n';
        // r.setAll(1, 2, 3, 4);
        // std::cout << r.getTop() << "; " << r.getBottom() << '\n';

        // Rect r1;
        // std::cout << r1.<имя_поля> << std::endl;


        // Rect r1;
        // Rect *pR = new Rect(1,2,1,2);   
        // {
        //     Rect r2(r1);
        //     Rect arRect[2];
        //     for(int i = 0; i < 3; i++)
        //     {
        //         static Rect r3 (i,i,i,i) ;
        //         std::cout << "Hello"<< std::endl;
        //         Rect r4(*pR);
        //         Rect r5(i,i,i,i);
        //     }
        // }
        // delete pR;


    // std::cout << "Начало main" << std::endl;
    // {
    //     Rect r1(1, 2, 3, 4);
    // }
    // Rect r2;
    // std::cout << "Конец main" << std::endl;


    // Rect rect(1, 2, 3, 4); 
    // Rect rect2;
}
    {
    Barrel alch(100.0, 96.0);
    Barrel water(100.0, 0.0);
    
    int iteration = 0;
    while (alch.getConcentration() > 50.0) {
        iteration++;
        water.transfuseFrom(alch, 1.0);
        alch.transfuseFrom(water, 1.0);
        std::cout << "Итерация " << iteration 
                  << ": Спирт в 1-й бочке = " << alch.getConcentration() << "%" << std::endl;

        if (iteration > 100000) break;
    }

    std::cout << "Ответ: Концентрация стала меньше 50% на итерации номер " << iteration << std::endl;
}
    // 1. Создание объектов через разные конструкторы
    MyString empty;              // По умолчанию: ""
    MyString hello("Привет");    // Со строкой C-style

    std::cout << "Начальное состояние:" << std::endl;
    std::cout << "Empty: "; empty.print();
    std::cout << "Hello: "; hello.print();

    // 2. Использование методов get и set
    std::cout << "\nРабота с символами:" << std::endl;
    char first = hello.get(0);
    std::cout << "Первый символ: " << first << std::endl;
    
    hello.set(0, 'p'); // Меняем 'П' на 'p'
    std::cout << "После изменения: "; hello.print();

    // 3. Замена строки (управление ресурсом)
    std::cout << "\nЗамена содержимого:" << std::endl;
    hello.setNewString("Динамическая строка");
    hello.print();

    // 4. Чтение из консоли (динамический размер)
    std::cout << "\nВведите любую длинную строку: ";
    MyString userString;
    userString.readLine(); // Можно ввести хоть целое предложение
    
    std::cout << "Вы ввели: ";
    userString.print();

    // 5. Демонстрация работы конструктора копирования
    // (Гарантирует, что при копировании выделится новая память)
    MyString copy = userString;
    std::cout << "Копия введённой строки: ";
    copy.print();

    {
        MyString s1;
        MyString s2 = s1;
        MyString s3("This is my string");
        MyString s4 = s3;
    }

    return 0; // Все деструкторы вызовутся автоматически здесь
}

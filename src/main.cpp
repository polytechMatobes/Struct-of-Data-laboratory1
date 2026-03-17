#include <iostream>
#include "MyString.hpp"
#include "barrel.hpp"
#include "matrix.hpp"
#include "rect.hpp"


int main() {
    {
        // Rect r1(0, 4, 5 ,8), r2(2, 5, 5, 1);
        // Rect r3 = boundingRect(r1, r2);
        // printRect(r3);

        // Matrix A(4);
        // Matrix B(3, 2, 1);
        // Matrix C(2, 2, 1.1);

        // B.set(0, 0, 3);
        // Matrix res = B.multiply(C);

        // res.printMatrix();
        // C.negate();
        // C.printMatrix();

        // Matrix D(3, 3, 1);
        // Matrix E(3, 3, 4);
        // D.addInPlace(E);
        // D.printMatrix();

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
//     {
//     Barrel alch(100.0, 96.0);
//     Barrel water(100.0, 0.0);
    
//     int iteration = 0;
//     while (alch.getConcentration() > 50.0) {
//         iteration++;
//         water.transfuseFrom(alch, 1.0);
//         alch.transfuseFrom(water, 1.0);
//         std::cout << "Итерация " << iteration 
//                   << ": Спирт в 1-й бочке = " << alch.getConcentration() << "%" << std::endl;

//         if (iteration > 100000) break;
//     }

//     std::cout << "Ответ: Концентрация стала меньше 50% на итерации номер " << iteration << std::endl;
// }
    MyString empty;
    MyString hello("Привет");

    std::cout << "Начальное состояние:" << std::endl;
    std::cout << "Empty: "; empty.print();
    std::cout << "Hello: "; hello.print();

    std::cout << "\nРабота с символами:" << std::endl;
    char first = hello.get(0);
    std::cout << "Первый символ: " << first << std::endl;
    
    hello.set(0, 'p');
    std::cout << "После изменения: "; hello.print();

    std::cout << "\nЗамена содержимого:" << std::endl;
    hello.setNewString("Динамическая строка");
    hello.print();

    std::cout << "\nВведите любую длинную строку: ";
    MyString userString;
    userString.readLine();
    
    std::cout << "Вы ввели: ";
    userString.print();

    MyString copy = userString;
    std::cout << "Копия введённой строки: ";
    copy.print();

    {
        MyString s1;
        MyString s2 = s1;
        MyString s3("This is my string");
        MyString s4 = s3;
        s2 = s3;
    }
    int* a = new int;
    
    return 0;
}

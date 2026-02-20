#include "rect.hpp"
#include <iostream>
#include <algorithm>




// int man()
//     {
//         Rect r1(0, 4, 5 ,8), r2(2, 5, 5, 1);
//         Rect r3 = boundingRect(r1, r2);
//         printRect(r3);
//         // Rect r;
//         // std::cout << r.getLeft() << "; " << r.getRight() << '\n';
//         // r.setAll(1, 2, 3, 4);
//         // std::cout << r.getTop() << "; " << r.getBottom() << '\n';

//         // Rect r1;
//         // std::cout << r1.<имя_поля> << std::endl;


//         // Rect r1;
//         // Rect *pR = new Rect(1,2,1,2);   
//         // {
//         //     Rect r2(r1);
//         //     Rect arRect[2];
//         //     for(int i = 0; i < 3; i++)
//         //     {
//         //         static Rect r3 (i,i,i,i) ;
//         //         std::cout << "Hello"<< std::endl;
//         //         Rect r4(*pR);
//         //         Rect r5(i,i,i,i);
//         //     }
//         // }
//         // delete pR;


//     // std::cout << "Начало main" << std::endl;
//     // {
//     //     Rect r1(1, 2, 3, 4);
//     // }
//     // Rect r2;
//     // std::cout << "Конец main" << std::endl;


//     // Rect rect(1, 2, 3, 4); 
//     // Rect rect2;

//     return 0;
// }

Rect boundingRect(const Rect& r1, const Rect& r2){
    int newLeft = std::min(r1.getLeft(), r2.getLeft());
    int newRight = std::max(r1.getRight(), r2.getRight());
    int newTop = std::max(r1.getTop(), r2.getTop());
    int newBottom = std::min(r1.getBottom(), r2.getBottom());

    return Rect(newLeft, newRight, newTop, newBottom);
}

void printRect(Rect &r){
    std::cout << "Rect: [Left: " << r.getLeft() << ", Right: " << r.getRight() 
              << ", Top: " << r.getTop() << ", Bottom: " << r.getBottom() << "]" << std::endl; 
}
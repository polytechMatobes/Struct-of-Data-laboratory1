#include "barrel.hpp"
#include <iostream>

void Barrel::transfuseFrom(Barrel &other, double cupVolume) {
        double alcoholInCup = other.alcoholVolume * (cupVolume / other.totalVolume);

        other.alcoholVolume -= alcoholInCup;

        this->alcoholVolume += alcoholInCup;

    }

// int master() {
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

//     return 0;
// }



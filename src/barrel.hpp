#pragma once

class Barrel {
private:
    double alcoholVolume;
    double totalVolume;

public:
    Barrel(double volume, double concentration) {
        totalVolume = volume;
        alcoholVolume = volume * (concentration / 100.0);
    }

    double getConcentration() const {
        return (alcoholVolume / totalVolume) * 100.0;
    }

    void transfuseFrom(Barrel &other, double cupVolume);
};

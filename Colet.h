#ifndef OOP_COLET_H
#define OOP_COLET_H

#include <iostream>
#include <vector>
#include "Curier.h"


class Colet {
protected:
    int AWB = 0;
    std :: string nume = "";
    float greutate = 0;
    float distanta = 0;
    std :: string detalii = "";
    int stare_colet = 0;
    Curier curier;
public :
    Colet(int AWB_, const std :: string& nume_, float greutate_, float distanta_, const std :: string& detalii_, int stare_colet_, const Curier& curier_);

    Colet(const Colet &other) = default;

    Colet &operator=(const Colet &other) = default;

    friend std :: ostream &operator<<(std :: ostream &os, const Colet &client_);

    void Depunere_Colet(Colet colet_1);

    void generare_AWB(Colet colet_1);

    int getAWB() const;

    void Starea_colet(Colet colet_1);
};


#endif //OOP_COLET_H

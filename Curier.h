#ifndef OOP_CURIER_H
#define OOP_CURIER_H

#include <iostream>
#include <vector>

class Curier {
protected:
    std :: string nume;
    std :: string telefon;
    std :: string masina;
    int stare_masina;
    int salariu;
    int livrari_efectuate;

public:
    Curier(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_);

    Curier(const Curier &other) = default;

    Curier &operator=(const Curier &other) = default;

    friend std :: ostream &operator<<(std :: ostream &os, const Curier &client_);

    void get_curier(Curier curier_1);
};


#endif //OOP_CURIER_H

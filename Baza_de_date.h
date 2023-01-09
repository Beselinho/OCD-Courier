#ifndef OOP_BAZA_DE_DATE_H
#define OOP_BAZA_DE_DATE_H

#include <iostream>
#include <vector>
#include "Curier.h"
#include "Colet.h"

class Baza_de_date {
    std :: vector<std::shared_ptr<Colet>> all_colete;
public:

    std :: vector<std::shared_ptr<Curier>> all_curieri;

    ~Baza_de_date() = default;

    void total_salarii ();

    template<class T> void adaugare_curieri(std::string nume_, std::string telefon_, std::string masina_, int stare_masina_, int salariu_, int livrari_);

};


#endif //OOP_BAZA_DE_DATE_H

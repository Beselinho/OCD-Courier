#ifndef OOP_EVIDENTA_CURIERI_H
#define OOP_EVIDENTA_CURIERI_H

#include <iostream>
#include <vector>
#include "Curier.h"
#include "Colet.h"

class Evidenta_curieri {
    //std :: vector<std::shared_ptr<Colet>> all_colete;
public:

    std :: vector<std::shared_ptr<Curier>> all_curieri;

    ~Evidenta_curieri() = default;

    void total_salarii ();

    template<class T> void adaugare_curieri(std::string nume_, std::string telefon_, std::string masina_, int stare_masina_, int salariu_, int livrari_);

};

template <class T> void Evidenta_curieri ::adaugare_curieri(std::string nume_, std::string telefon_, std::string masina_, int stare_masina_, int salariu_, int livrari_) {
    // Curier_de_zi crz_1{"Pintea", "0747399860", "Dacia", 1, 3650, 1};
    this->all_curieri.push_back(std::make_shared<T>(nume_,telefon_,masina_,stare_masina_,salariu_,livrari_));
}
#endif //OOP_EVIDENTA_CURIERI_H

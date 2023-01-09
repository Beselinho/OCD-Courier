#include "Baza_de_date.h"
#include <iostream>
#include "Curier.h"

void Baza_de_date::total_salarii() {
    double total_sal = 0;
    for(unsigned long long i = 0; i < all_curieri.size(); i++){
        std :: shared_ptr p = std ::dynamic_pointer_cast<Curier_de_noapte>(all_curieri.at(i));
        if(p == nullptr){
            std :: cout << "Acesta nu este un curier de noapte!";
            std :: shared_ptr p1 = std ::dynamic_pointer_cast<Curier_de_zi>(all_curieri.at(i));
            total_sal = total_sal + p1->getSal();
        }
        else {
            p->bonus_salariu();
            total_sal = total_sal + p->getSal();
        }
    }
}

template <class T> void Baza_de_date ::adaugare_curieri(std::string nume_, std::string telefon_, std::string masina_, int stare_masina_, int salariu_, int livrari_) {
    // Curier_de_zi crz_1{"Pintea", "0747399860", "Dacia", 1, 3650, 1};
    this->all_curieri.push_back(std::make_shared<T>(nume_,telefon_,masina_,stare_masina_,salariu_,livrari_));
}

#include "Baza_de_date.h"
#include <iostream>
#include "Curier.h"

void Baza_de_date::total_salarii(/*Curier c1*/) {
    double total_sal = 0;
    for(auto i = all_curieri.begin(); i <= all_curieri.end(); i++){
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

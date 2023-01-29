#include <iostream>
#include "Evidenta_curieri.h"

void Evidenta_curieri::total_salarii() {
    double total_sal = 0;
    for(unsigned long long i = 0; i < all_curieri.size(); i++){
        std :: shared_ptr p = std ::dynamic_pointer_cast<Curier_de_noapte>(all_curieri.at(i));
        if(p == nullptr){
            //std :: cout << "Acesta nu este un curier de noapte!";
            std :: shared_ptr p1 = std ::dynamic_pointer_cast<Curier_de_zi>(all_curieri.at(i));
            total_sal = total_sal + p1->getSal();
        }
        else {
            p->bonus_salariu();
            total_sal = total_sal + p->getSal();
        }
    }
    std :: cout << total_sal << "\n";
}



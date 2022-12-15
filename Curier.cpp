#include "Curier.h"

Curier ::Curier(const std :: string& nume_, const std :: string& telefon_, const std :: string& masina_, int stare_masina_, int salariu_, int livrari_efectuate_) :
                nume{nume_}, telefon{telefon_}, masina{masina_}, stare_masina{stare_masina_}, salariu{salariu_}, livrari_efectuate{livrari_efectuate_} {}

std :: ostream& operator<<(std::ostream& os, const Curier& cr){
    os << "Nume Curier :" << cr.nume << "\n";
    os << "Numar de telefon: " << cr.telefon  <<"\n";
    os << "Masina : " << cr.masina;
    os << "Stare masinii :"<< cr.stare_masina << "\n" ;
    os << "Salariu (in RON): " << cr.salariu << "\n" ;
    os << "Livrari efectuate :" << cr.livrari_efectuate << "\n";
    return os;
}

void Curier::get_curier(Curier curier_1) {
        if(curier_1.stare_masina == 1)
            std :: cout << "Coletul va fi preluat de catre curierul " << curier_1.nume << "\n";
}

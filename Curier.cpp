//#include <vector>
#include "Curier.h"

Curier ::Curier(const std :: string& nume_, const std :: string& telefon_, const std :: string& masina_, int stare_masina_, int salariu_, int livrari_efectuate_) :
                nume{nume_}, telefon{telefon_}, masina{masina_}, stare_masina{stare_masina_}, salariu{salariu_}, livrari_efectuate{livrari_efectuate_} {}
Curier ::Curier(){
    nr_curieri++;
}
std :: ostream& operator<<(std::ostream& os, const Curier& cr){
    os << "Nume Curier :" << cr.nume << "\n";
    os << "Numar de telefon: " << cr.telefon  <<"\n";
    os << "Masina : " << cr.masina;
    os << "Stare masinii :"<< cr.stare_masina << "\n" ;
    os << "Salariu (in RON): " << cr.salariu << "\n" ;
    os << "Livrari efectuate :" << cr.livrari_efectuate << "\n";
    return os;
}

Curier_de_zi ::Curier_de_zi(const std::string &nume_, const std::string &telefon_, const std::string &masina_, int stare_masina_, int salariu_, int livrari_efectuate_) :
        Curier(nume_, telefon_, masina_, stare_masina_, salariu_, livrari_efectuate_) {}



Curier_de_noapte ::Curier_de_noapte(const std::string &nume_, const std::string &telefon_, const std::string &masina_, int stare_masina_, int salariu_, int livrari_efectuate_ ) :
        Curier(nume_, telefon_, masina_, stare_masina_, salariu_, livrari_efectuate_) {}

int Curier::getSal() const {
    return salariu;
}

double Curier_de_noapte::bonus_salariu() {
    double bonus;
        bonus = spor_de_noapte * salariu;
        salariu = salariu + bonus;
    return salariu;
}


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



Curier_de_zi ::Curier_de_zi(const std::string &nume_, const std::string &telefon_, const std::string &masina_, int stare_masina, int salariu_, int livrari_efectuate_, int experienta_) :
        Curier(nume_, telefon_, masina_, stare_masina, salariu_, livrari_efectuate_), experienta(experienta_) {}

double Curier_de_zi::bonus_salariu() const {
    double bonus = 0;
        if(experienta <= 5)
            bonus = 0.1 * salariu;
        else
            if(experienta <= 15)
                bonus = 0.25 * salariu;
            else
                    bonus = 0.35 * salariu;
    std :: cout << "Totalul de bonus : " << bonus << "\n";
    return 1;
}

void Curier_de_zi::lista_curieri_1(Curier* curier_) {
    if(auto* cr = dynamic_cast<Curier_de_zi*>(curier_)) {
        std::cout << nume;
        cr->livrari_efectuate++;
    }
    else
        std :: cout << "nobun";
}

Curier_de_noapte ::Curier_de_noapte(const std::string &nume_, const std::string &telefon_, const std::string &masina_, int stare_masina, int salariu_, int livrari_efectuate_,
                                    int experienta_, double spor_de_noapte_) :
                   Curier(nume_, telefon_, masina_, stare_masina, salariu_, livrari_efectuate_), experienta(experienta_),spor_de_noapte(spor_de_noapte_) {}

double Curier_de_noapte::bonus_salariu() const {
    double bonus = 0;
        if(experienta <= 5)
            bonus = 0.1 * salariu + spor_de_noapte * salariu;
        else
            if(experienta <= 15)
                bonus = 0.25 * salariu + spor_de_noapte * salariu;
                else
                        bonus = 0.35 * salariu + spor_de_noapte * salariu;

    std :: cout << "Totalul de bonus : " << bonus << "\n";
    return 1;
}

void ::Curier_de_noapte::lista_curier_2(Curier& curier_) const {
    if(auto* cr = dynamic_cast<Curier_de_noapte*>(&curier_)) {
        std::cout << nume;
        cr->livrari_efectuate++;
    }
    else
        std :: cout << "nobun";
}
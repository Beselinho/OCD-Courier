
#include "Colet.h"
#include <random>
#include "Exceptii.h"

Colet :: Colet (int AWB_, const std :: string& nume_, float greutate_, float distanta_, const std :: string& detalii_, int stare_colet_, const Curier curier1_) :
        AWB{AWB_}, nume{nume_}, greutate{greutate_}, distanta{distanta_}, detalii{detalii_}, stare_colet{stare_colet_}, curier1{curier1_} {}

std :: ostream& operator<<(std::ostream& os, const Colet& c){
    os << "AWB : " << c.AWB  <<"\n";
    os << "Denumire :" << c.nume << "\n";
    os << "Greutate (in kg) :"<< c.greutate << "\n" ;
    os << "Distanta (in km): " << c.distanta << "\n" ;
    os << "Detalii :" << c.detalii << "\n";
    os << "Pret (in RON) :" << c.greutate * c.distanta << "\n";

    return os;
}

void Colet::Depunere_Colet() {
    std :: cout << "Completati datele coletului : "<< "\n";
    std :: cout << "Nume colet :" << "\n";
    std :: cin >> nume;
    std :: cout << "Greutate colet :" << "\n";
    std :: cin >> greutate;
    std :: cout << "Distanta (in km) :" << "\n";
    std :: cin >> distanta;
    std :: cout << "Pretul (in RON) pentru colet este :" << (distanta * greutate) << "\n";

        if (greutate == 0)
            throw eroare_colet("Nu s-a introdus greutatea coletului");
        if (distanta == 0)
            throw eroare_colet("Nu s-a introdus distanta");
}

void Colet::generare_AWB(Colet colet_1) {
    std::random_device rd;
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<> dist(1000000,9999999);
    auto random_number = dist(engine);
    colet_1.AWB = random_number;

    std :: cout << "AWB-ul coletului dvs este :" << colet_1.AWB << "\n";

    if (colet_1.AWB == 0)
        throw eroare_colet("Nu s-a creat AWB pentru colet");
}

int Colet :: getAWB() const {
    return AWB;
}

int Colet::getStareColet() const {
    return stare_colet;
}

double Colet::get_pret() const {
    return distanta * greutate;
}

void Colet::Starea_colet(Colet colet_1) {
    if(colet_1.distanta <= 60)
        colet_1.stare_colet = 2;
    else
    if(colet_1.distanta <= 250)
        colet_1.stare_colet = 1;
    else
    if(colet_1.distanta > 250)
        colet_1.stare_colet = 0;

    switch(colet_1.stare_colet){
        case 0 :
            std :: cout << "Coletul " << colet_1.nume << " urmeaza sa fie ridicat de catre curier";
            break;
        case 1 :
            std :: cout << "Coletul " << colet_1.nume << " a fost ridicat de cater curieri si este in drum spre destinatar";
            break;
        case 2:
            std :: cout << "Coletul " << colet_1.nume << " va fi livrat in curand !";
            break;
    }

}

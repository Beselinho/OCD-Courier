#include "Factura.h"
#include "Exceptii.h"

Factura::Factura(double suma_,const Colet& colet_) : suma(suma_), colet(colet_) {}

std :: ostream& operator<<(std::ostream& os, const Factura& f){
    os << f.suma;
    return os;
}

double Factura::Verificare() const {
    try {
        if (suma <= colet.get_pret()){
            throw eroare_plata("Suma platita nu e buna");
            std::cout << "bun";
        }
    }catch (eroare_plata &err){
        std :: cout << err.what() << "\n";
    }

    return 1;
}

Factura_card::Factura_card(double suma_, const Colet &colet_, const std::string &nume_card_, const std::string &iban_) :
              Factura(suma_, colet_), nume_card(nume_card_), iban(iban_) {}



#include "Factura_electronica.h"

Factura_electronica::Factura_electronica(double suma, const Colet &colet, const std::string &numeCard,
                                         const std::string &iban, const std::string &denumireSitePlata) : Factura_card(
        suma, colet, numeCard, iban), denumire_site_plata(denumireSitePlata) {}

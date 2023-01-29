#ifndef OOP_FACTURA_ELECTRONICA_H
#define OOP_FACTURA_ELECTRONICA_H


#include "Factura.h"

class Factura_electronica : public Factura_card{
    std :: string denumire_site_plata;
public:
    Factura_electronica(double suma, const Colet &colet, const std::string &numeCard, const std::string &iban,
                        const std::string &denumireSitePlata);

    ~Factura_electronica() override = default;



};


#endif //OOP_FACTURA_ELECTRONICA_H

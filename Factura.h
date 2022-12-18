
#ifndef OOP_FACTURA_H
#define OOP_FACTURA_H

#include <iostream>
#include <vector>
#include "Colet.h"
#include "Clienti.h"

class Colet;

class Factura {
private:
    double suma;
    Colet colet;
public:

    Factura(double suma_, const Colet& colet_);

    friend std :: ostream &operator<<(std :: ostream &os, const Factura &client_);

    double Verificare() const;

    virtual ~Factura() = default;

};

class Factura_card : public Factura{
private:
    std :: string nume_card;
    std :: string iban;
public:
    Factura_card(double suma_, const Colet& colet_, const std::string& nume_card_, const std::string& iban_);

};


#endif //OOP_FACTURA_H

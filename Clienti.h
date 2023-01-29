#ifndef OOP_CLIENTI_H
#define OOP_CLIENTI_H

#include <iostream>
#include <vector>
#include <random>
#include "Colet.h"
#include "Factura.h"

using std :: string;
using std :: vector;

class Client {
private :
    //virtual void afisare (std :: ostream &) const;
protected:
    std :: string nume;
    std :: string prenume;
    std :: string telefon;
    std :: string adresa;
    int rating_serviciu;

    Client(const string& nume_, const string& prenume_, const string& telefon_, const string& adresa_, int rating_serviciu_);
    Client() = default;
    Client(const Client& other) = default;
    Client &operator=(const Client& other);
public:
    friend std :: ostream &operator<<(std :: ostream &os, const Client &client_);

    virtual std::shared_ptr<Client> clone() const = 0;

    virtual ~Client() = default;

    virtual void Evaluare_servicii() const = 0;
};

class Colet;

class Expeditor : public Client{
private:
    Colet colet1;
    std :: vector<Colet> colete;
public:

    Expeditor(const string &nume, const string &prenume, const string &telefon, const string &adresa,
              int ratingServiciu, const Colet &colet1);
    //Expeditor() = default;

    ~Expeditor() override = default;

    void add_colet(Colet colet);

    void  Cautare_AWB(const int &AWB);

    void Anulare_colet(const int& AWB);

    void Evaluare_servicii() const override;

    std::shared_ptr<Client> clone() const override { return std::make_shared<Expeditor>(*this); }

};

class Destinatar : public Client{
private:
    int cod_primire = 0;
public:
    Destinatar(const string &nume, const string &prenume, const string &telefon, const string &adresa,
               int ratingServiciu, int codPrimire);

    Destinatar() = default;

    ~Destinatar() override = default;


    void generare_cod_primire();

    void Evaluare_servicii() const override;

    void plata_ramburs(Factura const &);

    std::shared_ptr<Client> clone() const override { return std::make_shared<Destinatar>(*this); }


};

#endif //OOP_CLIENTI_H

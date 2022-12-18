#ifndef OOP_CLIENTI_H
#define OOP_CLIENTI_H

#include <iostream>
#include <vector>
#include <random>
#include "Colet.h"

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

    Client(const string& nume_, const string& prenume_, const string& telefon_, const string& adresa_);
    Client(const Client& other) = default;
    Client &operator=(const Client& other);
public:
    friend std :: ostream &operator<<(std :: ostream &os, const Client &client_);

    virtual ~Client() = default;
};

class Colet;

class Expeditor : public Client{
private:
    Colet colet1;
    std :: vector<Colet> colete;
public:

    Expeditor(const string& nume_, const string& prenume_, const string& telefon_, const string& adresa_, const Colet& colet1_);

    void add_colet(Colet colet);

    void  Cautare_AWB(const int &AWB);

    void Anulare_colet(const int& AWB);


    //Expeditor(const char string[5], const char string1[8], const char string2[12], const char string3[14], Colet colet);
};

class Destinatar : public Client{
private:
    int cod_primire;
public:
    Destinatar(const string& nume_, const string& prenume_, const string& telefon_, const string& adresa_, int cod_primire);

    void generare_cod_primire(Destinatar dest_1);
};

#endif //OOP_CLIENTI_H

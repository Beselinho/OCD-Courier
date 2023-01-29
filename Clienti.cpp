//
// Created by pisc0 on 12/12/2022.
//

#include "Clienti.h"
//#include "Colet.h"

Client &Client::operator=(const Client &other) {
    nume = other.nume;
    prenume = other.prenume;
    telefon = other.telefon;
    adresa = other.adresa;
    return *this;
}

Client :: Client(const string& nume_, const string& prenume_, const string& telefon_, const string& adresa_) :
        nume{nume_}, prenume{prenume_}, telefon{telefon_}, adresa{adresa_} {}

std :: ostream& operator<<(std::ostream& os, const Client& cl){
    os << "Nume:" << cl.nume << "\n";
    os << "Prenume: " << cl.prenume <<"\n";
    os << "Telefon :"<< cl.telefon  << "\n" ;
    os << "Adresa: " << cl.adresa << "\n" ;
    return os;
}

Expeditor::Expeditor(const std::string &nume_, const std::string &prenume_, const std::string &telefon_,
                     const std::string &adresa_, const Colet &colet1_) : Client(nume_,prenume_,telefon_,adresa_),
                                                                         colet1(colet1_){}


void Expeditor::add_colet(Colet colet) {
    colete.push_back(colet);
}
void Expeditor::Cautare_AWB(const int &AWB) {
    auto cauta_AWB  = [AWB](auto colet){
        return colet.getAWB() == AWB;
    };
    auto i = std :: find_if (std :: begin(colete), std :: end(colete), cauta_AWB);
    if(i == std::end(colete))
        std::cout << "Nu exista colet cu acest AWB !";
    else
        std::cout << "\n";
    //return i;
}

void Expeditor::Anulare_colet(const int &AWB) {
    auto cauta_AWB = [AWB](auto colet){
        return colet.getAWB() == AWB;
    };
    auto i = std::find_if(std::begin(colete), std::end(colete), cauta_AWB);
    if(i != colete.end()){
        colete.erase(i);
        std :: cout << "Coletul cu AWB-ul " << AWB <<" a fost anulat";
    }
    else
        std::cout << "Nu exista colet cu acest AWB";
}
void Expeditor::Evaluare_servicii() const {
    if(colet1.getStareColet() < 1)
        std :: cout << "Servicii foarte bune";
    else
        std :: cout << "Servicii nobun";
}
Destinatar ::Destinatar(const std::string &nume_, const std::string &prenume_, const std::string &telefon_, const std::string &adresa_, int cod_primire_) :
             Client(nume_, prenume_, telefon_, adresa_), cod_primire{cod_primire_} {}

void Destinatar::generare_cod_primire() {
    std::random_device rd;
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<> dist(1000,9999);
    auto random_number = dist(engine);
    cod_primire = random_number;

    std :: cout << "Codul este :" << cod_primire << "\n";
}

void Destinatar::Evaluare_servicii() const {
    if(rating_serviciu > 0)
    std :: cout <<"\nServicii bune";
    else
        std :: cout << "\nServicii nobun";
}

void Destinatar::plata_ramburs(Factura &f) {
    if(f.Verificare()){
        std :: cout << "\nOptiune noua";
        this->rating_serviciu++;
    }

    
    std :: cout << "\nPlata cu ramburs efectuata!";
}
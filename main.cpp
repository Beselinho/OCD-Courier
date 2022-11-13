#include <iostream>
#include <string>

class Clienti{
protected:
        std :: string nume;
        std :: string prenume;
        std :: string telefon;
        std :: string adresa;
public:
    Clienti(const std :: string& nume_, const std :: string& prenume_ , const std :: string& telefon_, const std :: string& adresa_) : nume{nume_}, prenume{prenume_}, telefon{telefon_}, adresa{adresa_}{};
    Clienti(const Clienti & other) : nume(other.nume), prenume(other.prenume), telefon(other.telefon), adresa(other.adresa){};

    virtual ~Clienti();
    virtual void afisare(std :: ostream &out);
    virtual void citire(std :: istream &in);

    friend std :: ostream& operator<<(std :: ostream& out, Clienti&);
    friend std :: istream& operator>>(std :: istream& in, Clienti&);
};

Clienti :: ~Clienti(){
    nume = "";
    prenume = "";
    telefon = "";
    adresa ="";
}

std :: istream& operator>>(std :: istream& in, Clienti& cl){
    cl.citire(in);
    return in;
}

void Clienti ::citire(std::istream &in) {
    //std :: cout << "\n" << "Introduceti datele dumneavoastra :" << "\n";
    std :: cout << "\n";
    std :: cout << "Nume :";
    in >> nume;
    std :: cout << "Prenume :";
    in >> prenume;
    std :: cout << "Numarul de telefon :";
    in >> telefon;
    std :: cout << "Adresa :";
    in.get();
    std :: string aux;
    std::getline(in,aux);
    adresa = aux;
}
std::ostream& operator<<(std :: ostream& out, Clienti& cl){
    cl.afisare(out);
    return out;
}

void Clienti ::afisare(std::ostream &out){
    out << "Numele : "<< nume << "\n";
    out << "Prenumele :" << prenume << "\n";
    out << "Telefonul : "<< telefon << "\n";
    out << "Adresa :"<< adresa << "\n";
}

class Curieri{
    std :: string nume;
    std :: string telefon;
    std :: string adresa;
    std :: string masina;
    int stare_masina;
    int disponibilitate;
    int salariu;

    friend class Colete;
public:
    Curieri(const std :: string& nume_, const std :: string& telefon_,  const std :: string& adresa_, const std :: string& masina_, int stare_masina_, int disponibilitate_, int salariu_) :
             nume{nume_}, telefon{telefon_}, adresa{adresa_}, masina{masina_}, stare_masina{stare_masina_}, disponibilitate{disponibilitate_} ,salariu{salariu_}{
        //std :: cout << "intializare\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Curieri& cr){
        os << "Informatii despre curier: " << "\n" << "Nume: "<< cr.nume << "\n" << "Numar de telefon: " << cr.telefon << "\n" << "Adresa: " << cr.adresa <<"\n"
            << "Masina curierului :"<<cr.masina << "\n" << "Stare masinii :"<< cr.stare_masina << "\n" << "Salariu (in RON): " << cr.salariu << "\n";
        if(cr.disponibilitate != 0)
            os << "Curierul este disponibil!" << "\n";
            else
                os << "Curierul nu este disponibil la momentul actual!" << "\n";

        return os;
    }
    ~Curieri() = default;
};

class Destinatari : public Clienti{
protected:
    int cod_primire;
public:
    Destinatari(std :: string, std :: string, std :: string, std :: string, int);
    ~Destinatari();
    Destinatari(const Destinatari &);

    void afisare(std :: ostream &out) override;
    void citire(std::istream &in) override;

    friend std::ostream& operator<<(std :: ostream& out, Destinatari&);
    friend std::istream& operator>>(std :: istream& in, Destinatari&);

};

Destinatari :: Destinatari(const std::string nume, const std::string prenume, const std::string telefon, const std::string adresa, int cod_primire) : Clienti(nume,prenume,telefon,adresa) {
    this->cod_primire = cod_primire;
}

Destinatari :: ~Destinatari(){
    cod_primire = 0;
}

/*Destinatari ::Destinatari(const Destinatari &d){
    cod_primire = d.cod_primire;
}*/

void Destinatari ::citire(std::istream &in){
    Clienti ::citire(in);
    //std :: cout << "Codul dvs. de primire este : ";
    int aux;
    aux = 1;
    cod_primire = aux;
}
std::istream& operator>>(std::istream &in, Destinatari& d){
    d.citire(in);
    return in;
}

void Destinatari ::afisare(std::ostream &out) {
    Clienti :: afisare(out);
    //out << "Codul de primire este : " << cod_primire << "\n";
}

std::ostream & operator<<(std::ostream& out, Destinatari& d){
    d.afisare(out);
    return out;
}

class Colete{
    int AWB;
    std :: string nume;
    float greutate;
    float distanta;
    std :: string detalii;
    Curieri curier_1;

    friend class Curieri;
public:

    Colete(int AWB_, const std :: string& nume_, float greutate_, float distanta_, const std :: string& detalii_, Curieri const& curier_1_) :
            AWB{AWB_}, nume{nume_}, greutate{greutate_}, distanta{distanta_}, detalii{detalii_},  curier_1{curier_1_} {}

    Colete(const Colete& other) : AWB(other.AWB), nume(other.nume), greutate(other.greutate), distanta(other.distanta), detalii(other.detalii),
                                  curier_1(other.curier_1){};

    Colete& operator=(const Colete& other){
        AWB = other.AWB;
        nume = other.nume;
        greutate = other.greutate;
        distanta = other.distanta;
        detalii = other.detalii;
        std :: cout << "op egal\n";
        return *this;

    }
    ~Colete() = default;

    friend std :: ostream& operator<<(std::ostream& os, const Colete& col) {
        os << "Informatii despre colet: " << "\n" << "Denumire: " << col.nume << "\n" << "AWB: " << col.AWB << "\n"
           << "Greutate (in kg): " << col.greutate << "\n" << "Distanta :" << col.distanta << "\n";
        os << "Pret (in RON) :" << col.greutate * col.distanta << "\n";
        return os;
    }

    void Depunere_Colet(Colete colet_1){
        std :: cout << "Completati datele coletului : "<< "\n";
        std :: cout << "Nume colet :" << "\n";
        std :: cin >> colet_1.nume;
        std :: cout << "Greutate colet :" << "\n";
        std :: cin >> colet_1.greutate;
        std :: cout << "Distanta (in km) :" << "\n";
        std :: cin >> colet_1.distanta;
        std :: cout << "Pretul (in RON) pentru colet este :" << (colet_1.distanta * colet_1.greutate) << "\n";
    }

    void get_curier(Curieri m_curier_1){
        if(m_curier_1.disponibilitate == 1 && m_curier_1.stare_masina == 1)
            std :: cout << "Coletul va fi preluat de catre curierul " << m_curier_1.nume << "\n";

    }
};

class Expeditori : public Clienti{
protected:
     int ceva;
public:
    Expeditori(std :: string, std :: string, std :: string,std :: string, int);
    ~Expeditori();
    Expeditori(const Expeditori &);

    void afisare(std :: ostream &out) override;
    void citire(std :: istream &in) override;

    friend std::ostream& operator<<(std :: ostream& out, Expeditori&);
    friend std::istream& operator>>(std :: istream& in, Expeditori&);
};

Expeditori :: Expeditori(const std::string nume, const std::string prenume, const std::string telefon, const std::string adresa, int ceva) : Clienti(nume,prenume,telefon,adresa) {
    this->ceva = ceva;
}

Expeditori :: ~Expeditori(){
    ceva = 0;
}

/*Expeditori ::Expeditori(const Expeditori &d){
    ceva = d.ceva;
}*/

void Expeditori :: citire(std::istream &in){
    Clienti ::citire(in);
    int aux;
    aux = 1;
    ceva = aux;
}
std::istream& operator>>(std::istream &in, Expeditori& e){
    e.citire(in);
    return in;
}

void Expeditori ::afisare(std::ostream &out) {
    Clienti :: afisare(out);
    out << "Ceva-ul este : " << ceva << "\n";
}

std::ostream & operator<<(std::ostream& out, Expeditori& e) {
    e.afisare(out);
    return out;
}
int main() {
    Curieri cr_1{"daniel", "0745392868", "calea magurii", "Dacia", 1,1,3650};
    Colete c1{1, "Documente", 1, 50, "Important foarte tare", cr_1};
   //c1.Depunere_Colet(c1);
    //c1.get_curier(cr_1);
    //std :: cout << cr_1;

     Expeditori ex_1("petrica", "lover", "07415626753", "principala", 3);
     //c1.Depunere_Colet(c1);

    Destinatari dest_1{"Petrica", "Ion", "07412121221", "Strada Neagoe", 0};

    int x;
    std :: cout << "Alegeti operatia pe care doriti sa o efectuati:" << "\n";
    std :: cout << "1. Depunere colet" << "\n";
    std :: cout << "2. Verificati starea unei livrari" << "\n";
    std :: cout << "3. Iesire" << "\n";
    std :: cout << "4. Wanna hear a joke 8) ?" << "\n";
    std :: cin >> x;
    if (x == 1){
        std :: cin >> ex_1;
        c1.Depunere_Colet(c1);
        std :: cout << "Completati datele destinatarului : ";
        std :: cin >> dest_1;
        c1.get_curier(cr_1);
    }
    else
        if(x == 2){
            std :: cout << "well n am facut inca :))";
        }
        else
            if(x == 3){
                std :: cout << "La revedere !";
                return 0;
            }
            else
                if(x == 4){
                    std :: cout << "I am on a seafood diet. Cause when i see food, i eat it.";
                }
    return 0;
}


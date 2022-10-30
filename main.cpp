#include <iostream>

class Curieri{
    std :: string nume;
    std :: string telefon;
    std :: string adresa;
    int salariu;
public:
    Curieri(const std :: string& nume_, const std :: string& telefon_,  const std :: string& adresa_, int salariu_) : nume{nume_}, telefon{telefon_}, adresa{adresa_}, salariu{salariu_}{
        std :: cout << "intializare\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Curieri& cr){
        os << "Informatii despre curier: " << "\n" << "Nume: "<< cr.nume << "\n" << "Numar de telefon: " << cr.telefon << "\n" << "Adresa: " << cr.adresa <<"\n" << "Salariu (in RON): " << cr.salariu << "\n";
        return os;
    }
    ~Curieri();
};

class Destinatari{
    std :: string nume;
    std :: string telefon;
    std :: string adresa;
public:

    Destinatari(const std :: string& nume_, const std :: string& telefon_, const std :: string& adresa_) : nume{nume_}, telefon{telefon_}, adresa{adresa_}{}

    friend std :: ostream& operator<<(std::ostream& os, const Destinatari& ds){
        os << "Informatii despre destinatar: " << "\n" << "Nume: "<< ds.nume << "\n" << "Numar de telefon: " << ds.telefon << "\n" << "Adresa: " << ds.adresa <<"\n";
        return os;
    }

    ~Destinatari();
};


class Colete{
    int AWB;
    std :: string nume;
    int greutate;
    int distanta;
    std :: string detalii;
    friend class Expeditori;
public:
    Colete(int AWB_, const std :: string& nume_, int greutate_, int distanta_, const std :: string& detalii_) : AWB{AWB_}, nume{nume_}, greutate{greutate_}, distanta{distanta_}, detalii{detalii_}{};

    Colete(const Colete& other){
        AWB = other.AWB;
        nume = other.nume;
        greutate = other.greutate;
        distanta = other.distanta;
        detalii = other.detalii;
        std :: cout << "cc\n";

    }
    Colete& operator=(const Colete& other){
        AWB = other.AWB;
        nume = other.nume;
        greutate = other.greutate;
        distanta = other.distanta;
        detalii = other.detalii;
        std :: cout << "op egal\n";
        return *this;

    }
    ~Colete(){
        //std :: cout << "salut la revedere!\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Colete& col) {
        os << "Informatii despre colet: " << "\n" << "Denumire: " << col.nume << "\n" << "AWB: " << col.AWB << "\n" << "Greutate (in kg): " << col.greutate << "\n" << "Distanta :" << col.distanta <<"\n";
        os << "Pret (in RON) :" << col.greutate * col.distanta <<"\n";
        return os;
    }

};

class Expeditori{
    std :: string nume;
    std :: string telefon;
    std :: string adresa;
    Colete colet_1;
    friend class Colete;

public:

    Expeditori(const std :: string& nume_, const std :: string& telefon_, const std :: string& adresa_, Colete colet_1_) : nume{nume_}, telefon{telefon_}, adresa{adresa_}, colet_1(colet_1_){}
    friend std :: ostream& operator<<(std::ostream& os, const Expeditori& ex){
        os << "Informatii despre expeditor: " << "\n" << "Nume: "<< ex.nume << "\n" << "Numar de telefon: " << ex.telefon << "\n" << "Adresa: " << ex.adresa <<"\n";
        return os;
    }
    void Depunere_Colet(Colete &m_colet_1){
        std :: cout << "Ce colet doriti sa depuneti ? "<< "\n";
        std :: cout << "Nume colet :" << "\n";
        std :: cin >> m_colet_1.nume;
        std :: cout << "Greutate colet :" << "\n";
        std :: cin >> m_colet_1.greutate;
        std :: cout << "Distanta (in km) :" << "\n";
        std :: cin >> m_colet_1.distanta;
        std :: cout << "Pretul (in RON) pentru colet este :" << (m_colet_1.distanta * m_colet_1.greutate);
    }
    ~Expeditori() = default;
};

int main() {
        Colete colet_1{1, "Documente", 1, 50, "Important"};
//    Colete colet_2{2,"Bicicleta", 15,100,"Nimic"};
//    Colete colet_3{1, "Documente", 1, 50, "Important"};
//    Colete colet_4 = colet_3;
//    colet_3 = colet_2;
//    //Curieri curier_1{"Marcel Love", "0741273748", "Strada Principala", 3500};
//    std :: cout << colet_2 << colet_3 << colet_4;
    //std :: cout << curier_1;
    Expeditori ex_1{"Petrica","074123748","Principala",colet_1};
    ex_1.Depunere_Colet(colet_1);
    return 0;
}

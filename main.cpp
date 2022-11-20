#include <iostream>
#include <string>
#include <random>

using std :: vector;

class Client{
protected:
        std :: string nume;
        std :: string prenume;
        std :: string telefon;
        std :: string adresa;
public:
    Client(const std :: string& nume_, const std :: string& prenume_ , const std :: string& telefon_, const std :: string& adresa_) : nume{nume_}, prenume{prenume_}, telefon{telefon_}, adresa{adresa_}{};
    Client(const Client & other) : nume(other.nume), prenume(other.prenume), telefon(other.telefon), adresa(other.adresa){};

    virtual ~Client();
    virtual void afisare (std :: ostream &out);
    virtual void citire(std :: istream &in);

    friend std :: ostream& operator<<(std :: ostream& out, Client&);
    friend std :: istream& operator>>(std :: istream& in, Client&);
};

Client :: ~Client(){
    nume = "";
    prenume = "";
    telefon = "";
    adresa ="";
}

std :: istream& operator>>(std :: istream& in, Client& cl){
    cl.citire(in);
    return in;
}

void Client ::citire(std::istream &in) {
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
std::ostream& operator<<(std :: ostream& out, Client& cl){
    cl.afisare(out);
    return out;
}

void Client :: afisare (std::ostream &out){
    out << "Numele : "<< nume << "\n";
    out << "Prenumele :" << prenume << "\n";
    out << "Telefonul : "<< telefon << "\n";
    out << "Adresa :"<< adresa << "\n";
}

class Curier{
protected:
    std :: string nume;
    std :: string telefon;
    std :: string masina;
    int stare_masina;
    int salariu;
    int livrari_efectuate;

    friend class Colete;
public:
    Curier(const std :: string& nume_, const std :: string& telefon_, const std :: string& masina_, int stare_masina_, int salariu_, int livrari_efectuate_) :
             nume{nume_}, telefon{telefon_},  masina{masina_}, stare_masina{stare_masina_} ,salariu{salariu_}, livrari_efectuate{livrari_efectuate_} {
        //std :: cout << "intializare\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Curier& cr){
        os << "Informatii despre curier: " << "\n" << "Nume: "<< cr.nume << "\n" << "Numar de telefon: " << cr.telefon  <<"\n"
            << "Masina curierului :"<<cr.masina << "\n" << "Stare masinii :"<< cr.stare_masina << "\n" << "Salariu (in RON): " << cr.salariu << "\n" << "Livrari efectuate :" << cr.livrari_efectuate << "\n";
        return os;
    }
    ~Curier() = default;

    void get_curier(Curier curier_1){
        if(curier_1.stare_masina == 1)
            std :: cout << "Coletul va fi preluat de catre curierul " << curier_1.nume << "\n";
    }

    void setLivrari(int l){
        livrari_efectuate += l;
    }

    void prima_de_Craicun(Curier const curier_1){
        int decizie;
            if(curier_1.livrari_efectuate == 2){
                std :: cout << "Felicitari ai primit 300 RON prima de Craciun !";
                std :: cout << " La 3 livrari efecutate iti marim prima la 225 RON prima ! Accepti ?" << "\n";
                std :: cout << "1.Da / 2.Nu";
                std :: cin >> decizie;
                switch(decizie){
                    case 2 : {
                        std::cout << "Nu Accept!";
                        int net = 300;
                            net -= 150;
                            int cas = 0.08 * net;
                            int cass = 0.1 * net;
                            net -= (cas + cass);
                            net = 150 + net;
                            std::cout << "In urma taxelor prima este in valoare de : " << net << "\n";
                    }
                        break;
                    case 1:
                        std :: cout <<"Accept!";
                        break;
                    default :
                        std :: cout << "Accept!";
                        break;
                }
            }
            else
                {
                    std :: cout << "face if u  1";
                    std :: cout << "Felicitari ai primit 150 prima de Craciun ! ";
        }
    }
};

class Destinatar : public Client{
protected:
    int cod_primire;
public:
    Destinatar(std :: string, std :: string, std :: string, std :: string, int);
    ~Destinatar();
    Destinatar(const Destinatar &);

    friend std::ostream& operator<<(std :: ostream& out, Destinatar&);
    friend std::istream& operator>>(std :: istream& in, Destinatar&);

    void generare_cod_primire(Destinatar dest_1){
        std::random_device rd;
        std::mt19937 engine{rd()};
        std::uniform_int_distribution<> dist(1,9);
        int count = 3;
        while(count > 0){
            auto random_number = dist(engine);
            dest_1.cod_primire = dest_1.cod_primire * 10 + random_number;
            count--;
        }
    }

    /*void verificare_cod(int x, Destinatar dest_1){
        if(x == dest_1.cod_primire)
            std :: cout << "Ati primit coletul !";
        else
            std :: cout << "Ati introdus codul gresit !";
    }*/

};

Destinatar :: Destinatar(const std::string nume, const std::string prenume, const std::string telefon, const std::string adresa, int cod_primire) : Client(nume, prenume, telefon, adresa) {
    this->cod_primire = cod_primire;
}

Destinatar :: ~Destinatar(){
    cod_primire = 0;
}

std::istream& operator>>(std::istream &in, Destinatar& d){
    d.citire(in);
    return in;
}

std::ostream & operator<<(std::ostream& out, Destinatar& d){
    d.afisare(out);
    return out;
}

class Colet{
    int AWB;
    std :: string nume;
    float greutate;
    float distanta;
    std :: string detalii;
    int stare_colet;
    Curier curier_1;

    friend class Curieri;
public:

    Colet(int AWB_, const std :: string& nume_, float greutate_, float distanta_, const std :: string& detalii_, int stare_colet_, Curier const& curier_1_) :
            AWB{AWB_}, nume{nume_}, greutate{greutate_}, distanta{distanta_}, detalii{detalii_}, stare_colet{stare_colet_},  curier_1{curier_1_} {}

    Colet(const Colet& other) : AWB(other.AWB), nume(other.nume), greutate(other.greutate), distanta(other.distanta), detalii(other.detalii),
                                stare_colet(other.stare_colet), curier_1(other.curier_1){};

    Colet& operator=(const Colet& other){
        AWB = other.AWB;
        nume = other.nume;
        greutate = other.greutate;
        distanta = other.distanta;
        detalii = other.detalii;
        stare_colet = other.stare_colet;
        std :: cout << "op egal\n";
        return *this;

    }
    ~Colet() = default;

    friend std :: ostream& operator<<(std::ostream& os, const Colet& col) {
        os << "Informatii despre colet: " << "\n" << "Denumire: " << col.nume << "\n" << "AWB: " << col.AWB << "\n"
           << "Greutate (in kg): " << col.greutate << "\n" << "Distanta :" << col.distanta << "\n";
        os << "Pret (in RON) :" << col.greutate * col.distanta << "\n";
        return os;
    }

    void Depunere_Colet(Colet colet_1){
        std :: cout << "Completati datele coletului : "<< "\n";
        std :: cout << "Nume colet :" << "\n";
        std :: cin >> colet_1.nume;
        std :: cout << "Greutate colet :" << "\n";
        std :: cin >> colet_1.greutate;
        std :: cout << "Distanta (in km) :" << "\n";
        std :: cin >> colet_1.distanta;
        std :: cout << "Pretul (in RON) pentru colet este :" << (colet_1.distanta * colet_1.greutate) << "\n";
    }


    void generare_AWB(Colet colet_1){

        std::random_device rd;
        std::mt19937 engine{rd()};
        std::uniform_int_distribution<> dist(1000000,9999999);
        auto random_number = dist(engine);
        colet_1.AWB = random_number;

        std :: cout << "AWB-ul coletului dvs este :" << colet_1.AWB << "\n";
    }
    int getAWB() {
        return AWB;
    }
    int get_stare_colet() {
        return stare_colet;
    }

    void Starea_colet(Colet colet_1){
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
};

class Expeditor : public Client{
protected:
     int avans;
public:
    Expeditor(std :: string, std :: string, std :: string, std :: string, int);
    ~Expeditor();
    Expeditor(const Expeditor &);

    void afisare(std :: ostream &out) override;
    void citire(std :: istream &in) override;

    friend std::ostream& operator<<(std :: ostream& out, Expeditor&);
    friend std::istream& operator>>(std :: istream& in, Expeditor&);
};

Expeditor :: Expeditor(const std::string nume, const std::string prenume, const std::string telefon, const std::string adresa, int ceva) : Client(nume, prenume, telefon, adresa) {
    this->avans = ceva;
}

Expeditor :: ~Expeditor(){
    avans = 0;
}

/*Expeditor ::Expeditor(const Expeditor &d){
    avans = d.avans;
}*/

void Expeditor :: citire(std::istream &in){
    Client ::citire(in);
    int aux;
    aux = 1;
    avans = aux;
}
std::istream& operator>>(std::istream &in, Expeditor& e){
    e.citire(in);
    return in;
}

void Expeditor ::afisare(std::ostream &out) {
    Client :: afisare(out);
    out << "Ceva-ul este : " << avans << "\n";
}

std::ostream & operator<<(std::ostream& out, Expeditor& e) {
    e.afisare(out);
    return out;
}
int main() {

    Curier cr_1{"Pintea", "0747399860", "Dacia", 1, 3650, 1};
    Curier cr_2{"Andrusca", "0789394461", "Ford", 0, 3000, 0};
    Curier cr_3{"Toader", "0747123987", "Volkswagen", 1, 4100, 1};
    Curier cr_4{"Intotero", "0740420691", "Dacia", 1, 3870, 1};

    vector<Curier> v1;
    v1.push_back(cr_1);
    v1.push_back(cr_2);
    v1.push_back(cr_3);
    v1.push_back(cr_4);

    Colet c1{1234567, "Documente", 1, 56, "Important", 0, cr_1};
    Colet c2{2222222 , "Boxe", 7.5, 167, "boxe audio voluminoase fragile", 2, cr_1};
    Colet c3{3333333, "Carti", 4, 89, "Carti de limba engleza", 2, cr_1};


    vector<int> v2;
    v2.push_back(c1.getAWB());
    v2.push_back(c2.getAWB());
    v2.push_back(c3.getAWB());

    vector<int> v3;
    v3.push_back(c1.get_stare_colet());
    v3.push_back(c2.get_stare_colet());
    v3.push_back(c3.get_stare_colet());


     Expeditor ex_1("Love", "Petrica", "07415626753", "Calea Magurii", 0);
     Expeditor ex_2("Marcel", "Piftel", "07415626753", "Strada Municipiului", 0);

    Destinatar dest_1{"Dan", "Carmen", "0741568721", "Strada Camplung", 1234};
    Destinatar dest_2{"Vasilescu", "Olguta", "0742190541", "Strada General Grigore", 5689};
    Destinatar dest_3{"Anton", "Anton", "0747693690", "Strada Neagoe Basarab", 8935};
    Destinatar dest_4{"Melecsanu", "Viorel", "0745643699", "Strada Gheorgeni", 1568};


    int x;
    /// Depunere colet :
        std :: cin >> ex_1;
        std :: cout << "Completati datele destinatarului : ";
        std :: cin >> dest_1;
        c1.Depunere_Colet(c1);
        c1.generare_AWB(c1);
        cr_1.get_curier(cr_1);
    /// Prima de Craciun :
        cr_1.setLivrari(1);
        cr_1.prima_de_Craicun(cr_1);
        std :: cout << "\n";
    /// Verificare stare colet :
    std :: cout << "Introduceti AWB-ul coletului pe care doriti sa-l verificati :";
    std :: cin >> x;
    int ok = 0;
    for(unsigned long long i = 0; i < v2.size(); i++) {
        if (x == v2[i]) {
            c1.Starea_colet(c1);
            //dest_1.generare_cod_primire(dest_1);
            ok = 1;
            break;
        } else if (ok == 0)
            std::cout << "Nu exista niciun colet cu acest AWB !";
    }
    return 0;
}


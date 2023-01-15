//#include <string>
#include "Curier.h"
#include "Colet.h"
#include "Clienti.h"
#include "Factura.h"
#include "Exceptii.h"
#include "Baza_de_date.h"

using std :: vector;

//class Client

int Curier::nr_curieri = 0;
int main() {

    Baza_de_date b1;
    b1.adaugare_curieri<Curier_de_zi>("Pintea", "0747399860", "Dacia", 1, 3650, 1);
    b1.adaugare_curieri<Curier_de_zi>("Andrusca", "0789394461", "Ford", 0, 3000, 1);
    b1.adaugare_curieri<Curier_de_noapte>("Toader", "0747123987", "Volkswagen", 1, 4100, 1);


    Destinatar dest_1{"Dan", "Carmen", "0741568721", "Strada Camplung", 1234};
    Destinatar dest_2{"Vasilescu", "Olguta", "0742190541", "Strada General Grigore", 5689};
    Destinatar dest_3{"Anton", "Anton", "0747693690", "Strada Neagoe Basarab", 8935};
    Destinatar dest_4{"Melecsanu", "Viorel", "0745643699", "Strada Gheorgeni", 1568};

    Colet c1{1234567, "Documente", 0, 56, "Important", 0, *b1.all_curieri.at(0)};
    Colet c2{2222222 , "Boxe", 7.5, 167, "boxe audio voluminoase fragile",1, *b1.all_curieri.at(1)};
    Colet c3{3333333, "Carti", 4, 89, "Carti de limba engleza", 2, *b1.all_curieri.at(2)};


    Expeditor ex_1("Love", "Petrica", "0741273748", "Strada Principala", c1);
    //Expeditor ex_2("Marcel", "Piftel", "07415626753", "Strada Municipiului", 0);

    Factura fac(56, c1);
    Factura_card facC(100,c2,"Love Petrica", "RO 0040 1896 2596");


    b1.total_salarii();
   try{
       // c1.Depunere_Colet();
        c1.generare_AWB(c1);
    }catch (eroare_colet &err){
        std :: cout << err.what() << "\n" ;}
    fac.Verificare();
   ex_1.Evaluare_servicii();
   dest_1.Evaluare_servicii();
   /// Verificare stare colet :
    ex_1.add_colet(c1);
    ex_1.add_colet(c2);
    ex_1.add_colet(c3);
    dest_1.generare_cod_primire();

    ex_1.Cautare_AWB(3333333);
    c3.Starea_colet(c3);
    std :: cout << "\n";
    ///Anulare colet :
    ex_1.Anulare_colet(1234567);

    return 0;
}


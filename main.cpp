#include <iostream>
//#include <string>
#include <random>
#include "Curier.h"
#include "Colet.h"
#include "Clienti.h"

using std :: vector;

//class Client


int main() {

    Curier cr_1{"Pintea", "0747399860", "Dacia", 1, 3650, 1};
    Curier cr_2{"Andrusca", "0789394461", "Ford", 0, 3000, 1};
    Curier cr_3{"Toader", "0747123987", "Volkswagen", 1, 4100, 1};
    //Curier cr_4{"Intotero", "0740420691", "Dacia", 1, 3870, 0};


    Colet c1{1234567, "Documente", 1, 56, "Important", 0, cr_1};
    Colet c2{2222222 , "Boxe", 7.5, 167, "boxe audio voluminoase fragile", 2, cr_3};
    Colet c3{3333333, "Carti", 4, 89, "Carti de limba engleza", 2, cr_2};


    Expeditor ex_1("Love", "Petrica", "07415626753", "Calea Magurii", 0);
    //Expeditor ex_2("Marcel", "Piftel", "07415626753", "Strada Municipiului", 0);

    Destinatar dest_1{"Dan", "Carmen", "0741568721", "Strada Camplung", 1234};
    Destinatar dest_2{"Vasilescu", "Olguta", "0742190541", "Strada General Grigore", 5689};
    Destinatar dest_3{"Anton", "Anton", "0747693690", "Strada Neagoe Basarab", 8935};
    Destinatar dest_4{"Melecsanu", "Viorel", "0745643699", "Strada Gheorgeni", 1568};

    /// Depunere colet :
        //std :: cin >> ex_1;
        //std :: cout << "Completati datele destinatarului : ";
        //std :: cin >> dest_1;
        c1.Depunere_Colet(c1);
        c1.generare_AWB(c1);
        cr_1.get_curier(cr_1);
    /// Verificare stare colet :
    ex_1.add_colet(c1);
    ex_1.add_colet(c2);
    ex_1.add_colet(c3);
    dest_1.generare_cod_primire(dest_1);

    ex_1.Cautare_AWB(3333333);
    c3.Starea_colet(c3);
    std :: cout << "\n";
    ///Anulare colet :
    ex_1.Anulare_colet(1234567);
    ex_1.get_suma();

    return 0;
}


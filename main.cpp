#include <iostream>
//#include <string>
#include "Curier.h"
#include "Colet.h"
#include "Clienti.h"
#include "Factura.h"
#include "Exceptii.h"

using std :: vector;

//class Client


int main() {

    Curier_de_zi crz_1{"Pintea", "0747399860", "Dacia", 1, 3650, 1, 20,0.4};
    Curier_de_zi crz_2{"Andrusca", "0789394461", "Ford", 0, 3000, 1,10,0.2};
    Curier_de_noapte crn_1{"Toader", "0747123987", "Volkswagen", 1, 4100, 1, 3, 0.1, 0.25};
    //Curier cr_4{"Intotero", "0740420691", "Dacia", 1, 3870, 0};


    Destinatar dest_1{"Dan", "Carmen", "0741568721", "Strada Camplung", 1234};
    Destinatar dest_2{"Vasilescu", "Olguta", "0742190541", "Strada General Grigore", 5689};
    Destinatar dest_3{"Anton", "Anton", "0747693690", "Strada Neagoe Basarab", 8935};
    Destinatar dest_4{"Melecsanu", "Viorel", "0745643699", "Strada Gheorgeni", 1568};

    Colet c1{1234567, "Documente", 0, 56, "Important", 0, crz_1/*, dest_1*/};
    Colet c2{2222222 , "Boxe", 7.5, 167, "boxe audio voluminoase fragile", 2, crn_1/*, dest_2*/};
    Colet c3{3333333, "Carti", 4, 89, "Carti de limba engleza", 2, crz_2/*, dest_1*/};



    Expeditor ex_1("Love", "Petrica", "0741273748", "Strada Principala", c1);
    //Expeditor ex_2("Marcel", "Piftel", "07415626753", "Strada Municipiului", 0);

    Factura fac(56, c1);
    Factura_card facC(100,c2,"Love Petrica", "RO 0040 1896 2596");

    crz_1.lista_curieri_1(&crz_1);
    crn_1.lista_curier_2(crn_1);

   try{
        c1.Depunere_Colet();
        c1.generare_AWB(c1);
    }catch (eroare_colet &err){
        std :: cout << err.what() << "\n" ;}
    fac.Verificare();
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

    crn_1.bonus_salariu();
    crz_1.bonus_salariu();

    return 0;
}


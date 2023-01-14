#ifndef OOP_CURIER_H
#define OOP_CURIER_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <typeinfo>

class Curier {
protected:
    static int nr_curieri;
    std :: string nume;
    std :: string telefon;
    std :: string masina;
    int stare_masina;
    int salariu;
    int livrari_efectuate;

public:
    Curier(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_);
    //Curier();
    Curier(const Curier &other) = default;

    Curier &operator=(const Curier &other) = default;

    friend std :: ostream &operator<<(std :: ostream &os, const Curier &client_);

    virtual ~Curier(){
        nr_curieri--;
    }

    int getSal() const;

};
class Curier_de_zi : public Curier{
private:
public:
    Curier_de_zi(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_);

};

class Curier_de_noapte : public Curier{
private :
    double spor_de_noapte = 0.25;
public:
    Curier_de_noapte(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_);

    double bonus_salariu();

};




#endif //OOP_CURIER_H

#ifndef OOP_CURIER_H
#define OOP_CURIER_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <typeinfo>

class Curier {
protected:
    std :: string nume;
    std :: string telefon;
    std :: string masina;
    int stare_masina;
    int salariu;
    int livrari_efectuate;

public:
    Curier(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_);

    Curier(const Curier &other) = default;

    Curier &operator=(const Curier &other) = default;

    friend std :: ostream &operator<<(std :: ostream &os, const Curier &client_);

    virtual ~Curier() = default;

    virtual double bonus_salariu () const {
        return 0;
    }
};
class Curier_de_zi : public Curier{
private:
    int experienta;
public:
    Curier_de_zi(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_, int experienta_);

    double bonus_salariu() const override;

    void lista_curieri_1(Curier* curier_);

};

class Curier_de_noapte : public Curier{
private :
    int experienta;
    double spor_de_noapte;
public:
    Curier_de_noapte(const std::string& nume_, const std::string& telefon_, const std::string& masina_, int stare_masina, int salariu_, int livrari_efectuate_, int experienta_, double spor_de_noapte);

    double bonus_salariu() const override;

    void lista_curier_2(Curier& curier_) const;
};



#endif //OOP_CURIER_H

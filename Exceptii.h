#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>
#include <vector>

class eroare_mare : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class eroare_plata : public eroare_mare{
public:
    explicit eroare_plata(const std :: string &string_) : eroare_mare("Nobun plata :" + string_) {}
};

class eroare_colet : public eroare_mare{
public:
    explicit  eroare_colet(const std :: string &string_) : eroare_mare("Nobun colet: " + string_) {}
};
#endif //OOP_EXCEPTII_H

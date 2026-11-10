#ifndef ITEM6_HPP
#define ITEM6_HPP

#include <string>

namespace tema2 {

// ---------- Varianta din carte (C++98): clasa de baza Uncopyable ----------
// Copy constructor si operator= sunt PRIVATE si NEDEFINITE.
// Orice clasa derivata din ea nu mai poate fi copiata.
class Uncopyable
{
protected:
    Uncopyable() {}            // se pot crea / distruge obiecte derivate
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable&);              // doar declarat, fara corp
    Uncopyable& operator=(const Uncopyable&);   // doar declarat, fara corp
};

// O casa de vanzare e unica => nu are sens sa o copiem.
class Apartament : private Uncopyable
{
private:
    std::string adresa_;

public:
    explicit Apartament(const std::string& adresa);
    void afiseaza() const;
};

// ---------- Varianta moderna (C++11): = delete ----------
class ContBancar
{
private:
    std::string iban_;
    double      sold_;

public:
    ContBancar(const std::string& iban, double sold);

    ContBancar(const ContBancar&)            = delete;   // interzis
    ContBancar& operator=(const ContBancar&) = delete;   // interzis

    void afiseaza() const;
};

}

#endif

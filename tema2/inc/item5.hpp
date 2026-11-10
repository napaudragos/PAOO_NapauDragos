#ifndef ITEM5_HPP
#define ITEM5_HPP

#include <martor.hpp>
#include <string>

namespace tema2 {

// No user-declared functions: compiler generates default ctor, copy ctor,
// copy assignment and destructor (plus move operations in C++11)
class Carte
{
private:
    std::string titlu_;
    Martor      martor_{"Carte"};
};

// User-declared ctor => no default ctor; const member => operator= is deleted
class Nota
{
private:
    const int valoare_;

public:
    explicit Nota(int valoare) : valoare_(valoare) {}
    int valoare() const { return valoare_; }
};

}

#endif

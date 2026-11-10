#ifndef ITEM4_HPP
#define ITEM4_HPP

#include <martor.hpp>
#include <string>

namespace tema2 {

// BAD: assignment in constructor body (default ctor + operator=)
class StudentAtribuire
{
private:
    std::string nume_;
    int         nota_;
    Martor      martor_;

public:
    StudentAtribuire(const std::string& nume, int nota, const Martor& m);
    void afiseaza() const;
};

// GOOD: member initializer list (single copy ctor call)
class StudentLista
{
private:
    std::string nume_;
    int         nota_;
    Martor      martor_;

public:
    StudentLista(const std::string& nume, int nota, const Martor& m);
    void afiseaza() const;
};

// Members are initialized in declaration order, not initializer list order
class OrdineInit
{
private:
    Martor primul_;
    Martor alDoilea_;

public:
    OrdineInit();
};

}

#endif

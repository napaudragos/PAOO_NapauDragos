#ifndef ITEM4_HPP
#define ITEM4_HPP

#include <martor.hpp>
#include <string>

namespace tema2 {

// ---------- GRESIT: atribuire in corpul constructorului ----------
// Membrii sunt mai intai construiti implicit, apoi li se atribuie valori.
// => 2 apeluri (constructor implicit + operator=) in loc de 1.
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

// ---------- CORECT: lista de initializare ----------
// Membrii sunt construiti DIRECT cu valoarea buna => 1 singur apel (copy constructor).
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

// ---------- Ordinea de initializare ----------
// Membrii se initializeaza in ordinea in care sunt DECLARATI in clasa,
// NU in ordinea in care apar in lista de initializare.
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

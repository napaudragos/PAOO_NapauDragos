#ifndef ITEM5_HPP
#define ITEM5_HPP

#include <martor.hpp>
#include <string>

namespace tema2 {

// ---------- Clasa in care NU scriem nicio functie ----------
// Compilatorul genereaza singur (doar daca sunt folosite):
//   - constructor implicit      Carte()
//   - copy constructor          Carte(const Carte&)
//   - copy assignment           Carte& operator=(const Carte&)
//   - destructor                ~Carte()
// (+ in C++11: move constructor si move assignment)
// Acestea apeleaza la randul lor functiile corespunzatoare ale membrilor.
class Carte
{
private:
    std::string titlu_;
    Martor      martor_{"Carte"};   // il folosim ca sa vedem ce se apeleaza
};

// ---------- Cand compilatorul NU genereaza ce credem ----------
// 1) Am scris un constructor cu parametru => nu mai exista constructor implicit.
// 2) Membru const (sau referinta) => operator= NU poate fi generat,
//    pentru ca un const nu poate fi modificat dupa initializare.
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

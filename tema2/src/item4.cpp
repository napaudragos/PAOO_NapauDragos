#include <item4.hpp>
#include <config.hpp>
#include <iostream>

namespace tema2 {

// ---------- GRESIT ----------
StudentAtribuire::StudentAtribuire(const std::string& nume, int nota, const Martor& m)
{
    // aici martor_ a fost DEJA construit implicit, iar nota_ contine o valoare aleatoare
    nume_   = nume;
    nota_   = nota;
    martor_ = m;    // al doilea apel: operator=
}

void StudentAtribuire::afiseaza() const
{
    std::cout << "  " << nume_ << " are nota " << nota_ << '\n';
}

// ---------- CORECT ----------
StudentLista::StudentLista(const std::string& nume, int nota, const Martor& m)
    : nume_(nume),
      nota_(nota > config().notaMaxima() ? 0 : nota),   // config() din ALT fisier .cpp
      martor_(m)
{
}

void StudentLista::afiseaza() const
{
    std::cout << "  " << nume_ << " are nota " << nota_ << '\n';
}

// ---------- ORDINEA ----------
// Ordinea scrisa aici e inversa fata de declarare, intentionat.
// Compilatorul da un warning (-Wreorder) si oricum il construieste primul pe primul_.
OrdineInit::OrdineInit()
    : alDoilea_("alDoilea"),
      primul_("primul")
{
}

}

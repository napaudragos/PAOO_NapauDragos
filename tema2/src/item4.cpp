#include <item4.hpp>
#include <config.hpp>
#include <iostream>

namespace tema2 {

StudentAtribuire::StudentAtribuire(const std::string& nume, int nota, const Martor& m)
{
    // martor_ is already default-constructed here
    nume_   = nume;
    nota_   = nota;
    martor_ = m;
}

void StudentAtribuire::afiseaza() const
{
    std::cout << "  " << nume_ << " are nota " << nota_ << '\n';
}

StudentLista::StudentLista(const std::string& nume, int nota, const Martor& m)
    : nume_(nume),
      nota_(nota > config().notaMaxima() ? 0 : nota),
      martor_(m)
{
}

void StudentLista::afiseaza() const
{
    std::cout << "  " << nume_ << " are nota " << nota_ << '\n';
}

// Intentionally reversed order: triggers -Wreorder, primul_ is still built first
OrdineInit::OrdineInit()
    : alDoilea_("alDoilea"),
      primul_("primul")
{
}

}

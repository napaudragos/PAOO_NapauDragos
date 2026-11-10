#include <item6.hpp>
#include <iostream>

namespace tema2 {

Apartament::Apartament(const std::string& adresa)
    : adresa_(adresa)
{
}

void Apartament::afiseaza() const
{
    std::cout << "  Apartament: " << adresa_ << '\n';
}

ContBancar::ContBancar(const std::string& iban, double sold)
    : iban_(iban), sold_(sold)
{
}

void ContBancar::afiseaza() const
{
    std::cout << "  Cont " << iban_ << " | sold: " << sold_ << " lei\n";
}

}

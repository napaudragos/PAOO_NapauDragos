#include <martor.hpp>
#include <iostream>

namespace tema2 {

Martor::Martor()
    : nume_("fara nume")
{
    std::cout << "    [Martor " << nume_ << "] constructor implicit\n";
}

Martor::Martor(const std::string& nume)
    : nume_(nume)
{
    std::cout << "    [Martor " << nume_ << "] constructor cu parametru\n";
}

Martor::Martor(const Martor& other)
    : nume_(other.nume_)
{
    std::cout << "    [Martor " << nume_ << "] copy constructor\n";
}

Martor& Martor::operator=(const Martor& other)
{
    std::cout << "    [Martor " << nume_ << "] operator= (primeste \"" << other.nume_ << "\")\n";
    nume_ = other.nume_;
    return *this;
}

Martor::~Martor()
{
    std::cout << "    [Martor " << nume_ << "] destructor\n";
}

}

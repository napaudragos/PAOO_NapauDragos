#ifndef ITEM6_HPP
#define ITEM6_HPP

#include <string>

namespace tema2 {

// C++98 approach: private, undefined copy operations in a base class
class Uncopyable
{
protected:
    Uncopyable() {}
    ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable&);              // declared, never defined
    Uncopyable& operator=(const Uncopyable&);   // declared, never defined
};

class Apartament : private Uncopyable
{
private:
    std::string adresa_;

public:
    explicit Apartament(const std::string& adresa);
    void afiseaza() const;
};

// C++11 approach: = delete
class ContBancar
{
private:
    std::string iban_;
    double      sold_;

public:
    ContBancar(const std::string& iban, double sold);

    ContBancar(const ContBancar&)            = delete;
    ContBancar& operator=(const ContBancar&) = delete;

    void afiseaza() const;
};

}

#endif

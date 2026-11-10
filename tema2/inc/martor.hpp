#ifndef MARTOR_HPP
#define MARTOR_HPP

#include <string>

namespace tema2 {

// "Martor" = o clasa care afiseaza pe ecran ORICE functie speciala i se apeleaza.
// O punem ca membru in alte clase ca sa VEDEM ce functii scrie/apeleaza compilatorul.
class Martor
{
private:
    std::string nume_;

public:
    Martor();                                // constructor implicit
    explicit Martor(const std::string& nume);
    Martor(const Martor& other);             // copy constructor
    Martor& operator=(const Martor& other);  // copy assignment
    ~Martor();                               // destructor
};

}

#endif

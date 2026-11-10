#ifndef MARTOR_HPP
#define MARTOR_HPP

#include <string>

namespace tema2 {

// Prints every special member function call, to make compiler-generated calls visible
class Martor
{
private:
    std::string nume_;

public:
    Martor();
    explicit Martor(const std::string& nume);
    Martor(const Martor& other);
    Martor& operator=(const Martor& other);
    ~Martor();
};

}

#endif

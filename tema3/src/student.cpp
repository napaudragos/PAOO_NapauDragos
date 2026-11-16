#include <student.hpp>
#include <iostream>

Student::Student(const std::string& nume, int nota)
    : nume_(nume), nota_(new int(nota))
{
}

Student::Student(const Student& other)
    : nume_(other.nume_), nota_(new int(*other.nota_))
{
}

Student& Student::operator=(const Student& other)
{
    if (this == &other)              // Item 11: self-assignment
        return *this;

    int* nou = new int(*other.nota_);
    delete nota_;
    nota_ = nou;
    nume_ = other.nume_;

    return *this;                    // Item 10: return *this
}

Student::~Student()
{
    delete nota_;
}

void Student::afiseaza() const
{
    std::cout << nume_ << " - nota " << *nota_;
}

Bursier::Bursier(const std::string& nume, int nota, int bursa)
    : Student(nume, nota), bursa_(bursa)
{
}

// Item 12: copy the base part too
Bursier::Bursier(const Bursier& other)
    : Student(other), bursa_(other.bursa_)
{
}

Bursier& Bursier::operator=(const Bursier& other)
{
    Student::operator=(other);       // Item 12
    bursa_ = other.bursa_;
    return *this;
}

void Bursier::afiseaza() const
{
    Student::afiseaza();
    std::cout << " - bursa " << bursa_;
}

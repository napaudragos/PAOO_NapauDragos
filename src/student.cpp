#include <student/student.hpp>
#include <iostream>
#include <utility>

namespace catalog {

// ---------- CONSTRUCTOR ----------
Student::Student(const std::string& nume, int numarNote)
    : nume_(nume), note_(new int[numarNote]), numarNote_(numarNote)
{
    for (int i = 0; i < numarNote_; ++i)
        note_[i] = 0;   // fara asta, vectorul ar contine valori aleatoare

    std::cout << "[constructor] " << nume_ << ": am alocat " << numarNote_
              << " note la adresa " << note_ << '\n';
}

// ---------- DESTRUCTOR ----------
Student::~Student()
{
    std::cout << "[destructor]  " << (nume_.empty() ? "(obiect mutat)" : nume_)
              << ": eliberez adresa " << note_ << '\n';
    delete[] note_;     // delete[] pe nullptr e sigur, nu face nimic
}

// ---------- COPY CONSTRUCTOR ----------
#ifndef SHALLOW_COPY
Student::Student(const Student& other)
    : nume_(other.nume_ + " (copie)"),
      note_(new int[other.numarNote_]),
      numarNote_(other.numarNote_)
{
    for (int i = 0; i < numarNote_; ++i)
        note_[i] = other.note_[i];

    std::cout << "[copy]        " << nume_ << ": vector NOU la adresa " << note_ << '\n';
}
#endif

// ---------- MOVE CONSTRUCTOR ----------
Student::Student(Student&& other) noexcept
    : nume_(std::move(other.nume_)),
      note_(other.note_),
      numarNote_(other.numarNote_)
{
    other.note_      = nullptr;
    other.numarNote_ = 0;

    std::cout << "[move]        " << nume_ << ": am preluat adresa " << note_
              << " fara sa copiez nimic\n";
}

// ---------- METODE ----------
void Student::setNota(int index, int nota)
{
    if (index < 0 || index >= numarNote_) {
        std::cout << "  Eroare: indexul " << index << " nu exista!\n";
        return;
    }
    if (nota < 1 || nota > 10) {
        std::cout << "  Eroare: nota " << nota << " nu e intre 1 si 10!\n";
        return;
    }
    note_[index] = nota;
}

double Student::getMedie() const
{
    if (numarNote_ == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < numarNote_; ++i)
        suma += note_[i];
    return static_cast<double>(suma) / numarNote_;
}

void Student::afiseaza() const
{
    if (note_ == nullptr) {
        std::cout << "  (obiect gol - resursele au fost mutate)\n";
        return;
    }
    std::cout << "  " << nume_ << " | note:";
    for (int i = 0; i < numarNote_; ++i)
        std::cout << ' ' << note_[i];
    std::cout << " | media: " << getMedie() << '\n';
}

} 

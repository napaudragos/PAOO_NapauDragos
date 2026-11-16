#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
public:
    Student(const std::string& nume, int nota);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    void afiseaza() const;

private:
    std::string nume_;
    int*        nota_;
};

class Bursier : public Student
{
public:
    Bursier(const std::string& nume, int nota, int bursa);
    Bursier(const Bursier& other);
    Bursier& operator=(const Bursier& other);

    void afiseaza() const;

private:
    int bursa_;
};

#endif

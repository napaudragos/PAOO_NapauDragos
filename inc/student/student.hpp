#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

namespace catalog {

class Student
{
private:
    std::string nume_;
    int*        note_;       
    int         numarNote_;

public:
    Student(const std::string& nume, int numarNote);
    ~Student();

#ifdef SHALLOW_COPY
    Student(const Student& other) = default;   
#else
    Student(const Student& other);             
#endif

    
    Student(Student&& other) noexcept;

    
    void   setNota(int index, int nota);
    double getMedie() const;
    void   afiseaza() const;
};

} 

#endif 

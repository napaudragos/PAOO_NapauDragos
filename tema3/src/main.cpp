#include <student.hpp>
#include <iostream>

int main()
{
    std::cout << "Item 10: a = b = c\n";
    Student a("Ana", 9), b("Bogdan", 7), c("Cristi", 10);
    a = b = c;
    a.afiseaza(); std::cout << '\n';
    b.afiseaza(); std::cout << '\n';

    std::cout << "\nItem 11: a = a\n";
    a = a;
    a.afiseaza(); std::cout << '\n';

    std::cout << "\nItem 12: copy Bursier\n";
    Bursier x("Dan", 8, 500);
    Bursier y(x);
    Bursier z("Elena", 6, 0);
    z = x;
    y.afiseaza(); std::cout << '\n';
    z.afiseaza(); std::cout << '\n';

    return 0;
}

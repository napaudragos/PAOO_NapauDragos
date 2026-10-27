#include <student/student.hpp>
#include <iostream>
#include <utility>

using catalog::Student;

int main()
{
    std::cout << std::unitbuf;   

    std::cout << "=== 1. Constructor + incapsulare ===\n";
    Student ana("Ana", 3);
    ana.setNota(0, 9);
    ana.setNota(1, 10);
    ana.setNota(2, 8);
    ana.setNota(1, 15);   
    ana.setNota(7, 10);   
    
    ana.afiseaza();

    std::cout << "\n=== 2. Destructor ===\n";
    {
        Student temporar("Temporar", 1000);
        std::cout << "  ...ies din bloc acum...\n";
    }   
    std::cout << "  Am iesit din bloc, memoria lui Temporar a fost eliberata.\n";

    std::cout << "\n=== 3. Copy constructor ===\n";
    Student copie = ana;      
    copie.setNota(0, 4);      
    std::cout << "Original: "; ana.afiseaza();
    std::cout << "Copie:    "; copie.afiseaza();
#ifdef SHALLOW_COPY
    std::cout << "  !!! Copie superficiala: s-a schimbat si nota Anei !!!\n"
              << "  !!! La final, aceeasi adresa va fi stearsa de 2 ori -> crash !!!\n";
#else
    std::cout << "  Originalul a ramas neschimbat, fiecare are memoria lui.\n";
#endif

    std::cout << "\n=== 4. Move constructor ===\n";
    Student mutat = std::move(copie);   
    std::cout << "Mutat: "; mutat.afiseaza();
    std::cout << "Copie: "; copie.afiseaza();

    std::cout << "\n=== Final: destructorii se apeleaza automat (ordine inversa) ===\n";
    return 0;
}

#include <martor.hpp>
#include <config.hpp>
#include <item4.hpp>
#include <item5.hpp>
#include <item6.hpp>
#include <iostream>

using namespace tema2;

// Non-copyable objects are passed by reference
void afiseazaCont(const ContBancar& cont)
{
    cont.afiseaza();
}

int main()
{
    std::cout << std::unitbuf;

    std::cout << "=== ITEM 4: Initializeaza obiectele inainte sa le folosesti ===\n";

    std::cout << "\n--- 4.1 Tipurile de baza NU se initializeaza singure ---\n";
    int x = 0;   // built-in types are not initialized automatically
    std::cout << "  x = " << x << " (initializat explicit)\n";

    std::cout << "\n--- 4.2 Atribuire in constructor (GRESIT) ---\n";
    {
        Martor m("Ana");
        std::cout << "  >> construiesc StudentAtribuire:\n";
        StudentAtribuire s("Ana", 9, m);
        s.afiseaza();
        std::cout << "  >> ies din bloc\n";
    }

    std::cout << "\n--- 4.3 Lista de initializare (CORECT) ---\n";
    {
        Martor m("Ana");
        std::cout << "  >> construiesc StudentLista:\n";
        StudentLista s("Ana", 9, m);
        s.afiseaza();
        std::cout << "  >> ies din bloc\n";
    }

    std::cout << "\n--- 4.4 Ordinea de initializare = ordinea declararii ---\n";
    {
        OrdineInit o;
    }

    std::cout << "\n--- 4.5 Obiect static local in loc de global ---\n";
    std::cout << "  config() a fost creat la 4.3, la prima folosire.\n";
    std::cout << "  apel din main.cpp: nota maxima = " << config().notaMaxima() << '\n';
    std::cout << "  inca un apel:      nota maxima = " << config().notaMaxima() << '\n';

    std::cout << "\n=== ITEM 5: Ce functii scrie si apeleaza C++ pe ascuns ===\n";
    {
        std::cout << "  >> Carte a;        (constructor implicit generat)\n";
        Carte a;
        std::cout << "  >> Carte b(a);     (copy constructor generat)\n";
        Carte b(a);
        std::cout << "  >> b = a;          (operator= generat)\n";
        b = a;
        std::cout << "  >> ies din bloc    (destructor generat, pentru b apoi a)\n";
    }

    std::cout << "\n  Nota n1(9), n2(n1): copy constructor merge si cu membru const\n";
    Nota n1(9);
    Nota n2(n1);
    std::cout << "  n2 = " << n2.valoare() << '\n';
#ifdef DEMO_ERORI
    Nota n3;     // error: no default constructor
    n1 = n2;     // error: operator= deleted (const member)
#endif

    std::cout << "\n=== ITEM 6: Interzice functiile generate pe care nu le vrei ===\n";

    Apartament ap("Str. Lunga nr. 5");
    ap.afiseaza();

    ContBancar cont("RO49AAAA1B31007593840000", 1500);
    afiseazaCont(cont);

#ifdef DEMO_ERORI
    Apartament ap2(ap);          // error: private copy ctor in Uncopyable
    ContBancar cont2(cont);      // error: deleted copy ctor
    ContBancar cont3("RO00", 0);
    cont3 = cont;                // error: deleted operator=
#endif
    std::cout << "  Copierea lor nu compileaza (vezi build cu -DDEMO_ERORI=ON).\n";
    return 0;
}

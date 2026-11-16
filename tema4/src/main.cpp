#include <resurse.hpp>
#include <iostream>
#include <memory>

void functie(bool iesireDevreme)
{
    std::unique_ptr<Resursa> r(new Resursa);
    if (iesireDevreme)
        return;
    std::cout << "  lucrez cu resursa\n";
}

int main()
{
    Mutex m;

    std::cout << "Item 13: unique_ptr\n";
    functie(false);
    functie(true);

    std::cout << "\nItem 13: Lock\n";
    {
        Lock l(&m);
        std::cout << "  zona protejata\n";
    }

    std::cout << "\nItem 14: SharedLock\n";
    {
        SharedLock a(&m);
        {
            SharedLock b(a);
            std::cout << "  copii: " << a.nrCopii() << '\n';
        }
        std::cout << "  copii: " << a.nrCopii() << '\n';
    }

    std::cout << "\nItem 14: transfer de proprietate\n";
    std::unique_ptr<Resursa> p1(new Resursa);
    std::unique_ptr<Resursa> p2 = std::move(p1);
    std::cout << "  p1 " << (p1 ? "are" : "nu are") << " resursa, p2 "
              << (p2 ? "are" : "nu are") << " resursa\n";


    return 0;
}

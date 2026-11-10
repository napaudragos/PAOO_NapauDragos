#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace tema2 {

// Item 4: obiect "global" folosit din mai multe fisiere .cpp.
class Config
{
private:
    int notaMaxima_;

public:
    Config();
    int notaMaxima() const;
};

// In loc de o variabila globala (Config config;), folosim o FUNCTIE
// care intoarce un obiect static local. Astfel obiectul e creat garantat
// la primul apel, deci nu poate fi folosit inainte sa fie initializat.
Config& config();

}

#endif

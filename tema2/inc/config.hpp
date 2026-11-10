#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace tema2 {

// Item 4: shared object used from several translation units
class Config
{
private:
    int notaMaxima_;

public:
    Config();
    int notaMaxima() const;
};

// Function-local static instead of a global: created on first use,
// avoids the static initialization order fiasco
Config& config();

}

#endif

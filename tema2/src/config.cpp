#include <config.hpp>
#include <iostream>

namespace tema2 {

Config::Config()
    : notaMaxima_(10)
{
    std::cout << "    [Config] creat ACUM (la primul apel al lui config())\n";
}

int Config::notaMaxima() const
{
    return notaMaxima_;
}

Config& config()
{
    static Config instanta;   // constructed once, on first call
    return instanta;
}

}

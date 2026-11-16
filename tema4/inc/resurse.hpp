#ifndef RESURSE_HPP
#define RESURSE_HPP

#include <memory>

class Resursa
{
public:
    Resursa();
    ~Resursa();
};

// Simulated mutex
class Mutex
{
public:
    void lock();
    void unlock();
};

// Item 13: RAII - lock in constructor, unlock in destructor
// Item 14: copying is prohibited
class Lock
{
public:
    explicit Lock(Mutex* m);
    ~Lock();

    Lock(const Lock&)            = delete;
    Lock& operator=(const Lock&) = delete;

private:
    Mutex* m_;
};

// Item 14: reference counting, unlock when the last copy is destroyed
class SharedLock
{
public:
    explicit SharedLock(Mutex* m);
    long nrCopii() const;

private:
    std::shared_ptr<Mutex> m_;
};

#endif

#include <resurse.hpp>
#include <iostream>

Resursa::Resursa()  { std::cout << "  [Resursa] alocata\n"; }
Resursa::~Resursa() { std::cout << "  [Resursa] eliberata\n"; }

void Mutex::lock()   { std::cout << "  [Mutex] lock\n"; }
void Mutex::unlock() { std::cout << "  [Mutex] unlock\n"; }

Lock::Lock(Mutex* m)
    : m_(m)
{
    m_->lock();
}

Lock::~Lock()
{
    m_->unlock();
}

// Custom deleter: unlock instead of delete
SharedLock::SharedLock(Mutex* m)
    : m_(m, [](Mutex* p) { p->unlock(); })
{
    m_->lock();
}

long SharedLock::nrCopii() const
{
    return m_.use_count();
}

# Tema 1 PAOO - Catalog studenti

Aplicatie C++ simpla, construita cu CMake, care demonstreaza:

1. Build cu CMake (structura de laborator: `inc/`, `src/`, `CMakeLists.txt`)
2. Incapsulare (date `private`, acces doar prin metode care valideaza notele)
3. Initializarea membrilor in constructor (lista de initializare)
4. Eliberarea heap-ului in destructor (`delete[]`)
5. Suprascrierea copy constructor-ului (deep copy)
6. Move constructor

## Structura

```
tema1/
├── CMakeLists.txt
├── inc/student/student.hpp
└── src/
    ├── student.cpp
    └── main.cpp
```

## Build si rulare

```
mkdir build
cd build
cmake ..
cmake --build .
./catalog
```

## De ce e nevoie de copy constructor?

Clasa are un pointer `int* note_` catre memorie alocata pe heap.
Copy constructor-ul implicit copiaza doar adresa, deci doua obiecte
ajung sa foloseasca aceeasi memorie. Efecte:
- daca modifici copia, se modifica si originalul;
- la final, ambii destructori fac `delete[]` pe aceeasi adresa -> crash (double free).

Demonstratie (varianta gresita):

```
mkdir build_gresit
cd build_gresit
cmake -DSHALLOW_COPY=ON ..
cmake --build .
./catalog
```

## De ce e nevoie de move constructor?

Cand obiectul original nu mai e folosit (`std::move`), nu are rost sa
alocam si sa copiem tot vectorul. Move constructor-ul preia pointerul
si il pune pe `nullptr` in obiectul vechi, ca destructorul acestuia
sa nu stearga memoria preluata.

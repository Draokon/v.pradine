#include "zmogus.h"
#include "student.h"
#include <memory>
#include <iostream>

// Šis kodas NEGALI kompiliuotis: Zmogus z("a", "b"); // ERROR
// Demonstracija, kad Zmogus yra abstrakti

void abstrakcios_klases_testas() {
    // std::unique_ptr<Zmogus> z = std::make_unique<Zmogus>("A", "B"); // ERROR
    std::unique_ptr<Zmogus> s = std::make_unique<Studentas>("Vardas", "Pavarde", std::vector<int>{10, 9}, 8);
    s->info(); // veikia, nes Studentas paveldi info()
    // Zmogus z("A", "B"); // ERROR: negalima kurti abstraktaus objekto
}
int main() {
    abstrakcios_klases_testas();
    return 0;
}

//g++ test_zmogus.cpp zmogus.cpp student.cpp -o zmogus
// zmogus.exe
#ifndef UTILS_H
#define UTILS_H

#include "Lib.h"

enum ContainerType { VECTOR, LIST, DEQUE };

// Nuskaitymo funkcija:
template <typename Container>
void skaityti(const std::string& filename, Container& students) {
    ifstream fin(filename);
    string header;
    getline(fin, header);
    string vardas, pavarde;
    while (fin >> vardas >> pavarde) {
        vector<int> nd;
        int n;
        for (int i = 0; i < 5; i++) {
            if (fin >> n) nd.push_back(n);
        }
        int egzaminas;
        fin >> egzaminas;
        Studentas s(vardas, pavarde, nd, egzaminas);
        s.skaiciuoti_galutini();
        students.push_back(s);
    }
}

// Rūšiavimas
template <typename Container>
void rusiavimas(Container& students) {
    sort(students.begin(), students.end(),
        [](const Studentas& a, const Studentas& b) { return a.galutinis() < b.galutinis(); });
}
template <>
inline void rusiavimas(list<Studentas>& students) {
    students.sort([](const Studentas& a, const Studentas& b) { return a.galutinis() < b.galutinis(); });
}

// 1 strategija: Kopijuojama į du naujus konteinerius
template <typename Container>
void skirstymas1(const Container& students, Container& vargs, Container& kiet) {
    for (const auto& s : students) {
        if (s.galutinis() < 5.0) vargs.push_back(s);
        else kiet.push_back(s);
    }
}

// 2 strategija: Tik vargšiukai naujame, trinami iš bendro
template <typename Container>
void skirstymas2(Container& students, Container& vargs) {
    auto it = students.begin();
    while (it != students.end()) {
        if (it->galutinis() < 5.0) {
            vargs.push_back(*it);
            it = students.erase(it);
        } else ++it;
    }
}

// 3 strategija: STL partition/remove_if
template <typename Container>
void skirstymas3(Container& students, Container& vargs) {
    auto it = partition(students.begin(), students.end(), [](const Studentas& s) {
        return s.galutinis() < 5.0;
    });
    vargs.insert(vargs.end(), students.begin(), it);
    students.erase(students.begin(), it);
}
template <>
inline void skirstymas3(list<Studentas>& students, list<Studentas>& vargs) {
    students.remove_if([&vargs](const Studentas& s) {
        if (s.galutinis() < 5.0) {
            vargs.push_back(s);
            return true;
        }
        return false;
    });
}

#endif

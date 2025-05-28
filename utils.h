/**
 * @file utils.h
 *@brief pagalbinėsfunkcijos skirtos studentų duomenų apdorojimui
 */
#ifndef UTILS_H
#define UTILS_H

#include "Lib.h"

/**
 * @enum ContainerType
 * @brief konteinerio tipų enumeracija (VECTOR, LIST, DEQUE)
 */
enum ContainerType { VECTOR, LIST, DEQUE };

// Nuskaitymo funkcija:
/**
 * @brief Skaito studentų duomenis iš failo į nurodytą konteinerį.
 * @tparam Container STL suderinamas konteineris 
 * @param filename Failo pavadinimas, iš kurio bus skaitomi studentų duomenys.
 * @param students Konteineris, į kurį bus rašomi studentų duomenys.
 */
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
/**
 * @brief rūšiuoja studentus pagal galutinį pažymį.
 * 
 * @tparam Container STL, turintis begin() ir end() 
 * @param students studentų konteineris
 */
template <typename Container>
void rusiavimas(Container& students) {
    sort(students.begin(), students.end(),
        [](const Studentas& a, const Studentas& b) { return a.galutinis() < b.galutinis(); });
}
/**
 * @brief Rūšiuoja studentų sąrašą pagal galutinį pažymį
 * @param students Studentų sąrašas (list).
 */
template <>
inline void rusiavimas(list<Studentas>& students) {
    students.sort([](const Studentas& a, const Studentas& b) { return a.galutinis() < b.galutinis(); });
}

// 1 strategija: Kopijuojama į du naujus konteinerius
/**
 * @brief Skirsto studentus į dvi grupes: vargšus ir kietus.
 * @tparam Container STL suderinamas konteineris 
 * @param students Originalus studentų konteineris.
 * @param vargs Vargšų studentų konteineris, kuriame bus saugomi studentai su galutiniu pažymiu mažesniu nei 5.0.
 * @param kiet Kietų studentų konteineris, kuriame bus saugomi studentai su galutiniu pažymiu 5.0 ar didesniu.
 */
template <typename Container>
void skirstymas1(const Container& students, Container& vargs, Container& kiet) {
    for (const auto& s : students) {
        if (s.galutinis() < 5.0) vargs.push_back(s);
        else kiet.push_back(s);
    }
}
/**
 * @brief Skirsto studentus: vargšiukai kopijuojami į naują, trinami iš bendro konteinerio
 * @tparam Container STL suderinamas konteineris
 * @param students Pradinis studentų konteineris (bus iš jo trinami)
 * @param vargs Konteineris, kuriame bus studentai su galutinis < 5
 */
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
/**
 * @brief Skirsto studentus naudojant STL partition/remove_if
 * @tparam Container STL suderinamas konteineris
 * @param students Pradinis studentų konteineris (bus iš jo trinami)
 * @param vargs Konteineris, kuriame bus studentai su galutinis < 5
 */
// 3 strategija: STL partition/remove_if
template <typename Container>
void skirstymas3(Container& students, Container& vargs) {
    auto it = partition(students.begin(), students.end(), [](const Studentas& s) {
        return s.galutinis() < 5.0;
    });
    vargs.insert(vargs.end(), students.begin(), it);
    students.erase(students.begin(), it);
}

/**
 * @brief Skirsto studentų sąrašą naudojant remove_if (specializacija list)
 * @param students Studentų sąrašas (list), iš kurio bus trinami
 * @param vargs Sąrašas, į kurį bus kopijuojami studentai su galutinis < 5
 */
// Specializacija list konteineriui
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
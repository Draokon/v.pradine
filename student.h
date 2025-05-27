#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
    double galutinis;

    void skaiciuoti_galutini() {
        if (nd.empty()) {
            galutinisVid = 0;
            galutinis = 0.4 * 0 + 0.6 * egzaminas;
        } else {
            double vid = 0;
            for (auto n : nd) vid += n;
            vid /= nd.size();
            galutinisVid = vid;
            galutinis = 0.4 * vid + 0.6 * egzaminas;
        }
    }
};
#endif

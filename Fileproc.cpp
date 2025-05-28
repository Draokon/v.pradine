
#include "Fileproc.h"
#include "student.h"

void nuskaitytiFaila(const string& pav, vector<Studentas>& studentai) {
    ifstream fin(pav);
    string eilute;
    getline(fin, eilute); // skip header

    while (getline(fin, eilute)) {
        istringstream iss(eilute);
        string vardas, pavarde;
        vector<int> nd;
        int paz;
        iss >> vardas >> pavarde;
        while (iss >> paz) nd.push_back(paz);
        int egzaminas = nd.back(); nd.pop_back();
        Studentas s(vardas, pavarde, nd, egzaminas);
        s.skaiciuoti_galutini();
        studentai.push_back(s);
    }
    fin.close();
}

void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargs, vector<Studentas>& kiet) {
    for (const auto& s : studentai) {
        if (s.galutinis() < 5.0) vargs.push_back(s);
        else kiet.push_back(s);
    }
}

void isvestiIFailus(const vector<Studentas>& vargs, const vector<Studentas>& kiet, const string& pavPre) {
    ofstream foutV(pavPre + "_vargsiukai.txt");
    for (const auto& s : vargs) foutV << s.vardas() << " " << s.pavarde() << " " << s.galutinis() << "\n";

    ofstream foutG(pavPre + "_kietekai.txt");
    for (const auto& s : kiet) foutG << s.vardas() << " " << s.pavarde() << " " << s.galutinis() << "\n";
}
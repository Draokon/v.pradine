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

void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsai, vector<Studentas>& galvociai) {
    for (const auto& s : studentai) {
        if (s.galutinis() < 5.0) vargsai.push_back(s);
        else galvociai.push_back(s);
    }
}

void isvestiIFailus(const vector<Studentas>& vargsai, const vector<Studentas>& galvociai, const string& pavPre) {
    ofstream foutV(pavPre + "_vargsiukai.txt");
    for (const auto& s : vargsai) foutV << s.vardas() << " " << s.pavarde() << " " << s.galutinis() << "\n";

    ofstream foutG(pavPre + "_galvociai.txt");
    for (const auto& s : galvociai) foutG << s.vardas() << " " << s.pavarde() << " " << s.galutinis() << "\n";
}

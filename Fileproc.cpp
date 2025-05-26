#include "Fileproc.h"

void nuskaitytiFaila(const string& pav, vector<Studentas>& studentai) {
    ifstream fin(pav);
    string eilute;
    getline(fin, eilute); // skip header

    while (getline(fin, eilute)) {
        istringstream iss(eilute);
        Studentas s;
        iss >> s.vardas >> s.pavarde;
        int paz;
        while (iss >> paz) s.namuDarbai.push_back(paz);
        s.egzaminas = s.namuDarbai.back(); s.namuDarbai.pop_back();

        s.galutinisVid = 0.4 * (accumulate(s.namuDarbai.begin(), s.namuDarbai.end(), 0.0) / s.namuDarbai.size()) + 0.6 * s.egzaminas;
        studentai.push_back(s);
    }
    fin.close();
}

void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsai, vector<Studentas>& galvociai) {
    for (const auto& s : studentai) {
        if (s.galutinisVid < 5.0) vargsai.push_back(s);
        else galvociai.push_back(s);
    }
}

void isvestiIFailus(const vector<Studentas>& vargsai, const vector<Studentas>& galvociai, const string& pavPre) {
    ofstream foutV(pavPre + "_vargsiukai.txt");
    for (const auto& s : vargsai) foutV << s.vardas << " " << s.pavarde << " " << s.galutinisVid << "\n";

    ofstream foutG(pavPre + "_galvociai.txt");
    for (const auto& s : galvociai) foutG << s.vardas << " " << s.pavarde << " " << s.galutinisVid << "\n";
}

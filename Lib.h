#ifndef LIB_H
#define LIB_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::accumulate;
using std::sort;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};

double apskaiciuotiVidurki(const vector<int>& pazymiai, int egzaminas);
double apskaiciuotiMediana(vector<int>& pazymiai);
void nuskaitytiFaila(vector<Studentas>& studentai, const string& failoPav, int studentuKiekis);
void ivestiDuomenis(Studentas& studentas);
void generuotiDuomenis(Studentas& studentas, int pazymiuKiekis);
void spausdintiDuomenis(const Studentas& studentas, int pasirinkimas);

#endif

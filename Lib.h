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
#include <random>
#include <chrono>
#include <iomanip>

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
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::getline;
using std::istreambuf_iterator;
using std::to_string;
using std::istream;
using std::istringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::cin;
using std::ofstream;
using std::default_random_engine;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;

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

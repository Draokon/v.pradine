#include "Lib.h"
#include <iostream>
#include <random>

void ivestiDuomenis(Studentas& studentas) {
    string vardas, pavarde;
    cout << "Iveskite varda: ";
    cin >> vardas;
    cout << "Iveskite pavarde: ";
    cin >> pavarde;
    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);

    cout << "Iveskite namu darbu pazymius (baige iveskite 0 ): ";
    int pazymys;
    vector<int> nd;
    while (cin >> pazymys && pazymys != 0) {
        nd.push_back(pazymys);
    }
    studentas.setNd(nd);

    cout << "Iveskite egzamino rezultata: ";
    int egz;
    cin >> egz;
    studentas.setEgzaminas(egz);

    studentas.skaiciuoti_galutini();
}

void generuotiDuomenis(Studentas& studentas, int pazymiuKiekis) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    vector<int> nd;
    for (int i = 0; i < pazymiuKiekis; ++i) {
        nd.push_back(dis(gen));
    }
    int egz = dis(gen);

    studentas.setNd(nd);
    studentas.setEgzaminas(egz);
    studentas.skaiciuoti_galutini();
}

void spausdintiDuomenis(const Studentas& studentas, int pasirinkimas) {
    cout << left << setw(12) << studentas.vardas()
              << setw(12) << studentas.pavarde();
    if (pasirinkimas == 0) {
        cout << fixed << setprecision(2) << "(Med.) " << studentas.galutinisMed() << endl;
    } else if (pasirinkimas == 1) {
        cout << fixed << setprecision(2) << "(Vid.) " << studentas.galutinisVid() << endl;
    } else if (pasirinkimas == 2) {
        cout << fixed << setprecision(2) << "(Vid.) "<< setw(12) << studentas.galutinisVid()
                  << fixed << setprecision(2) << "(Med.) " << studentas.galutinisMed() << endl;
    }
}
#include "Lib.h"

double apskaiciuotiVidurki(const vector<int>& pazymiai, int egzaminas) {
    double suma = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
    double vidurkis = suma / pazymiai.size();
    return 0.4 * vidurkis + 0.6 * egzaminas;
}

double apskaiciuotiMediana(vector<int>& pazymiai) {
    sort(pazymiai.begin(), pazymiai.end());
    int n = pazymiai.size();
    if (n % 2 == 0) {
        return (pazymiai[n / 2 - 1] + pazymiai[n / 2]) / 2.0;
    } else {
        return pazymiai[n / 2];
    }
}

void nuskaitytiFaila(vector<Studentas>& studentai, const string& failoPav, int studentuKiekis) {
    ifstream file(failoPav);
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failoPav << endl;
        return;
    }

    string eilute;
    getline(file, eilute); 

    for (int i = 0; i < studentuKiekis && getline(file, eilute); ++i) {
        stringstream ss(eilute);
        Studentas studentas;
        int pazymys;

        ss >> studentas.vardas >> studentas.pavarde;
        
        studentas.namuDarbai.clear();
        for (int i = 0; i < 7; ++i) {     
            ss >> pazymys;
            studentas.namuDarbai.push_back(pazymys);
        }

        ss >> studentas.egzaminas;

        studentas.galutinisVid = apskaiciuotiVidurki(studentas.namuDarbai, studentas.egzaminas);
        studentas.galutinisMed = apskaiciuotiMediana(studentas.namuDarbai);

        studentai.push_back(studentas);
    }
    file.close();
}

void ivestiDuomenis(Studentas& studentas) {
    cout << "Iveskite varda: ";
    cin >> studentas.vardas;
    cout << "Iveskite pavarde: ";
    cin >> studentas.pavarde;

    cout << "Iveskite namu darbu pazymius (baige iveskite 0 ): ";
    int pazymys;
    while (cin >> pazymys && pazymys != 0) {
        studentas.namuDarbai.push_back(pazymys);
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> studentas.egzaminas;
}

void generuotiDuomenis(Studentas& studentas, int pazymiuKiekis) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    studentas.namuDarbai.clear();
    for (int i = 0; i < pazymiuKiekis; ++i) {
        studentas.namuDarbai.push_back(dis(gen));
    }
    studentas.egzaminas = dis(gen);
}

void spausdintiDuomenis(const Studentas& studentas, int pasirinkimas) {
    cout << left << setw(12) << studentas.vardas
         << setw(12) << studentas.pavarde;
    if (pasirinkimas == 0) {
        cout << fixed << setprecision(2) << "(Med.) " << studentas.galutinisMed << endl;
    } else if (pasirinkimas == 1) {
        cout << fixed << setprecision(2) << "(Vid.) " << studentas.galutinisVid << endl;
    } else if (pasirinkimas == 2) {
        cout << fixed << setprecision(2) << "(Vid.) "<< setw(12) << studentas.galutinisVid 
         << fixed << setprecision(2) << "(Med.) " << studentas.galutinisMed << endl;
    }
}

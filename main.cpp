#include "Lib.h"
int main() {
    try {
        vector<Studentas> studentai;
        int pasirinkimas;
        int pasirinkimas1;
        int pasirinkimas2;
        int studentuKiekis;
        string ats;

        cout << "Iveskite studentu skaiciu: ";
        cin >> studentuKiekis;

        if (studentuKiekis <= 0) {
            throw invalid_argument("Studentu skaicius turi buti teigiamas");
        }

        cout << "Pasirinkite veiksma:\n";
        cout << "1 - Ivesti duomenis ranka\n";
        cout << "2 - Generuoti pazymius\n";
        cout << "3 - Generuoti studentu vardus, pavardes ir pazymius\n";
        cout << "4 - Nuskaityti duomenis is failo\n";
        cout << "5 - Baigti darba\n";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            for (int i = 0; i < studentuKiekis; ++i) {
                Studentas studentas;
                ivestiDuomenis(studentas);
                studentas.galutinisVid = apskaiciuotiVidurki(studentas.namuDarbai, studentas.egzaminas);
                studentas.galutinisMed = apskaiciuotiMediana(studentas.namuDarbai);
                studentai.push_back(studentas);
            }
        } else if (pasirinkimas == 2 || pasirinkimas == 3) {
            int pazymiuKiekis;
            cout << "Iveskite kiek studentas tures namu darbu pazymiu: ";
            while (!(cin >> pazymiuKiekis) || pazymiuKiekis <= 0) {
                cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
                cin.clear();
            }
            for (int i = 0; i < studentuKiekis; ++i) {
                Studentas studentas;
                generuotiDuomenis(studentas, pazymiuKiekis);
                cout << "Pazymiai:\n";
                for (int i = 0; i < studentas.namuDarbai.size(); ++i) {
                    cout << "ND " << i + 1 << ": " << studentas.namuDarbai[i] << endl;
                }
                cout << "Egzamino pazymys: " << studentas.egzaminas << endl;
                studentas.galutinisVid = apskaiciuotiVidurki(studentas.namuDarbai, studentas.egzaminas);
                studentas.galutinisMed = apskaiciuotiMediana(studentas.namuDarbai);
                studentai.push_back(studentas);
            }
        } else if (pasirinkimas == 4) {
            string failoPavadinimas = "studentai1000000.txt";
            try {
                nuskaitytiFaila(studentai, failoPavadinimas, studentuKiekis);
            } catch (const runtime_error& e) {
                cout << "Klaida atidarant faila: " << e.what() << endl;
                return 1;
            }
        } else if (pasirinkimas == 5) {
            cout << "Baigiate darba. Iki! \n";
            return 0;
        } else {
            throw invalid_argument("Neteisingas pasirinkimas!");
        }

        do {
            cout << "Norite skaiciuoti vidurki, mediana ar abu? Mediana - 0, Vidurkis - 1, Abu - 2: ";
            cin >> pasirinkimas;

            if (pasirinkimas == 0) {
                ats = "Galutinis(Med.)";
            } else if (pasirinkimas == 1) {
                ats = "Galutinis(Vid.)";
            } else if (pasirinkimas == 2) {
                ats = "Galutinis(Vid.)  Galutinis(Med.)";
            } else {
                throw invalid_argument("Neteisingas pasirinkimas!");
            }
        } while (pasirinkimas != 0 && pasirinkimas != 1 && pasirinkimas != 2);

        do {
            cout << "Ar norite rusiuoti studentus? Taip - 1, Ne - 0: ";
            cin >> pasirinkimas1;

            if (pasirinkimas1 == 1) {
                cout << "Pasirinkite kaip norite rusiuoti studentus:\n";
                cout << "0 - Pagal mediana\n";
                cout << "1 - Pagal vidurki\n";
                cin >> pasirinkimas2;

            } else if (pasirinkimas1 == 0) {
                break;
            }
        } while (pasirinkimas1 != 0 && pasirinkimas1 != 1);

        if (pasirinkimas2 == 0) {
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.galutinisMed < b.galutinisMed;
            });
     } else if (pasirinkimas2 == 1) {
          sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.galutinisVid < b.galutinisVid;
         });
    }

 cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(15) << ats << endl;
cout << "-----------------------------------------------------------------" << endl;

for (const auto& studentas : studentai) {
            spausdintiDuomenis(studentas, pasirinkimas);
        }

    } catch (const invalid_argument& e) {
        cout << "Klaida: " << e.what() << endl;
    } catch (const std::runtime_error& e) {
        cout << "Klaida: " << e.what() << endl;
    } catch (const std::exception& e) {
        cout << "Klaida: " << e.what() << endl;
    }
    return 0;
}

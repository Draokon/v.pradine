
#include "Filegen.h"
#include "Lib.h"

void generuotiFaila(const string& pavadinimas, int irasuSkaicius, int pazymiuKiekis) {
    ofstream fout(pavadinimas);
    fout << "Vardas Pavarde";
    for (int i = 1; i <= pazymiuKiekis; ++i) fout << " ND" << i;
    fout << " Egzaminas\n";

    mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(1, 10);

    for (int i = 1; i <= irasuSkaicius; ++i) {
        fout << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < pazymiuKiekis; ++j) fout << " " << dist(gen);
        fout << " " << dist(gen) << "\n";
    }
    fout.close();
}
#include "Filegen.h"
#include "Fileproc.h"
#include "Timer.h"
#include "Lib.h"
#include <iostream>

int main() {
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    int pazymiuKiekis = 5;

    // 1 tyrimas: failu kurimas
    for (int n : dydziai) {
        Timer t;
        generuotiFaila("studentai_" + to_string(n) + ".txt", n, pazymiuKiekis);
        cout << "Sugeneruota " << n << " irasu per " << t.elapsed() << " s.\n";
    }

    // 2 tyrimas: apdorojimas
    for (int n : dydziai) {
        vector<Studentas> visi, vargsai, galvociai;
        Timer total;

        Timer t1;
        nuskaitytiFaila("studentai_" + to_string(n) + ".txt", visi);
        cout << "[Nuskaitymas " << n << "] " << t1.elapsed() << " s.\n";

        Timer t2;
        padalintiStudentus(visi, vargsai, galvociai);
        cout << "[Rusiavimas " << n << "] " << t2.elapsed() << " s.\n";

        Timer t3;
        isvestiIFailus(vargsai, galvociai, "rezultatai_" + to_string(n));
        cout << "[Isvedimas " << n << "] " << t3.elapsed() << " s.\n";

        cout << "[Viso " << n << "] " << total.elapsed() << " s.\n\n";
    }

    return 0;
}

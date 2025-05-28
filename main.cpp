#include "utils.h"
#include "Timer.h"
#include "Filegen.h"
#include "Fileproc.h"
#include "student.h"
#include "Lib.h"

void benchmark(const string& failas, ContainerType tipas, size_t kiekis) {
    cout << "---- " << (tipas==VECTOR?"VECTOR":tipas==LIST?"LIST":"DEQUE") << " ----\n";
    if (tipas == VECTOR) {
        vector<Studentas> students, vargs, kiet;

        auto t1 = start_timer();
        skaityti(failas, students);
        double nuskaitymas = elapsed_time(t1);

        cout << left << setw(25) << "Nuskaitymas (s): " << nuskaitymas << endl;
        cout << "Nuskaityta studentu: " << students.size() << endl;

        auto t2 = start_timer();
        rusiavimas(students);
        double rusiavimas_time = elapsed_time(t2);
        cout << left << setw(25) << "Rusiavimas (s): " << rusiavimas_time << endl;

        auto t3 = start_timer();
        skirstymas1(students, vargs, kiet);
        double skirst1 = elapsed_time(t3);
        cout << left << setw(25) << "Skirstymas1 (s): " << skirst1 << endl;

        vargs.clear(); vector<Studentas> students2 = students;
        auto t4 = start_timer();
        skirstymas2(students2, vargs);
        double skirst2 = elapsed_time(t4);
        cout << left << setw(25) << "Skirstymas2 (s): " << skirst2 << endl;

        vargs.clear(); vector<Studentas> students3 = students;
        auto t5 = start_timer();
        skirstymas3(students3, vargs);
        double skirst3 = elapsed_time(t5);
        cout << left << setw(25) << "Skirstymas3 (s): " << skirst3 << endl;
    }
    else if (tipas == LIST) {
        list<Studentas> students, vargs, kiet;

        auto t1 = start_timer();
        skaityti(failas, students);
        double nuskaitymas = elapsed_time(t1);

        cout << left << setw(25) << "Nuskaitymas (s): " << nuskaitymas << endl;
        cout << "Nuskaityta studentu: " << students.size() << endl;

        auto t2 = start_timer();
        rusiavimas(students);
        double rusiavimas_time = elapsed_time(t2);
        cout << left << setw(25) << "Rusiavimas (s): " << rusiavimas_time << endl;

        auto t3 = start_timer();
        skirstymas1(students, vargs, kiet);
        double skirst1 = elapsed_time(t3);
        cout << left << setw(25) << "Skirstymas1 (s): " << skirst1 << endl;

        vargs.clear(); list<Studentas> students2 = students;
        auto t4 = start_timer();
        skirstymas2(students2, vargs);
        double skirst2 = elapsed_time(t4);
        cout << left << setw(25) << "Skirstymas2 (s): " << skirst2 << endl;

        vargs.clear(); list<Studentas> students3 = students;
        auto t5 = start_timer();
        skirstymas3(students3, vargs);
        double skirst3 = elapsed_time(t5);
        cout << left << setw(25) << "Skirstymas3 (s): " << skirst3 << endl;
    }
    else if (tipas == DEQUE) {
        deque<Studentas> students, vargs, kiet;

        auto t1 = start_timer();
        skaityti(failas, students);
        double nuskaitymas = elapsed_time(t1);

        cout << left << setw(25) << "Nuskaitymas (s): " << nuskaitymas << endl;
        cout << "Nuskaityta studentu: " << students.size() << endl;

        auto t2 = start_timer();
        rusiavimas(students);
        double rusiavimas_time = elapsed_time(t2);
        cout << left << setw(25) << "Rusiavimas (s): " << rusiavimas_time << endl;

        auto t3 = start_timer();
        skirstymas1(students, vargs, kiet);
        double skirst1 = elapsed_time(t3);
        cout << left << setw(25) << "Skirstymas1 (s): " << skirst1 << endl;

        vargs.clear(); deque<Studentas> students2 = students;
        auto t4 = start_timer();
        skirstymas2(students2, vargs);
        double skirst2 = elapsed_time(t4);
        cout << left << setw(25) << "Skirstymas2 (s): " << skirst2 << endl;

        vargs.clear(); deque<Studentas> students3 = students;
        auto t5 = start_timer();
        skirstymas3(students3, vargs);
        double skirst3 = elapsed_time(t5);
        cout << left << setw(25) << "Skirstymas3 (s): " << skirst3 << endl;
    }
}

int main() {
    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};
    int pazymiuKiekis = 5;

    for (int n : dydziai) {
        TimerPoint t_start = start_timer();
        generuotiFaila("studentai_" + to_string(n) + ".txt", n, pazymiuKiekis);
        cout << "Sugeneruota " << n << " irasu per " << elapsed_time(t_start) << " s.\n";
    }

    // 2 tyrimas: apdorojimas
    
    for (int n : dydziai) {
        vector<Studentas> visi, vargs, kiet;
        TimerPoint total_start = start_timer();

        TimerPoint t1_start = start_timer();
        nuskaitytiFaila("studentai_" + to_string(n) + ".txt", visi);
        cout << "[Nuskaitymas " << n << "] " << elapsed_time(t1_start) << " s.\n";

        TimerPoint t2_start = start_timer();
        padalintiStudentus(visi, vargs, kiet);
        cout << "[Rusiavimas " << n << "] " << elapsed_time(t2_start) << " s.\n";

        TimerPoint t3_start = start_timer();
        isvestiIFailus(vargs, kiet, "rezultatai_" + to_string(n));
        cout << "[Isvedimas " << n << "] " << elapsed_time(t3_start) << " s.\n";

        cout << "[Viso " << n << "] " << elapsed_time(total_start) << " s.\n\n";
    }

    vector<string> failai = {
        "studentai_1000.txt",
        //"studentai_10000.txt",
        "studentai_100000.txt",
        "studentai_1000000.txt"
    };

    for (const auto& f : failai) {
        cout << "\n----- Testas su failu: " << f << " -----\n";
        benchmark(f, VECTOR, 0);
        benchmark(f, LIST, 0);
        benchmark(f, DEQUE, 0);
    }

    return 0;
}

/*
g++ -O1 main.cpp student.cpp Filegen.cpp Fileproc.cpp Lib.cpp -o programa_O1
g++ -O2 main.cpp student.cpp Filegen.cpp Fileproc.cpp Lib.cpp -o programa_O2
g++ -O3 main.cpp student.cpp Filegen.cpp Fileproc.cpp Lib.cpp -o programa_O3
*/

/*
programa_O1.exe
programa_O2.exe
programa_O3.exe
*/
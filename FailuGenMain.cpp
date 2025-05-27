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
    TimerPoint t_start = start_timer();
    generuotiFaila("studentai_" + std::to_string(n) + ".txt", n, pazymiuKiekis);
    std::cout << "Sugeneruota " << n << " irasu per " << elapsed_time(t_start) << " s.\n";
}


 // 2 tyrimas: apdorojimas
for (int n : dydziai) {
    std::vector<Studentas> visi, vargsai, galvociai;
    TimerPoint total_start = start_timer();

    TimerPoint t1_start = start_timer();
    nuskaitytiFaila("studentai_" + std::to_string(n) + ".txt", visi);
    std::cout << "[Nuskaitymas " << n << "] " << elapsed_time(t1_start) << " s.\n";

    TimerPoint t2_start = start_timer();
    padalintiStudentus(visi, vargsai, galvociai);
    std::cout << "[Rusiavimas " << n << "] " << elapsed_time(t2_start) << " s.\n";

    TimerPoint t3_start = start_timer();
    isvestiIFailus(vargsai, galvociai, "rezultatai_" + std::to_string(n));
    std::cout << "[Isvedimas " << n << "] " << elapsed_time(t3_start) << " s.\n";

    std::cout << "[Viso " << n << "] " << elapsed_time(total_start) << " s.\n\n";
}

    return 0;
}

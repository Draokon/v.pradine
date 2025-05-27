// src/Benchmark.cpp
#include "Benchmark.h"
#include "Lib.h"
#include "FileUtils.h"
#include "sorting.h"
#include "Timer.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

void benchmark(const std::string& failas) {
    std::cout << "Benchmark failui: " << failas << "\n";

    // VECTOR
    {
        auto studentai = nuskaitytiStudentus(failas);
        std::vector<Student> v(studentai.begin(), studentai.end()), vargs;
        Timer t;
        skirstyk_partition(v, vargs);
        double laikas = t.elapsed();
        std::cout << "Vector: " << laikas << " s\n";
    }

    // LIST
    {
        auto studentai = nuskaitytiStudentus(failas);
        std::list<Student> l(studentai.begin(), studentai.end()), vargs;
        Timer t;
        skirstyk_partition(l, vargs);
        double laikas = t.elapsed();
        std::cout << "List: " << laikas << " s\n";
    }

    // DEQUE
    {
        auto studentai = nuskaitytiStudentus(failas);
        std::deque<Student> d(studentai.begin(), studentai.end()), vargs;
        Timer t;
        skirstyk_partition(d, vargs);
        double laikas = t.elapsed();
        std::cout << "Deque: " << laikas << " s\n";
    }
}

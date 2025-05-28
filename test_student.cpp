#include "student.h"
#include <cassert>
#include <sstream>
#include <iostream>

void test_rule_of_five() {
    std::vector<int> nd = {8, 9, 10};
    Studentas s1("Jonas", "Jonaitis", nd, 9);
    Studentas s2 = s1; // copy ctor
    assert(s2.vardas() == "Jonas");
    Studentas s3;
    s3 = s1; // copy assignment
    assert(s3.egzaminas() == 9);

    Studentas s4 = std::move(s1); // move ctor
    Studentas s5;
    s5 = std::move(s2); // move assign
    assert(s4.pavarde() == "Jonaitis");
    assert(s5.galutinisVid() == s3.galutinisVid());
}

void test_ivestis_isvedimas() {
    Studentas s;
    // Jonas Jonaitis 8 7 6 0 9
    std::istringstream iss("Jonas Jonaitis 8 7 6 0 9");
    iss >> s;
    assert(s.vardas() == "Jonas");
    assert(s.pavarde() == "Jonaitis");
    assert(s.nd().size() == 3);
    assert(s.nd()[0] == 8);
    assert(s.nd()[1] == 7);
    assert(s.nd()[2] == 6);
    assert(s.egzaminas() == 9);

    std::ostringstream oss;
    oss << s;
    std::string out = oss.str();
    std::cout << out << std::endl;
    assert(out.find("Jonas") != std::string::npos);
    assert(out.find("Jonaitis") != std::string::npos);
}

int main() {
    test_rule_of_five();
    std::cout << "Rule of five testas praejo!" << std::endl;
    test_ivestis_isvedimas();
    std::cout << "Testas praejo!" << std::endl;
    return 0;
}

//g++ test_student.cpp student.cpp -o stud
//stud.exe
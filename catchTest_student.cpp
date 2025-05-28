#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "student.h"


TEST_CASE("Studento konstruktorius ir getteriai veikia", "[Studentas]") {
    std::vector<int> nd = {8, 9, 10};
    Studentas s("Jonas", "Jonaitis", nd, 9);
    REQUIRE(s.vardas() == "Jonas");
    REQUIRE(s.pavarde() == "Jonaitis");
    REQUIRE(s.nd().size() == 3);
    REQUIRE(s.egzaminas() == 9);
}

TEST_CASE("Rule of Five (kopijavimo/perkėlimo konstruktoriai ir operatoriai)", "[Studentas][RuleOfFive]") {
    std::vector<int> nd = {8, 9, 10};
    Studentas s1("Jonas", "Jonaitis", nd, 9);

    Studentas s2 = s1; // copy constructor
    REQUIRE(s2.vardas() == "Jonas");
    REQUIRE(s2.pavarde() == "Jonaitis");
    REQUIRE(s2.galutinisVid() == s1.galutinisVid());

    Studentas s3;
    s3 = s1; // copy assignment
    REQUIRE(s3.egzaminas() == 9);

    Studentas s4 = std::move(s1); // move constructor
    REQUIRE(s4.pavarde() == "Jonaitis");

    Studentas s5;
    s5 = std::move(s2); // move assignment
    REQUIRE(s5.galutinisVid() == s3.galutinisVid());
}

TEST_CASE("Studento įvesties operatorius", "[Studentas][IO]") {
    Studentas s;
    std::istringstream iss("Jonas Jonaitis 8 7 6 0 9");
    iss >> s;
    REQUIRE(s.vardas() == "Jonas");
    REQUIRE(s.pavarde() == "Jonaitis");
    REQUIRE(s.nd().size() == 3);
    REQUIRE(s.nd()[0] == 8);
    REQUIRE(s.nd()[1] == 7);
    REQUIRE(s.nd()[2] == 6);
    REQUIRE(s.egzaminas() == 9);
}

TEST_CASE("Studento išvesties operatorius", "[Studentas][IO]") {
    Studentas s("Jonas", "Jonaitis", {8, 9, 10}, 9);
    std::ostringstream oss;
    oss << s;
    std::string out = oss.str();
    REQUIRE(out.find("Jonas") != std::string::npos);
    REQUIRE(out.find("Jonaitis") != std::string::npos);
}
TEST_CASE("Galutinių pažymių skaičiavimas", "[Studentas][Galutinis]") {
    Studentas s("Jonas", "Jonaitis", {8, 9, 10}, 9);
    s.skaiciuoti_galutini();
    REQUIRE(s.galutinisVid() == Approx(9.0).epsilon(0.01));
    REQUIRE(s.galutinisMed() == Approx(9.0).epsilon(0.01));
    REQUIRE(s.galutinis() == Approx(9.0).epsilon(0.01));
}
//g++ catchTest_student.cpp student.cpp -o stud
// ./stud
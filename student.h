#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisVid_;
    double galutinisMed_;
    double galutinis_;

public:
    // Konstruktoriai
    Studentas();
    Studentas(const std::string& vard, const std::string& pav, const std::vector<int>& nd, int egz);

    // Kopijavimo konstruktorius ir operatorius
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    // Destruktorius
    ~Studentas();

    // Getteriai
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    std::vector<int> nd() const { return nd_; }
    int egzaminas() const { return egzaminas_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }
    double galutinis() const { return galutinis_; }

    // Setteriai
    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setNd(const std::vector<int>& n) { nd_ = n; }
    void setEgzaminas(int e) { egzaminas_ = e; }

    // Kiti metodai
    void skaiciuoti_vidurki_ir_mediana();
    void skaiciuoti_galutini();
    void isvalytiNd() { nd_.clear(); }
    void pridetiNd(int n) { nd_.push_back(n); }

    bool operator<(const Studentas& other) const { return galutinis_ < other.galutinis_; }
};

#endif

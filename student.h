#ifndef STUDENT_H
#define STUDENT_H

#include "Lib.h"
class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egzaminas_;
    double galutinisVid_;
    double galutinisMed_;
    double galutinis_;

public:
    // Konstruktoriai
    Studentas();
    Studentas(const string& vard, const string& pav, const vector<int>& nd, int egz);

    // Kopijavimo konstruktorius ir operatorius
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    // Destruktorius
    ~Studentas();

    // Getteriai
    string vardas() const { return vardas_; }
    string pavarde() const { return pavarde_; }
    vector<int> nd() const { return nd_; }
    int egzaminas() const { return egzaminas_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }
    double galutinis() const { return galutinis_; }

    // Setteriai
    void setVardas(const string& v) { vardas_ = v; }
    void setPavarde(const string& p) { pavarde_ = p; }
    void setNd(const vector<int>& n) { nd_ = n; }
    void setEgzaminas(int e) { egzaminas_ = e; }

    // Kiti metodai
    void skaiciuoti_vidurki_ir_mediana();
    void skaiciuoti_galutini();
    void isvalytiNd() { nd_.clear(); }
    void pridetiNd(int n) { nd_.push_back(n); }

    bool operator<(const Studentas& other) const { return galutinis_ < other.galutinis_; }
};

#endif 

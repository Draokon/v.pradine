#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Zmogus.h"

class Studentas {
private:
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
    Studentas(const Studentas& other);                  //Rule of five copy constructor
    Studentas& operator=(const Studentas& other);       // Rule of five copy assignment operator
    Studentas(Studentas&& other) noexcept;              // Rule of five move constructor
    Studentas& operator=(Studentas&& other) noexcept;   // Rule of five move assignment operator  

    // Destruktorius
    ~Studentas();

    // Įvesties operatorius (iš srauto)
    friend std::istream& operator>>(std::istream& is, Studentas& s);

    // Išvesties operatorius (į srautą)
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

    // Getteriai
    std::vector<int> nd() const { return nd_; }
    int egzaminas() const { return egzaminas_; }
    double galutinisVid() const { return galutinisVid_; }
    double galutinisMed() const { return galutinisMed_; }
    double galutinis() const { return galutinis_; }

    // Setteriai
    void setNd(const std::vector<int>& n) { nd_ = n; }
    void setEgzaminas(int e) { egzaminas_ = e; }

    // Kiti metodai
    void skaiciuoti_vidurki_ir_mediana();
    void skaiciuoti_galutini();
    void isvalytiNd() { nd_.clear(); }
    void pridetiNd(int n) { nd_.push_back(n); }

    bool operator<(const Studentas& other) const { return galutinis_ < other.galutinis_; }
    // Privalomas abstraktaus metodo realizavimas
    void info() const override {
        std::cout << "Studentas: " << vardas_ << " " << pavarde_ << std::endl;
    }
};

#endif

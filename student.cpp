#include "Lib.h"

Studentas::Studentas()
    : vardas_(""), pavarde_(""), nd_(), egzaminas_(0), galutinisVid_(0), galutinisMed_(0), galutinis_(0) {}

Studentas::Studentas(const std::string& vard, const std::string& pav, const std::vector<int>& nd, int egz)
    : vardas_(vard), pavarde_(pav), nd_(nd), egzaminas_(egz), galutinisVid_(0), galutinisMed_(0), galutinis_(0)
{
    skaiciuoti_vidurki_ir_mediana();
    skaiciuoti_galutini();
}

Studentas::Studentas(const Studentas& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_), nd_(other.nd_), egzaminas_(other.egzaminas_),
      galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_), galutinis_(other.galutinis_) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinisVid_ = other.galutinisVid_;
        galutinisMed_ = other.galutinisMed_;
        galutinis_ = other.galutinis_;
    }
    return *this;
}

void Studentas::skaiciuoti_vidurki_ir_mediana() {
    if (nd_.empty()) {
        galutinisVid_ = 0;
        galutinisMed_ = 0;
        return;
    }
    double suma = std::accumulate(nd_.begin(), nd_.end(), 0.0);
    galutinisVid_ = suma / nd_.size();

    std::vector<int> nd_copy = nd_;
    std::sort(nd_copy.begin(), nd_copy.end());
    int n = nd_copy.size();
    if (n % 2 == 0)
        galutinisMed_ = (nd_copy[n / 2 - 1] + nd_copy[n / 2]) / 2.0;
    else
        galutinisMed_ = nd_copy[n / 2];
}

void Studentas::skaiciuoti_galutini() {
    skaiciuoti_vidurki_ir_mediana();
    galutinis_ = 0.4 * galutinisVid_ + 0.6 * egzaminas_;
}

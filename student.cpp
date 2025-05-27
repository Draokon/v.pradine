#include "Lib.h"

Studentas::Studentas()
    : Zmogus(), nd_{}, egzaminas_{0}, galutinisVid_{0}, galutinisMed_{0}, galutinis_{0} {}

Studentas::Studentas(const std::string& vard, const std::string& pav, const std::vector<int>& nd, int egz)
    : Zmogus(vard, pav), nd_(nd), egzaminas_(egz), galutinisVid_(0), galutinisMed_(0), galutinis_(0)
{
    skaiciuoti_vidurki_ir_mediana();
    skaiciuoti_galutini();
}

// Copy zmogus.h
Studentas::Studentas(const Studentas& other)
    : Zmogus(other), nd_(other.nd_), egzaminas_(other.egzaminas_),
    galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_), galutinis_(other.galutinis_) {}
//copy operator zmogus.h
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        Zmogus::operator=(other);
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galutinisVid_ = other.galutinisVid_;
        galutinisMed_ = other.galutinisMed_;
        galutinis_ = other.galutinis_;
    }
    return *this;
}
// Move
Studentas::Studentas(Studentas&& other) noexcept
    : Zmogus(std::move(other)), nd_(std::move(other.nd_)), egzaminas_(other.egzaminas_),
      galutinisVid_(other.galutinisVid_), galutinisMed_(other.galutinisMed_), galutinis_(other.galutinis_) {
    other.egzaminas_ = 0;
    other.galutinisVid_ = other.galutinisMed_ = other.galutinis_ = 0;
}
//move operator zmogus.h
Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        Zmogus::operator=(std::move(other));
        nd_ = std::move(other.nd_);
        egzaminas_ = other.egzaminas_;
        galutinisVid_ = other.galutinisVid_;
        galutinisMed_ = other.galutinisMed_;
        galutinis_ = other.galutinis_;
        other.egzaminas_ = 0;
        other.galutinisVid_ = other.galutinisMed_ = other.galutinis_ = 0;
    }
    return *this;
}
 
// Destruktorius
Studentas::~Studentas() {
    // Nėra dinaminės atminties, jei butu tai reiketu atlaisvint
}

//ivesties operatorius
istream& operator>>(istream& in, Studentas& s) {
    in >> s.vardas_ >> s.pavarde_;
    s.nd_.clear();
    int pazymys;
    while (in >> pazymys && pazymys != 0) {
        s.nd_.push_back(pazymys);
    }
    in >> s.egzaminas_; // egzaminas po 0
    s.skaiciuoti_galutini();
    return in;
}

//isvesties operatorius
ostream& operator<<(ostream& out, const Studentas& s) {
    out << s.vardas_ << " " << s.pavarde_ << " ";
    out << fixed << setprecision(2) << s.galutinisVid() << " " << s.galutinisMed() << " " << s.galutinis();
    return out;
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

/**
 * @file student.h
 * @class Studentas
 * @brief Klasė, kuri aprašo studentą, paveldinti iš Zmogus klasės, saugo nd, egzamina, skaiciuoja rezultatus
 */
#ifndef STUDENT_H
#define STUDENT_H

#include "Zmogus.h"
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Studentas :public Zmogus {
private:
    //std::string vardas_;
    //std::string pavarde_;
    /**
     * @brief Studento namų darbų pažymiai
     * 
     */
    std::vector<int> nd_;
    /**
     * @brief Egzaminas pažymys
     * 
     */
    int egzaminas_;
    /**
     * @brief galutinis pažymys pagal vidurkį
     * 
     */
    double galutinisVid_;
    /**
     * @brief galutinis pažymys pagal medianą
     * 
     */
    double galutinisMed_;
    /**
     * @brief galutinis pažymys (galutinė formulė)
     * 
     */
    double galutinis_;

public:
    // Konstruktoriai
    /**
     * @brief Construktorius be parametrų
     * 
     */
    Studentas();
    /**
     * @brief Konstruktorius su parametrais
     * @param vard studento vardas
     * @param pav studento pavardė
     * @param nd studento namų darbų pažymiai
     * @param egz studento egzaminas pažymys
     */
    Studentas(const std::string& vard, const std::string& pav, const std::vector<int>& nd, int egz);

    // Kopijavimo konstruktorius ir operatorius
    /**
     * @brief kopijavimo konstruktorius
     * @details Naudojamas, kai reikia sukurti naują Studentas objektą, kuris yra kopija kito Studentas objekto.
     * @param other kitas Studentas objektas
     */
    Studentas(const Studentas& other);                  //Rule of five copy constructor
    /**
     * @brief kopijavimo priskyrimo operatorius
     * @param other kitas Studentas objektas
     * @details Naudojamas, kai reikia priskirti vieną Studentas objektą kitam.
     * @return Studentas& nuoroda į šį objektą
     * @note Šis operatorius yra svarbus, kad būtų galima teisingai tvarkyti išteklius, pvz., dinamiškai paskirtą atmintį.
     */
    Studentas& operator=(const Studentas& other);       // Rule of five copy assignment operator
    /**
     * @brief perkėlimo konstruktorius
     * @details Naudojamas, kai reikia sukurti naują Studentas objektą, perkeliant iš kitų Studentas objekto.
     * @param other kitas Studentas objektas
     */
    Studentas(Studentas&& other) noexcept;              // Rule of five move constructor
    /**
     * @brief perkėlimo priskyrimo operatorius
     * @param other kitas Studentas objektas
     * @details Naudojamas, kai reikia priskirti vieną Studentas objektą kitam, perkeliant išteklius.
     */
    Studentas& operator=(Studentas&& other) noexcept;   // Rule of five move assignment operator  

    /**
     * @brief Destruktorius
     * 
     */
    // Destruktorius
    ~Studentas();
    /**
     * @brief Įvesties operatorius
     * @param is įvesties srautas
     * @param s studentas objektas
     * @details Naudojamas studento duomenims įvesti iš srauto.
     */

    // Įvesties operatorius (i srautą)
    friend std::istream& operator>>(std::istream& is, Studentas& s);

    // Išvesties operatorius (iš srauto)
    /**
     * @brief Išvesties operatorius
     * @param os išvesties srautas
     * @param s studentas objektas
     * @details Naudojamas studento duomenims išvesti į srautą.
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);


    // Getteriai
    /*
    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }
    std::vector<int> nd() const { return nd_; }
    int egzaminas() const { return egzaminas_; }
    */

   /**
    * @brief Grąžina studento namų darbų pažymių vektorių
    * @return namų darbų pažymiai
    */
    std::vector<int> nd() const { return nd_; } //zmogus.h
    /**
     * @brief gražina studento egzaminą pažymį
     * 
     * @return egzamino pazymys
     */
    int egzaminas() const { return egzaminas_; }//zmogus.h
    /**
     * @brief gražina studento galutinį pažymį pagal vidurkį
     * 
     * @return galutinis pažymys pagal vidurkį
     */
    double galutinisVid() const { return galutinisVid_; }
   /**
    * @brief gražina studento galutinį pažymį pagal medianą
    * 
    * @return galutinis pažymys pagal medianą
    */
    double galutinisMed() const { return galutinisMed_; }
    /**
     * @brief gražina studento galutinį pažymį
     * 
     * @return galutinis pažymys
     * @details Galutinis pažymys yra apskaičiuojamas pagal formulę: 0.4 * vidurkis + 0.6 * egzaminas
     */
    double galutinis() const { return galutinis_; }

    // Setteriai
    /*
    void setVardas(const std::string& v) { vardas_ = v; }
    void setPavarde(const std::string& p) { pavarde_ = p; }
    */

    /**
     * @brief nustato nauja namų darbų pažymių vektorių
     * @param n namų darbų pažymiai
     */
    void setNd(const std::vector<int>& n) { nd_ = n; }
    /**
     * @brief nustato naują egzamino pažymį
     * 
     * @param e egzaminas pažymys
     */
    void setEgzaminas(int e) { egzaminas_ = e; }

    // Kiti metodai
    /**
     * @brief suskaičiuoja vidurkį ir medianą iš namų darbų pažymių
     * 
     */
    void skaiciuoti_vidurki_ir_mediana();
    /**
     * @brief suskaičiuoja galutinį pažymį pagal vidurkį ir egzaminą
     * 
     */
    void skaiciuoti_galutini();
    /**
     * @brief išvalo namų darbų pažymių vektorių, visus elementus ištrina
     * 
     */
    void isvalytiNd() { nd_.clear(); }
    /**
     * @brief prideja naują namų darbų pažymį į vektorių
     * 
     * @param n pridedamas pažymys
     */
    void pridetiNd(int n) { nd_.push_back(n); }

    /**
     * @brief operatorius, kuris lygina du studentus pagal galutinį pažymį
     * 
     * @param other kitas studentas objektas
     */
    bool operator<(const Studentas& other) const { return galutinis_ < other.galutinis_; }
   
    // Privalomas abstraktaus metodo realizavimas
    /**
     * @brief realizuoja abstraktų metodą iš Zmogus klasės
     * 
     */
    void info() const override {
        std::cout << "Studentas: " << vardas_ << " " << pavarde_ << std::endl;
    }
};

#endif // STUDENT_H

/**
 * @file Zmogus.h
 * @brief apibrėžia abstrakčią bazinę klasę Žmogus, skirtą paveldėjimui
 */
#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

// Abstrakti bazinė klasė Žmogus
/**
 * @class Zmogus
 * @brief abstakti bazinė klasė, kuri aprašo žmogaus duomenis (vardą ir pavardę) 
 * 
 */
class Zmogus {
protected:
    /**
     * @brief Žmogaus vardas
     * 
     */
    std::string vardas_;
    /**
     * @brief Žmogaus pavardė
     * 
     */
    std::string pavarde_;
public:
    /**
     * @brief Konstruktorius be parametrų, inicializuoja vardą ir pavardę tuščiais stringais
     * 
     */
    Zmogus() : vardas_{}, pavarde_{} {}
    /**
     * @brief Konstruktorius su parametrais, inicializuoja vardą ir pavardę
     * 
     * @param v Žmogaus vardas
     * @param p Žmogaus pavardė
     */
    Zmogus(const std::string& v, const std::string& p) : vardas_(v), pavarde_(p) {}
    /**
     * @brief kopijavimo konstruktorius
     * 
     * @param other kitas Zmogus objektas 
     */
    Zmogus(const Zmogus& other) : vardas_(other.vardas_), pavarde_(other.pavarde_) {}
    /**
     * @brief perkeliamasis konstruktorius
     * 
     * @param other kitas Zmogus objektas
     */
    Zmogus(Zmogus&& other) noexcept : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)) {}
    /**
     * @brief kopijavimo priskyrimo operatorius
     * 
     * @param other kitas Zmogus objektas
     */
    Zmogus& operator=(const Zmogus& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
        }
        return *this;
    }
    /**
     * @brief perkėlimo priskyrimo operatorius
     * 
     * @param other kitas Zmogus objektas
     */
    Zmogus& operator=(Zmogus&& other) noexcept {
        if (this != &other) {
            vardas_ = std::move(other.vardas_);
            pavarde_ = std::move(other.pavarde_);
        }
        return *this;
    }
    /**
     * @brief Destruktorius
     * 
     */
    virtual ~Zmogus() = default;

    /**
     * @brief gražina žmogaus vardą
     * 
     * @return vardas
     */
    std::string vardas() const { return vardas_; }
    /**
     * @brief gražina žmogaus pavardę
     * 
     * @return pavarde
     */
    std::string pavarde() const { return pavarde_; }
    /**
     * @brief nustato naują vardą
     * 
     * @param v naujas vardas
     */
    void setVardas(const std::string& v) { vardas_ = v; }
    /**
     * @brief nustato naują pavardę
     * 
     * @param p nauja pavardė
     */
    void setPavarde(const std::string& p) { pavarde_ = p; }

    // daro klasę abstrakčia
    /**
     * @brief grąžina žmogaus informaciją
     * 
     * @details Šis metodas yra grynasis virtualus metodas, todėl kiekviena paveldėta klasė turi jį įgyvendinti.
     */
    virtual void info() const = 0;
};

#endif
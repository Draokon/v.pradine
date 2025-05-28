/**
 * @file Filegen.h
 * @brief Deklaruoja funkciją testinių duomenų failams generuoti
 */
#ifndef FILEGEN_H
#define FILEGEN_H
#include <string>

/**
 * @brief Generuoja studentų duomenų failą su nurodytu įrašų ir pažymių kiekiu
 * @param pavadinimas Sukuriamo failo pavadinimas
 * @param irasuSkaicius Studentų įrašų skaičius faile
 * @param pazymiuKiekis Kiek pažymių turi kiekvienas studentas
 */
void generuotiFaila(const std::string& pavadinimas, int irasuSkaicius, int pazymiuKiekis);

#endif
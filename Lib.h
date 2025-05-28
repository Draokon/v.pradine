/**
 * @file Lib.h
 * @brief Bendroji biblioteka ir funkcijos darbui su Studentas duomenimis ir pagalbiniai apibrėžimai.
 */
#ifndef LIB_H
#define LIB_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>
#include <deque>
#include <list>
#include "student.h"

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::ifstream;
using std::stringstream;
using std::accumulate;
using std::sort;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::getline;
using std::invalid_argument;
using std::runtime_error;
using std::istreambuf_iterator;
using std::to_string;
using std::istringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::cin;
using std::ofstream;
using std::default_random_engine;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;


// Funkcijos su klase Studentas
/**
 * @brief Nuskaito studentų duomenis iš failo į vektorių
 * @param pav Failo pavadinimas
 * @param studentai Vektorius, į kurį bus įrašyti duomenys
 */
void nuskaitytiFaila(const string& pav, vector<Studentas>& studentai);
/**
 * @brief Padalina studentus į dvi grupes pagal glautini pažymį
 * @param studentai Vektorius su visais studentais
 * @param vargs Vektorius, kuriame bus vargšų studentų duomenys
 * @param kiet Vektorius, kuriame bus kietų studentų duomenys
 */
void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargs, vector<Studentas>& kiet);
/**
 * @brief Išveda studentų duomenis į failus (vargsiukai ir kietekai)
 * @param vargs Vektorius su vargšų studentų duomenimis
 * @param kiet Vektorius su kietų studentų duomenimis
 * @param pavPre Pagrindinis failo pavadinimas (be priedų)
 */
void isvestiIFailus(const vector<Studentas>& vargs, const vector<Studentas>& kiet, const string& pavPre);

// Pagalbinės funkcijos (jei reikia rankinio įvedimo/generavimo)
/**
 * @brief Įveda studento duomenis iš standartinio įvesties srauto
 * @param studentas Studentas objektas, kuriam bus priskirti duomenys
 */
void ivestiDuomenis(Studentas& studentas);
/**
 * @brief Generuoja studento duomenis su atsitiktiniais pažymiais
 * @param studentas Studentas objektas, kuriam bus priskirti duomenys
 * @param pazymiuKiekis Kiek pažymių generuoti (namų darbų)
 */
void generuotiDuomenis(Studentas& studentas, int pazymiuKiekis);
/**
 * @brief Išveda studento duomenis į standartinį išvesties srautą
 * @param studentas Studentas objektas, kurio duomenys bus išvedami
 * @param pasirinkimas 0 - tik galutinis pažymys pagal medianą, 1 - tik pagal vidurkį, 2 - abu
 */
void spausdintiDuomenis(const Studentas& studentas, int pasirinkimas);

#endif

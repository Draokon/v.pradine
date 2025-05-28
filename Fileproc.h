
#ifndef FILEPROC_H
#define FILEPROC_H

#include "Lib.h"


void nuskaitytiFaila(const string& pav, vector<Studentas>& studentai);

void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargs, vector<Studentas>& kiet);

void isvestiIFailus(const vector<Studentas>& vargs, const vector<Studentas>& kiet, const string& pavPre);

#endif
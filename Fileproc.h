#ifndef FILEPROC_H
#define FILEPROC_H

#include "Lib.h"

void nuskaitytiFaila(const string& pav, vector<Studentas>& studentai);
void padalintiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsai, vector<Studentas>& galvociai);
void isvestiIFailus(const vector<Studentas>& vargsai, const vector<Studentas>& galvociai, const string& pavPre);
#endif

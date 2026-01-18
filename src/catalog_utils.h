#pragma once
#include <string>
#include <vector>
#include "student.h"
#include "materii.h"
#include "nota.h"

void AfisareMeniu();
void AfisareStudenti(const std::vector<Student>& studenti, const std::vector<Nota>& note);
void AfisareMaterii(const std::vector<Materie>& materii);

bool studentExistent(const std::vector<Student>& studenti, const std::string& numeCautat);
bool materieExistenta(const std::vector<Materie>& materii, const std::string& numeCautat);

double CalculeazaMediaStudentului(const std::vector<Nota>& note, const std::string& numeStudent);
double CalculeazaMediaMateriei(const std::vector<Nota>& note, const std::string& numeMaterie);
double CalculeazaMediaGenerala(const std::vector<Nota>& note);
void AfiseazaCeaMaiBunaSiCeaMaiSlabaMaterie(const std::vector<Materie>& materii, const std::vector<Nota>& note);


void IncarcaStudentiCSV(std::vector<Student>& studenti);
void IncarcaMateriiCSV(std::vector<Materie>& materii);
void IncarcaNoteCSV(std::vector<Nota>& note);

void SalveazaStudentiCSV(const std::vector<Student>& studenti);
void SalveazaMateriiCSV(const std::vector<Materie>& materii);
void SalveazaNoteCSV(const std::vector<Nota>& note);

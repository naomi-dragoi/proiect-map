#pragma once
#include <string>
#include <vector>
#include "student.h"
#include "materii.h"
#include "nota.h"

// Afisari
void AfisareMeniu();
void AfisareStudenti(const std::vector<Student>& studenti, const std::vector<Nota>& note);
void AfisareMaterii(const std::vector<Materie>& materii);

// Validari
bool studentExistent(const std::vector<Student>& studenti, const std::string& numeCautat);
bool materieExistenta(const std::vector<Materie>& materii, const std::string& numeCautat);

// Medii
double CalculeazaMediaStudentului(const std::vector<Nota>& note, const std::string& numeStudent);
double CalculeazaMediaMateriei(const std::vector<Nota>& note, const std::string& numeMaterie);
double CalculeazaMediaGenerala(const std::vector<Nota>& note);
void AfiseazaCeaMaiBunaSiCeaMaiSlabaMaterie(const std::vector<Materie>& materii, const std::vector<Nota>& note);

// Filtrare studenti/note dupa anumite criterii
void ListeazaNoteFiltrate(const std::vector<Nota>& note, const std::vector<Student>& studenti, const std::vector<Materie>& materii);
// Listeaza studentii cu media sub un prag dat
void ListeazaStudentiSubPrag(const std::vector<Student>& studenti, const std::vector<Nota>& note, double prag);
// Raport complet pentru un student (note pe materii + medie)
void RaportStudent(const std::vector<Student>& studenti, const std::vector<Nota>& note, const std::vector<Materie>& materii, const std::string& numeStudent);

// Import CSV 
void IncarcaStudentiCSV(std::vector<Student>& studenti);
void IncarcaMateriiCSV(std::vector<Materie>& materii);
void IncarcaNoteCSV(std::vector<Nota>& note);

// Export CSV
void SalveazaStudentiCSV(const std::vector<Student>& studenti);
void SalveazaMateriiCSV(const std::vector<Materie>& materii);
void SalveazaNoteCSV(const std::vector<Nota>& note);

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "catalog_utils.h"
using namespace std;

void AfisareMeniu()
{ 
    cout <<"-----------------------------------" << endl;
    cout <<"  APLICATIE DE GESTIONARE A NOTELOR" << endl; 
    cout <<"-----------------------------------" << endl;
    cout <<" 1. Adauga student " << endl;
    cout <<" 2. Adauga materie " << endl;
    cout <<" 3. Adauga nota " << endl;
    cout <<" 4. Afiseaza toti studentii " << endl;
    cout <<" 5. Calculeaza media studentului " << endl;
    cout <<" 6. Calculeaza media pe materie " << endl;
    cout <<" 7. Calculeaza media generala " << endl;
    cout <<" 8. Statistici: cea mai buna/slaba materie " << endl;    
    cout <<" 0. Iesire" << endl;
    cout <<" Alegeti o optiune " << endl;
    // Am  creat meniul pe care il va vedea utilizatorul
}


void AfisareStudenti(const vector<Student>& studenti, const vector<Nota>& note) {

    for (size_t i = 0; i < studenti.size(); i++) {
        const std::string& numeStudent = studenti[i].getNume();
        cout << "Student: " << numeStudent << endl;

        bool areNote = false;

        for (size_t j = 0; j < note.size(); j++) {
            if (note[j].getNumeStudent() == numeStudent) {
                cout << "  - " << note[j].getNumeMaterie()
                     << ": " << note[j].getNota() << endl;
                areNote = true;
            }
        }

        if (!areNote) {
            cout << "  (nu are note)" << endl;
        }
        cout << endl;
    }
}



bool studentExistent(const vector<Student>& studenti, const std::string& numeCautat) {
    for (size_t i = 0; i < studenti.size(); i++) {
        if (studenti[i].getNume() == numeCautat) {
            return true;
        }
    }
    return false;
}


bool materieExistenta(const vector<Materie>& materii, const std::string& numeCautat) {
    for (size_t i = 0; i < materii.size(); i++) {
        if (materii[i].getNume() == numeCautat) {
            return true;
        }
    }
    return false;
}


void AfisareMaterii(const vector<Materie>& materii) {
    if (materii.empty()) {
        cout << "Nu exista nicio materie inregistrata." << endl;
        return;
    }

    cout << "Lista materii:" << endl;
    for (size_t i = 0; i < materii.size(); i++) {
        cout << "ID: " << materii[i].getId()
             << " | Nume: " << materii[i].getNume() << endl;
    }
}


double CalculeazaMediaStudentului(const vector<Nota>& note, const std::string& numeStudent) {
    int suma = 0;
    int numarNote = 0;

    for (size_t i = 0; i < note.size(); i++) {
        if (note[i].getNumeStudent() == numeStudent) {
            suma += note[i].getNota();
            numarNote++;
        }
    }

    if (numarNote == 0) {
        return 0.0; // student fara note
    }

    return static_cast<double>(suma) / numarNote;
}


double CalculeazaMediaMateriei(const std::vector<Nota>& note, const std::string& numeMaterie) {
    int suma = 0, nr = 0;
    for (const auto& n : note) {
        if (n.getNumeMaterie() == numeMaterie) {
            suma += n.getNota();
            nr++;
        }
    }
    if (nr == 0) return 0.0;
    return static_cast<double>(suma) / nr;
}

double CalculeazaMediaGenerala(const std::vector<Nota>& note) {
    if (note.empty()) return 0.0;
    int suma = 0;
    for (const auto& n : note) suma += n.getNota();
    return static_cast<double>(suma) / note.size();
}

void AfiseazaCeaMaiBunaSiCeaMaiSlabaMaterie(const std::vector<Materie>& materii,
                                            const std::vector<Nota>& note) {
    if (materii.empty() || note.empty()) {
        std::cout << "Nu exista suficiente date (materii/note) pentru statistici.\n";
        return;
    }

    std::string bestNume, worstNume;
    double best = -1.0;
    double worst = 11.0;

    for (const auto& m : materii) {
        double medie = CalculeazaMediaMateriei(note, m.getNume());
        if (medie == 0.0) continue; // materia fara note

        if (medie > best) { best = medie; bestNume = m.getNume(); }
        if (medie < worst) { worst = medie; worstNume = m.getNume(); }
    }

    if (bestNume.empty()) {
        std::cout << "Nicio materie nu are note inca.\n";
        return;
    }

    std::cout << "Cea mai buna materie: " << bestNume << " (medie " << best << ")\n";
    std::cout << "Cea mai slaba materie: " << worstNume << " (medie " << worst << ")\n";
}


void SalveazaStudentiCSV(const vector<Student>& studenti) {
    ofstream f("studenti.csv");
    f << "id,nume\n";
    for (const auto& s : studenti) f << s.getId() << "," << s.getNume() << "\n";
}

void SalveazaMateriiCSV(const vector<Materie>& materii) {
    ofstream f("materii.csv");
    f << "id,nume\n";
    for (const auto& m : materii) f << m.getId() << "," << m.getNume() << "\n";
}

void SalveazaNoteCSV(const vector<Nota>& note) {
    ofstream f("note.csv");
    f << "student,materie,nota\n";
    for (const auto& n : note)
        f << n.getNumeStudent() << "," << n.getNumeMaterie() << "," << n.getNota() << "\n";
}


void IncarcaStudentiCSV(vector<Student>& studenti) {
    ifstream f("studenti.csv");
    if (!f.is_open()) return;

    string line;
    getline(f, line); // header
    while (getline(f, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr, nume;
        getline(iss, idStr, ',');
        getline(iss, nume);
        studenti.push_back(Student(stoi(idStr), nume));
    }
}

void IncarcaMateriiCSV(vector<Materie>& materii) {
    ifstream f("materii.csv");
    if (!f.is_open()) return;

    string line;
    getline(f, line); // header
    while (getline(f, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string idStr, nume;
        getline(iss, idStr, ',');
        getline(iss, nume);
        materii.push_back(Materie(stoi(idStr), nume));
    }
}

void IncarcaNoteCSV(vector<Nota>& note) {
    ifstream f("note.csv");
    if (!f.is_open()) return;

    string line;
    getline(f, line); // header
    while (getline(f, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        string student, materie, notaStr;
        getline(iss, student, ',');
        getline(iss, materie, ',');
        getline(iss, notaStr);
        note.push_back(Nota(student, materie, stoi(notaStr)));

}
}

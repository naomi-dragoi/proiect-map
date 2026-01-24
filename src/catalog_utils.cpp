#include <iostream>
#include <fstream> // pentru fisiere (citire/scriere CSV)
#include <sstream> // pentru parsare CSV
#include <limits> // pentru cin.ignore()
#include <vector> // pentru vectori
#include <set>  // pentru liste unice
#include <algorithm>  // pentru std::sort
#include <map>  // pentru grupare note pe materii
#include "catalog_utils.h"
using namespace std;

void AfisareMeniu()
{ 
    cout << "-----------------------------------" << endl;
    cout << "  APLICATIE DE GESTIONARE A NOTELOR" << endl; 
    cout << "-----------------------------------" << endl;
    cout << " 1. Adauga student " << endl;
    cout << " 2. Adauga materie " << endl;
    cout << " 3. Adauga nota " << endl;
    cout << " 4. Afiseaza toti studentii " << endl;
    cout << " 5. Calculeaza media studentului " << endl;
    cout << " 6. Calculeaza media pe materie " << endl;
    cout << " 7. Calculeaza media generala " << endl;
    cout << " 8. Statistici: cea mai buna/slaba materie " << endl; 
    cout << " 9. Listeaza note filtrate" << endl;  
    cout << " 10. Studenti sub prag" << endl; 
    cout << " 11. Raport situatie scolara" << endl;
    cout << " 0. Iesire" << endl;
    cout << " Alegeti o optiune " << endl;
    // Am  creat meniul pe care il va vedea utilizatorul
}


// Afiseaza toti studentii si, pentru fiecare, afiseaza notele pe materii (daca exista)
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

// Verifica daca exista deja un student cu un anumit nume in vectorul de studenti
bool materieExistenta(const vector<Materie>& materii, const std::string& numeCautat) {
    for (size_t i = 0; i < materii.size(); i++) {
        if (materii[i].getNume() == numeCautat) {
            return true;
        }
    }
    return false;
}


// Verifica daca exista deja o materie cu un anumit nume in vectorul de materii
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


// Media studentului
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


// Calculeaza media pentru o anumita materie (media tuturor notelor la acea materie)
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


// Calculeaza media generala (media tuturor notelor din lista)
double CalculeazaMediaGenerala(const std::vector<Nota>& note) {
    if (note.empty()) return 0.0;
    int suma = 0;
    for (const auto& n : note) suma += n.getNota();
    return static_cast<double>(suma) / note.size();
}


//  Afiseaza statistici: materia cu media cea mai mare si materia cu media cea mai mica
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

// Filtreaza notele/studentii dupa nume student, denumire materie sau interval valori
void ListeazaNoteFiltrate(const std::vector<Nota>& note, const std::vector<Student>& studenti, const std::vector<Materie>& materii) {
    
    if (note.empty()) {
        cout << "Nu exista note de afisat." << endl;
        return;
    }
    
    int tipFiltru;
    cout << "\nFiltrare note:\n";
    cout << "1. Dupa student\n";
    cout << "2. Dupa materie\n"; 
    cout << "3. Dupa interval valori\n";
    cout << "Alegeti tipul de filtrare: ";
    cin >> tipFiltru;
    cin.ignore(10000, '\n');  
    
    vector<Nota> noteFiltrate;
    
    switch (tipFiltru) {
        case 1: {  
            // Afiseaza studentii care au note
            cout << "\nStudenti cu note disponibile:\n";

            set<string> studentiCuNote;

            for (const auto& n : note) {
                studentiCuNote.insert(n.getNumeStudent());
            }

            for (const auto& nume : studentiCuNote) {
                cout << "- " << nume << endl;
            }
            
            cout << "\nNume student: ";
            string numeStudent;
            getline(cin, numeStudent);
            
            for (const auto& n : note) {
                if (n.getNumeStudent() == numeStudent) {
                    noteFiltrate.push_back(n);
                }
            }
            break;
        }
        
        case 2: { 
            // Afiseaza materiile existente
            cout << "\nMaterii disponibile:\n";
            AfisareMaterii(materii);
            
            // Studenti cu note la materie
            cout << "\nNume materie: ";
            string numeMaterie;
            getline(cin, numeMaterie);
            
            // Afiseaza studentii care au note la materia aleasa
            cout << "Studenti cu note la " << numeMaterie << ":\n";

            set<string> studentiLaMaterie;

            for (const auto& n : note) {
                if (n.getNumeMaterie() == numeMaterie) {
                    studentiLaMaterie.insert(n.getNumeStudent());
                }
            }

            for (const auto& nume : studentiLaMaterie) {
                cout << "- " << nume << endl;
            }
            
            // Filtreaza notele
            for (const auto& n : note) {
                if (n.getNumeMaterie() == numeMaterie) {
                    noteFiltrate.push_back(n);
                }
            }
            break;
        }
        
        case 3: {  
            int notaMin, notaMax;
            cout << "Nota minima: ";
            cin >> notaMin;
            cout << "Nota maxima: ";
            cin >> notaMax;
            cin.ignore(10000, '\n');
            
            for (const auto& n : note) {
                if (n.getNota() >= notaMin && n.getNota() <= notaMax) {
                    noteFiltrate.push_back(n);
                }
            }
            break;
        }
        
        default:
            cout << "Optiune invalida." << endl;
            return;
    }
    
    // Sortare descrescatoare dupa note
    std::sort(noteFiltrate.begin(), noteFiltrate.end(),
                [](const Nota& a, const Nota& b) {
                  return a.getNota() > b.getNota();  // descrescător
              });
    
    if (noteFiltrate.empty()) {
        cout << "Nu s-au gasit note pentru filtrul ales." << endl;
    } else {
        cout << "\nNote filtrate (ordonate descrescator):\n";
        for (const auto& n : noteFiltrate) {
            cout << "- " << n.getNumeStudent() << " | " << n.getNumeMaterie() << ": " << n.getNota() << endl;
        }
    }
}


void ListeazaStudentiSubPrag(const std::vector<Student>& studenti, const std::vector<Nota>& note, double prag) {
    
    if (studenti.empty()) {
        cout << "Nu exista studenti." << endl;
        return;
    }
    
    cout << "\nStudenti cu media sub " << prag << ":\n";
    
    int numarSubPrag = 0;
    
    for (const auto& student : studenti) {
        double media = CalculeazaMediaStudentului(note, student.getNume());
        
        if (media > 0.0 && media < prag) {  
            cout << numarSubPrag + 1 << ". " << student.getNume() 
                 << " (media: " << media << ")\n";  
            numarSubPrag++;
        }
    }
    
    if (numarSubPrag == 0) {
        cout << "Niciun student cu media sub " << prag << endl;
    } else {
        cout << "Total: " << numarSubPrag << " studenti sub prag.\n";
    }
}


void RaportStudent(const std::vector<Student>& studenti, const std::vector<Nota>& note, const std::vector<Materie>& materii, const std::string& numeStudent) {
    
    // Verifica daca studentul exista
    bool studentExista = false;

    for (const auto& s : studenti) {
        if (s.getNume() == numeStudent) {
            studentExista = true;
            break;
        }
    }

    if (!studentExista) {
        cout << "Studentul " << numeStudent << " nu exista.\n";
        return;
    }
    
    cout << "\n=== RAPORT " << numeStudent << " ===\n";
    
    // Grupare note pe materii
    map<string, vector<int>> notePeMaterie;  
    
    for (const auto& n : note) {
        if (n.getNumeStudent() == numeStudent) {
            notePeMaterie[n.getNumeMaterie()].push_back(n.getNota());
        }
    }
    
    double mediaGenerala = CalculeazaMediaStudentului(note, numeStudent);
    
    if (notePeMaterie.empty()) {
        cout << "Nu are note inca.\n";
        cout << "Media generala: " << mediaGenerala << "\n";
        return;
    }
    
    // Afisare pe materii + medii pe materie
    for (const auto& pereche : notePeMaterie) {
        const string& materie = pereche.first;
        const vector<int>& noteMaterie = pereche.second;
        
        cout << "\n" << materie << ":\n";
        double suma = 0;
        for (int nota : noteMaterie) {
            cout << "  - " << nota << endl;
            suma += nota;
        }
        cout << "  Media materie: " << suma / noteMaterie.size() << endl;
    }
    
    cout << "\n=== MEDIA GENERALA: " << mediaGenerala << " ===\n";
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
        if (line.empty()) continue; // Ignoram liniile goale 
        istringstream iss(line);
        string student, materie, notaStr;
        getline(iss, student, ',');
        getline(iss, materie, ',');
        getline(iss, notaStr);
        note.push_back(Nota(student, materie, stod(notaStr)));
    }
    // Citim fisierul CSV: sarim peste prima linie (header), apoi parsam fiecare rand in campuri
    // (student, materie, nota) si incarcam in vectorul de note.
}

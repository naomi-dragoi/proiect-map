#include <iostream>
#include <string>
#include <vector> 
#include <limits>
#include "student.h"
#include "materii.h"
#include "nota.h"
#include "catalog_utils.h"

using namespace std;


int main() {
   int optiune = -1; 
   vector<Student> studenti;
   vector<Materie> materii;
   vector<Nota> note;
   
    IncarcaStudentiCSV(studenti);
    IncarcaMateriiCSV(materii);
    IncarcaNoteCSV(note);


   while (true) {
   AfisareMeniu();

   cin >> optiune; // Se alege optiunea dorita

   // Verificam daca optiunea introdusa este corecta
   if (cin.fail()) {

        cout<<"Optiunea introdusa este invalida. Incercati din nou." << endl;

        // Curatam eroarea si stergem ce a ramas in buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        continue;
    }
   

   if (optiune == 0) {
        SalveazaStudentiCSV(studenti);
        SalveazaMateriiCSV(materii);
        SalveazaNoteCSV(note);
        cout << "Date salvate in CSV. Iesire din aplicatie.\n";
        break;

   }
   switch (optiune) {

    case 1: {
                // Adaugare studenti               
                int id;
                std::string nume;

                // Se introduc datele studentului
                cout << "Introduceti id-ul: ";
                cin >> id;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

               do {
                     cout << "Introduceti numele: ";
                    getline(cin, nume);

                    if (studentExistent(studenti, nume)) {
                        cout << "Exista deja un student cu acest nume. Incercati alt nume.\n";
                     }
                } while (studentExistent(studenti, nume));

                // Se salveaza datele studentului
                Student s(id, nume);
                studenti.push_back(s); // Se adauga in vector

                cout << "Student adaugat. Numar total de studenti: " << studenti.size() << endl;
                break;
         }

    
    case 2: {
                // Adaugare materii

                AfisareMaterii(materii);
                cout << endl;

                int id;
                std::string nume;

                cout << "Introduceti id-ul materiei: ";
                cin >> id;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                do {
                 cout << "Introduceti denumirea materiei: ";
                 getline(cin, nume);

                 if (materieExistenta(materii, nume)) {
                    cout << "Exista deja aceasta materie. Alegeti alta." << endl;
                }
                } while (materieExistenta(materii, nume));

                Materie m(id, nume);
                materii.push_back(m);

                cout << "Materie adaugata. Numar total de materii: " << materii.size() << endl;
                break;
        }

    case 3: {
                // Afisare studenti si materii, apoi adaugare nota in functie de informatii
                if (studenti.empty() || materii.empty()) {
                    cout << "Nu exista suficienti studenti sau materii pentru a adauga o nota." << endl;
                break;
            }

                AfisareStudenti(studenti, note);

                AfisareMaterii(materii);
                cout << endl;

                std::string numeStudent, numeMaterie;
                double nota;

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduceti numele studentului: ";
                getline(cin, numeStudent);

                if (!studentExistent(studenti, numeStudent)) {
                    cout << "Nu exista student cu acest nume." << endl;
                break;
                }   

                cout << "Introduceti denumirea materiei: ";
                getline(cin, numeMaterie);

                if (!materieExistenta(materii, numeMaterie)) {
                    cout << "Nu exista materie cu aceasta denumire." << endl;
                break;
                }

                cout << "Introduceti valoarea notei (1.0 - 10.0): ";
                cin >> nota;

                if (nota < 1 || nota > 10) {
                    cout << "Nota invalida. Trebuie sa fie intre 1.0 si 10.0" << endl;
                break;
                }

                Nota n(numeStudent, numeMaterie, nota);
                note.push_back(n);

                cout << "Nota adaugata. Numar total de note: " << note.size() << endl;
                break;
        }


    case 4: {
                AfisareStudenti(studenti, note);
                break;

         }

    case 5: {
                AfisareStudenti(studenti, note);
                std::string numeStudent;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduceti numele studentului pentru care calculati media: ";
                getline(cin, numeStudent);

                if (!studentExistent(studenti, numeStudent)) {
                    cout << "Nu exista student cu acest nume." << endl;
                    break;
                }

                double media = CalculeazaMediaStudentului(note, numeStudent);
                if (media == 0.0) {
                    cout << numeStudent << " nu are note inca." << endl;
                 } else {
                    cout << "Media lui " << numeStudent << " este: " << media << endl;
                }
                break;
        }

    case 6: {
                AfisareMaterii(materii);
                cout << endl;

                string numeMaterie;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Introduceti denumirea materiei: ";
                getline(cin, numeMaterie);

                if (!materieExistenta(materii, numeMaterie)) {
                    cout << "Nu exista materie cu aceasta denumire.\n";
                    break;
                }

                double media = CalculeazaMediaMateriei(note, numeMaterie);
                if (media == 0.0) cout << "Materia nu are note inca.\n";
                else cout << "Media la " << numeMaterie << " este: " << media << "\n";
                break;
        }

    case 7: {
                double mg = CalculeazaMediaGenerala(note);
                if (mg == 0.0) cout << "Nu exista note inca.\n";
                else cout << "Media generala (toate notele) este: " << mg << "\n";
                break;
        }

    case 8: {
                AfiseazaCeaMaiBunaSiCeaMaiSlabaMaterie(materii, note);
                break;
        }
    
    case 9: {
                ListeazaNoteFiltrate(note, studenti, materii);
                break;
        }

    case 10: {
                double prag;
                cout << "Introduceti pragul (ex: 5.0): ";
                cin >> prag;
                cin.ignore(10000, '\n');
    
                ListeazaStudentiSubPrag(studenti, note, prag);
                break;
        }

    case 11: {
                AfisareStudenti(studenti, note);  // arată studenții disponibili
                cout << "\nNume student pentru raport: ";
                string numeStudent;
                cin.ignore(10000, '\n');
                getline(cin, numeStudent);
    
                RaportStudent(studenti, note, materii, numeStudent);
                break;
        }   

    default:
                cout << "Optiune invalida. Incercati din nou" << endl;
                break;
        }
    }
   return 0;
}

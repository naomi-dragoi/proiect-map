#include <iostream>
#include <string>
#include <vector> 
#include "student.h"
#include "materii.h"
#include "note.h"

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
   cout <<" 0. Iesire" << endl;
   cout <<" Alegeti o optiune " << endl;
   // Am  creat meniul pe care il va vedea utilizatorul
}


void AfisareStudenti(const vector<Student> studenti){
  if (studenti.empty()) {
        cout << "Nu exista niciun student inregistrat." << endl;
        return;
  }

  cout << "Lista studenti:" << endl;
  for (size_t i = 0; i < studenti.size(); i++){
        cout << "ID: " << studenti[i].getId() << " | Nume: " << studenti[i].getNume() << endl;
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



int main() {
   int optiune = -1; 
   vector<Student> studenti;
   vector<Materie> materii;
   vector<Nota> note;
   
   while (true) {
   AfisareMeniu();

   cin >> optiune; // Se alege optiunea dorita

   // Verificam daca optiunea introdusa este corecta
   if (cin.fail()) {

        cout<<"Optiunea introdusa este invalida. Incercati din nou." << endl;

        // Curatam eroarea si stergem ce a ramas in buffer
        cin.clear();
        cin.ignore(1000, '\n');

        continue;
    }
   

   if (optiune == 0) {

      cout<<"Iesire din aplicatie." << endl;
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
                cin.ignore(1000, '\n');

                cout << "Introduceti numele: ";
                getline(cin, nume);

                // Se salveaza datele studentului
                Student s(id, nume);
                studenti.push_back(s); // Se adauga in vector

                cout << "Student adaugat. Numar total de studenti: " << studenti.size() << endl;
                break;
         }

    
    case 2: {
                // Adaugare materii
                int id;
                std::string nume;

                cout << "Introduceti id-ul materiei: ";
                cin >> id;
                cin.ignore(1000, '\n');

                cout << "Introduceti denumirea materiei: ";
                getline(cin, nume);

                // Verificam daca exista deja materia pe care dorim sa o introducem
                if (materieExistenta(materii, nume)) {
                cout << "Exista deja aceasta materie. Alegeti alta." << endl;
                break;
    }

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

                AfisareStudenti(studenti);

                AfisareMaterii(materii);
                cout << endl;

                std::string numeStudent, numeMaterie;
                int nota;

                cin.ignore(1000, '\n');

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

                cout << "Introduceti valoarea notei (1-10): ";
                cin >> nota;

                if (nota < 1 || nota > 10) {
                    cout << "Nota invalida. Trebuie sa fie intre 1 si 10." << endl;
                break;
                }

                Nota n(numeStudent, numeMaterie, nota);
                note.push_back(n);

                cout << "Nota adaugata. Numar total de note: " << note.size() << endl;
                break;
        }


    case 4:
                AfisareStudenti(studenti);
                break;
                // [TODO] afisare notele studentului

    case 5:
                cout << "[TODO] Aici se va calcula media unui student" << endl;
                break;

    default:
                cout << "Optiune invalida. Incercati din nou" << endl;
                break;
   }


}
   return 0;
}

#include <iostream>
#include <string>
#include <vector> 
#include "student.h"

using namespace std;


void AfisareMeniu()
{
   cout <<"-----------------------------------" << endl;
   cout <<"  APLICATIE DE GESTIONARE A NOTELOR" << endl; 
   cout <<"-----------------------------------" << endl;
   cout <<" 1. Adauga student " << endl;
   cout <<" 2. Adauga materie " << endl;
   cout <<" 3. Adauga nota " << endl;
   cout <<" 4. Afiseaza toate notele " << endl;
   cout <<" 5. Calculeaza media studentului " << endl;
   cout <<" 0. Iesire" << endl;
   cout <<" Alegeti o optiune " << endl;
   // Am  creat meniul pe care il va vedea utilizatorul
}


void AfisareStudenti(const vector<Student> studenti){
  if (studenti.empty()){
        cout << "Nu exista niciun student inregistrat." << endl;
        return;
  }

  cout << "Lista studenti:" << endl;
  for (size_t i = 0; i < studenti.size(); i++){
        cout << "ID: " << studenti[i].getId() << " | Nume: " << studenti[i].getNume() << endl;
  }
}


int main() {
   int optiune = -1; 
   vector<Student> studenti;

   // Verificam daca optiunea introdusa este corecta
   while (true){
    AfisareMeniu();
    
    cin >> optiune; // Se alege optiunea dorita
    
    if (cin.fail()){
        cout<<"Optiunea introdusa este invalida. Incercati din nou." << endl;

        // Curatam eroarea si stergem ce a ramas in buffer
        cin.clear();
        cin.ignore(1000, '\n');

        continue;
    }
   

   if (optiune == 0){

    cout<<"Iesire din aplicatie." << endl;
    break;

   }
   switch (optiune){

    case 1:{
                
        int id;
        std::string nume;

        cout << "Introduceti id-ul: ";
        cin >> id;
        cin.ignore(1000, '\n');

        cout << "Introduceti numele: ";
        getline(cin, nume);

        Student s(id, nume);
        studenti.push_back(s);

        cout << "Student adaugat. Numar total de studenti: " << studenti.size() << endl;
        break;
    }

    
    case 2:
            cout << "[TODO] Aici se va adauga o materie" << endl;
            break;
    
    case 3:
            cout << "[TODO] Aici se va adauga o nota" << endl;
            break;

    case 4:
            AfisareStudenti(studenti);
            break;

    case 5:
            cout << "[TODO] Aici se va calcula media unui student" << endl;
            break;

    default:
            cout << "Optiune invalida. Incercati din nou" << endl;
            break;
   }

   cout<<endl;
}
   return 0;
}

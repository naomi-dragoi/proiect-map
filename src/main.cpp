#include <iostream>

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
   //Am  creat meniul pe care il va vedea utilizatorul
}

int main() {
   int optiune = -1; 

   //Verificam daca optiunea introdusa este corecta
   while (true){
    AfisareMeniu();
    
    cin >> optiune; //Se alege optiunea dorita
    
    if (cin.fail()){
        cout<<"Optiunea introdusa este invalida. Incercati din nou." << endl;

        //Curatam eroarea si stergem ce a ramas in buffer
        cin.clear();
        cin.ignore(1000, '\n');

        continue;
    }
   

   if (optiune == 0){

    cout<<"Iesire din aplicatie." << endl;
    break;

   }
   switch (optiune){

    case 1:
            cout << "[TODO] Aici se va adauga un student" << endl;
            break;
    
    case 2:
            cout << "[TODO] Aici se va adauga o materie" << endl;
            break;
    
    case 3:
            cout << "[TODO] Aici se va adauga o nota" << endl;
            break;

    case 4:
            cout << "[TODO] Aici se vor afisa toate notele" << endl;
            break;

    case 5:
            cout << "[TODO] Aici se va calcula media unui student" << endl;
            break;

    default:
            cout << "Optiune invalida incearca din nou" << endl;
            break;
   }

   cout<<endl;
}
   return 0;
}

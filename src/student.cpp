#include "student.h"

// Constructor fara parametri
Student::Student() : id(0), nume("") {}

// Constructor cu parametri
Student::Student(int id, const std::string& nume) : id(id), nume(nume) {}

// Getter pentru id
int Student::getId() const {
    return id;
}

// Getter pentru nume
const std::string& Student::getNume() const {
    return nume;
}

// Setter pentru id
void Student::setId(int idNou) {
    id = idNou;
}

// Setter pentru nume
void Student::setNume(const std::string& numeNou) {
    nume = numeNou;
}

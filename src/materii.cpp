#include "materii.h"

Materie::Materie() : id(0), nume("") {}

Materie::Materie( int id, const std::string& nume) : id(id), nume(nume) {}

int Materie::getId() const {
    return id;
} 

const std::string& Materie::getNume() const {
    return nume;
}


void Materie::setId(int idNou) {
    id = idNou;
}

void Materie::setNume(const std::string& numeNou) {
    nume = numeNou;
}
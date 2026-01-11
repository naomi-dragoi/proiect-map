#include "note.h"

Nota::Nota() : numeStudent(""), numeMaterie(""), nota(0) {}

Nota::Nota(const std::string& numeStudent, const std::string& numeMaterie, int nota)  
            : numeStudent(numeStudent), numeMaterie(numeMaterie), nota(nota) {}

std::string Nota::getNumeStudent() const {
    return numeStudent;
}

std::string Nota::getNumeMaterie() const {
    return numeMaterie;
}

int Nota::getNota() const {
    return nota;
}

void Nota::setNumeStudent(const std::string& numeNou) {
    numeStudent = numeNou;
}

void Nota::setNumeMaterie(const std::string& numeNou) {
    numeMaterie = numeNou;
}

void Nota::setNota(int notaNoua) {
    nota = notaNoua;
}

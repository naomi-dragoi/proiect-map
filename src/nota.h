#pragma once
#include <string>

class Nota {
private:
    std::string numeStudent;  
    std::string numeMaterie;  
    double nota;                  

public:
    Nota();
    Nota(const std::string& numeStudent, const std::string& numeMaterie, double nota);

    std::string getNumeStudent() const;
    std::string getNumeMaterie() const;
    double getNota() const;

    void setNumeStudent(const std::string& numeNou);
    void setNumeMaterie(const std::string& numeNou);
    void setNota(double notaNoua);
};

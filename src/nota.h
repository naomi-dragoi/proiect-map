#pragma once
#include <string>

class Nota {
private:
    std::string numeStudent;  
    std::string numeMaterie;  
    int nota;                  

public:
    Nota();
    Nota(const std::string& numeStudent,
         const std::string& numeMaterie,
         int nota);

    std::string getNumeStudent() const;
    std::string getNumeMaterie() const;
    int getNota() const;

    void setNumeStudent(const std::string& numeNou);
    void setNumeMaterie(const std::string& numeNou);
    void setNota(int notaNoua);
};

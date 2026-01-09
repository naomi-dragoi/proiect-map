#pragma once
#include <string>

// Am creat clasa Student 
class Student {
private:
    int id;             // identificator unic al studentului
    std::string nume;   
// Studentul va avea un id si un nume

public:
    Student();

    Student(int id, const std::string& nume);

    // Getteri pentru citire
    int getId() const;
    std::string getNume() const;

    // Getteri pentru modificari
    void setId(int idNou);
    void setNume(const std::string& numeNou);
};

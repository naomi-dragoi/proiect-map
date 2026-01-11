#pragma once
#include <string>

class Materie {
private: 
        int id;
        std::string nume;

public: 
        Materie();
        Materie(int id, const std::string& nume);

        int getId() const;
        std::string getNume() const;

        void setId(int idNou);
        void setNume(const std::string& numeNou);

};

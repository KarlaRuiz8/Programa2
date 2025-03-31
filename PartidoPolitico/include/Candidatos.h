#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Candidato {
private:
    string nombre;
    vector<int> votos;
    int totalVotos;

public:
    Candidato(string nombre);
    void asignarVoto(int voto);
    int getTotalVotos() const;
    string getNombre() const;
};

#endif

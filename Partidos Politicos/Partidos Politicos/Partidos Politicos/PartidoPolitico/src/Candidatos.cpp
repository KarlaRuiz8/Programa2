#include "Candidato.h"

Candidato::Candidato(string nombre) {
    this->nombre = nombre;
    totalVotos = 0;
}

void Candidato::asignarVoto(int voto) {
    votos.push_back(voto);
    totalVotos += voto;
}

int Candidato::getTotalVotos() const {
    return totalVotos;
}

string Candidato::getNombre() const {
    return nombre;
}

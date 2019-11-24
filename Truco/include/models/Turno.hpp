#ifndef TURNO_H
#define TURNO_H

#include <map>
#include <vector>
#include <Carta.hpp>
#include <Jogador.hpp>

using namespace std;

class Turno {
private:
	map<Jogador, Carta> jogadas;
public:
	Turno();
	void registrarJogada(Jogador jogador, Carta carta);
	vector<Jogador> getVencedores();
};

#endif
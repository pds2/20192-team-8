#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <list>
#include "Jogador.hpp"
#include "Rodada.hpp"

using namespace std;

class Jogo {

	const int PONTOS_MAXIMOS = 12;

private:

	int pontos_jogador = 0;
	int pontos_bot = 0;

	std::list<Rodada> rodadas;
	Jogador jogador;
	Jogador bot;
	
public:
	
	Jogo(Jogador jogador,
	Jogador jogador);
	void controlaJogo();
};

#endif
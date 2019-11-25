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

	list<Rodada> rodadas;
	Jogador jogador;
	Jogador bot;
	
public:
	Jogo();
	Jogo(Jogador jogador,
	Jogador bot);
	int getPontosJogador();
	int getPontosBot();
};

#endif
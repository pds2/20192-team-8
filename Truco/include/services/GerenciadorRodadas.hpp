#ifndef GERENCIADOR_RODADAS_H
#define GERENCIADOR_RODADAS_H

#include <iostream>
#include <Rodada.hpp>
#include <Carta.hpp>
#include <Baralho.hpp>
#include <GerenciadorTurnos.hpp>
#include <AuxiliaresConsole.hpp>

using namespace std;
using namespace auxiliaresConsole;

class GerenciadorRodadas {
private:
	Rodada* rodada;
	Jogador* jogador;
	Jogador* bot;
	Baralho baralho;
	void distribuirCartas();
public:
	GerenciadorRodadas(Rodada* rodada, Jogador* jogador, Jogador* bot);
	void executarRodada();
};

#endif
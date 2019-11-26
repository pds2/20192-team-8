#ifndef GERENCIADOR_TURNOS_H
#define GERENCIADOR_TURNOS_H

#include <iostream>
#include <vector>
#include <Rodada.hpp>
#include <Carta.hpp>
#include <Baralho.hpp>
#include <Constants.hpp>
#include <AuxiliaresConsole.hpp>
#include <time.h>
#include <thread>

using namespace std;
using namespace auxiliaresConsole;

class GerenciadorTurnos {
private:
	Rodada* rodada;
	Jogador* jogador;
	Jogador* bot;
	Baralho baralho;
	void imprimirCartasDoJogador();
	void aumentarValorRodada();
	Carta fazerJogada();
	Carta fazerJogadaBot();
	void imprimirJogadas(Carta cartaJogador, Carta cartaBot);
	void imprimirVencedor();
public:
	GerenciadorTurnos(Rodada* rodada, Jogador* jogador, Jogador* bot, Baralho baralho);
	void executarTurno();
};

#endif
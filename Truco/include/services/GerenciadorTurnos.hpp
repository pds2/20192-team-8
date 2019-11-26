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
	map<int, string> nomeAumentoValor;
	void imprimirCartasDoJogador();
	void aguardarRespostaTrucoJogador();
	void aguardarRespostaTrucoBot();
	void aumentarValorRodada(Jogador jogadorTrucou);
	Carta aguardaJogadaUsuario();
	Carta fazerJogada();
	Carta fazerJogadaBot();
	void imprimirJogadas(Carta cartaJogador, Carta cartaBot);
	void imprimirVencedor();
public:
	GerenciadorTurnos(Rodada* rodada, Jogador* jogador, Jogador* bot, Baralho baralho);
	void executarTurno();
};

#endif
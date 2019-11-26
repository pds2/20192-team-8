#ifndef RODADA_H
#define RODADA_H

#include <map>
#include <vector>
#include <Turno.hpp>
#include <RodadaIncompleta.hpp>
#include <RodadaJaFinalizada.hpp>

using namespace std;

class Rodada {
private:
	vector<Turno> turnos;
	Jogador jogador;
	Jogador bot;
	int pontuacaoJogador;
	int pontuacaoBot;
	int valorRodada;
	Turno* getTurnoAtual();
	void setPontuacao(vector<Jogador> jogadores, int pontos);
	void pontuarTurnoAtual();
public:
	Rodada();
	Rodada(Jogador jogador1, Jogador jogador2);
	bool estaFinalizada();
	void fazJogada(Jogador jogador, Carta carta);
	void finalizarTurno();
	vector<Jogador> getVencedores();
	vector<Jogador> getVencedoresTurnoAtual();
};

#endif
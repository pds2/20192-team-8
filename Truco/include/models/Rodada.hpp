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
	Jogador jogador1;
	Jogador jogador2;
	int pontuacaoJogador1;
	int pontuacaoJogador2;
	int valorRodada;
	bool estaFinalizada();
	Turno* getTurnoAtual();
	void setPontuacao(vector<Jogador> jogadores, int pontos);
	void pontuarTurnoAtual();
public:
	Rodada();
	Rodada(vector<Jogador> jogadores);
	void fazJogada(Jogador jogador, Carta carta);
	void finalizarTurno();
	vector<Jogador> getVencedores();
};

#endif
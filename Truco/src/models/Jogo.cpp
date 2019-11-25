#include "Jogo.hpp"
#include "Rodada.hpp" 
#include "Jogador.hpp"
#include "Baralho.hpp"
#include <list>
#include <iostream>

using namespace std;

Jogo::Jogo(Jogador jogador,
	Jogador bot) {
	this->jogador = jogador;
	this->bot = bot;
	controlaJogo();
}

void Jogo::controlaJogo() {

	int nRodada = 1;

	cout << "Partida Iniciada";

	while (this->pontos_jogador < PONTOS_MAXIMOS && this->pontos_bot < PONTOS_MAXIMOS) {
		cout << "\n" << "--------------------------------------------------";
		cout << "\n" << "Rodada: " << nRodada;
		cout << "\n" << "Pontos do Jogador: " << this->pontos_jogador;
		cout << "\n" << "Pontos Bot: " << this->pontos_bot;
		Rodada rodada =  Rodada(jogador,bot);
		this->rodadas.push_back(rodada);
		cout << "\n" << "Fim da rodada " << nRodada << "!";
		cout << "\n" << "--------------------------------------------------";
		nRodada++;
	}

	if (this->pontos_jogadorHumano >= PONTOS_MAXIMOS) {
		cout << "\n" << "O Jogador foi o vencedor !!!" << endl;
	}
	else {
		cout << "\n" << "O Bot foi o vencedor !!!" << endl;
	}
}


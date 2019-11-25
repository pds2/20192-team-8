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

int Jogo::getPontosJogador() {
	return this->pontos_jogador;
}
int Jogo::getPontosBot() {
	return this->pontos_bot;
}

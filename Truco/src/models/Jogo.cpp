#include "Jogo.hpp"

using namespace std;

Jogo::Jogo() {
	this->jogador = Jogador();
	this->bot = Jogador();
}

Jogo::Jogo(Jogador jogador, Jogador bot) {
	this->jogador = jogador;
	this->bot = bot;
}

int Jogo::getPontosJogador() {
	return this->pontosJogador;
}
int Jogo::getPontosBot() {
	return this->pontosBot;
}

void Jogo::acrescentaPontosJogador(int pontos)
{
	this->pontosJogador += pontos;
}

Rodada* Jogo::getRodadaAtual() {
	return &(*(this->rodadas.end() - 1));
}

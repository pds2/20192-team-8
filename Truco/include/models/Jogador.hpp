#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "Carta.hpp"
#include <vector>
#include<string>

using namespace std;

class Jogador {
private:
	string nome;
	bool ehBot;
protected:
	vector<Carta> mao;
public:
	Jogador(string nome);
	Jogador(string nome, vector<Carta> cartas,bool ehBot);
	void setEhBot(bool ehBot);
	bool getEhBot();
	string  getNome();
	void setNome(string nome);
	void addCartaMao(Carta carta);
	void removeCartaMao(Carta carta);
	Carta getCartaMao(int posicao);
	std::vector<Carta> getMao();
	int getNumeroCartas();
	void limparCartasMao();
	bool operator <(const Jogador& outroJogador) const;
};

#endif

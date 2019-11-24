#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "Carta.hpp"
#include <vector>

using namespace std;

class Jogador {
private:
	string nome;
protected:
	vector<Carta> mao;
public:

	Jogador(string nome);
	Jogador(string nome, vector<Carta> cartas);
	string  getNome();
	void setNome(string nome);
	void addCartaMao(Carta carta);
	void removeCartaMao(Carta carta);
	void setMao(vector<Carta> cartas);
	Carta getCartaMao(int posicao);
	std::vector<Carta> getMao();
	int getNumeroCartas();
	void limparCartasMao();

};

#endif

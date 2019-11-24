#ifndef JOGADOR_H
#define JOGADOR_H

#include<string>

using namespace std;

class Jogador {
public:
	string nome;
	Jogador(string nome) {
		this->nome = nome;
	}
};

struct ComparadorJogador
{
	bool operator() (const Jogador& lhs, const Jogador& rhs) const
	{
		return lhs.nome < rhs.nome;
	}
};

#endif
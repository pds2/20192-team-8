#ifndef JOGADOR_H
#define JOGADOR_H

#include <Carta.hpp>
#include <vector>
#include<string>

using namespace std;

class Jogador {
private:
	string nome;
protected:
	vector<Carta> mao;
public:
	Jogador();
	Jogador(string nome);
	Jogador(string nome, vector<Carta> cartas);
	string  getNome();
	void setNome(string nome);
	void addCartaMao(Carta carta);
	void removeCartaMao(Carta carta);
	Carta getCartaMao(int posicao);
	std::vector<Carta> getMao();
	int getNumeroCartas();
	void limparCartasMao();
	bool operator <(const Jogador& outroJogador) const;
	bool operator >(const Jogador& outroJogador) const;
	bool operator ==(const Jogador& outroJogador) const;
};

#endif

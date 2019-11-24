#include <Turno.hpp>

using namespace std;

Turno::Turno() {
}

void Turno::registrarJogada(Jogador jogador, Carta carta)
{
	this->jogadas[jogador] = carta;
}

vector<Jogador> Turno::getVencedores()
{
	vector<Jogador> vencedores;
	int maiorValorCarta = 0;

	for (auto const& jogada : this->jogadas) {
		Jogador jogador = jogada.first;
		Carta carta = jogada.second;

		if (carta.getValor() > maiorValorCarta) {
			maiorValorCarta = carta.getValor();
			vencedores.clear();
			vencedores.push_back(jogador);
		}
		else if (carta.getValor() == maiorValorCarta) {
			vencedores.push_back(jogador);
		}
	}

	return vencedores;
}

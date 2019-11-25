#include <Turno.hpp>

Turno::Turno() {
	this->numeroJogadores = 2;
}

Turno::Turno(int numeroJogadores) {
	this->numeroJogadores = numeroJogadores;
}

void Turno::registrarJogada(Jogador jogador, Carta carta)
{
	this->jogadas[jogador] = carta;
}

vector<Jogador> Turno::getVencedores()
{
	if (this->jogadas.size() < this->numeroJogadores) {
		throw TurnoIncompleto();
	}

	vector<Jogador> vencedores;
	Carta maiorCarta;

	for (auto const& jogada : this->jogadas) {
		Jogador jogador = jogada.first;
		Carta carta = jogada.second;

		if (carta > maiorCarta) {
			maiorCarta = carta;
			vencedores.clear();
			vencedores.push_back(jogador);
		}
		else if (carta == maiorCarta) {
			vencedores.push_back(jogador);
		}
	}

	return vencedores;
}

#include <Rodada.hpp>

Rodada::Rodada()
{
	this->valorRodada = 2;
	this->turnos.push_back(Turno());
	this->pontuacaoJogador1 = 0;
	this->pontuacaoJogador2 = 0;
}

Rodada::Rodada(vector<Jogador> jogadores)
{
	this->valorRodada = 2;

	this->jogador1 = jogadores[0];
	this->jogador2 = jogadores[1];
	
	this->pontuacaoJogador1 = 0;
	this->pontuacaoJogador2 = 0;

	this->turnos.push_back(Turno());
}

bool Rodada::estaFinalizada() {
	if (pontuacaoJogador1 >= 3 || pontuacaoJogador2 >= 3) {
		return true;
	}
	return false;
}

Turno* Rodada::getTurnoAtual()
{
	Turno* turnoAtual = &(*(this->turnos.end() - 1));
	return turnoAtual;
}

void Rodada::setPontuacao(vector<Jogador> jogadores, int pontos) {
	for (Jogador jogador : jogadores) {
		if (jogador == jogador1) {
			this->pontuacaoJogador1 += pontos;
		}else if (jogador == jogador2) {
			this->pontuacaoJogador2 += pontos;
		}
	}
}

void Rodada::pontuarTurnoAtual()
{
	vector<Jogador> vencedoresTurnoAtual = this->getTurnoAtual()->getVencedores();
	int pontuacao = 1;
	if (this->turnos.size() == 1 || this->turnos.size() == 3) {
		pontuacao = 2;
	}

	this->setPontuacao(vencedoresTurnoAtual, pontuacao);
}

void Rodada::fazJogada(Jogador jogador, Carta carta)
{
	if (this->estaFinalizada()) {
		throw RodadaJaFinalizada();
	}
	this->getTurnoAtual()->registrarJogada(jogador, carta);
}

void Rodada::finalizarTurno()
{
	this->pontuarTurnoAtual();

	if (this->estaFinalizada()) {
		return;
	}

	this->turnos.push_back(Turno());
}

vector<Jogador> Rodada::getVencedores()
{
	if (!this->estaFinalizada()) {
		throw RodadaIncompleta();
	}

	vector<Jogador> vencedores;

	if (pontuacaoJogador1 >= pontuacaoJogador2) {
		vencedores.push_back(jogador1);
	}
	
	if (pontuacaoJogador1 <= pontuacaoJogador2) {
		vencedores.push_back(jogador2);
	}

	return vencedores;
}

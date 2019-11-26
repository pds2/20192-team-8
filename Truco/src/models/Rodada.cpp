#include <Rodada.hpp>

Rodada::Rodada()
{
	this->valorRodada = 2;
	this->turnos.push_back(Turno());
	this->pontuacaoJogador = 0;
	this->pontuacaoBot = 0;
}

Rodada::Rodada(Jogador jogador, Jogador bot)
{
	this->valorRodada = 2;

	this->jogador = jogador;
	this->bot = bot;
	
	this->pontuacaoJogador = 0;
	this->pontuacaoBot = 0;

	this->turnos.push_back(Turno());
}

bool Rodada::estaFinalizada() {
	if (pontuacaoJogador >= 3 || pontuacaoBot >= 3) {
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
		if (jogador == this->jogador) {
			this->pontuacaoJogador += pontos;
		}else if (jogador == bot) {
			this->pontuacaoBot += pontos;
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

	if (pontuacaoJogador >= pontuacaoBot) {
		vencedores.push_back(jogador);
	}
	
	if (pontuacaoJogador <= pontuacaoBot) {
		vencedores.push_back(bot);
	}

	return vencedores;
}

vector<Jogador> Rodada::getVencedoresTurnoAtual()
{
	return this->getTurnoAtual()->getVencedores();
}

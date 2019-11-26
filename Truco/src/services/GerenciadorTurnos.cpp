#include <GerenciadorTurnos.hpp>

GerenciadorTurnos::GerenciadorTurnos(Rodada* rodada, Jogador* jogador, Jogador* bot, Baralho baralho)
{
	this->rodada = rodada;
	this->jogador = jogador;
	this->bot = bot;
	this->baralho = baralho;
}

void GerenciadorTurnos::imprimirCartasDoJogador() {
	imprimirPausadamente("Suas cartas sao: \n");

	vector<Carta> cartasJogador = this->jogador->getMao();
	for (int i = 0; i < (int)cartasJogador.size(); i++) {
		Carta carta = cartasJogador[i];
		imprimirPausadamente(to_string(i + 1) + ":\t" + string(carta) + "\n");
	}
}

void GerenciadorTurnos::aumentarValorRodada() {
	imprimirTruco();
	srand(time(NULL));

	if ((rand() % 1) == 0) {
		limpaConsole();
		//TODO implementar desistencia
		imprimirPausadamente("A maquina recusou seu truco.");
	}
}

Carta GerenciadorTurnos::fazerJogada() {
	int indiceCarta;
	char aux;
	Carta cartaJogada;
	char confirmacao = '\0';

	Carta cartaVira = this->baralho.getCartaVira();

	vector<Carta> cartasJogador = this->jogador->getMao();

	do {
		limpaConsole();

		imprimirPausadamente("A carta vira eh: " + string(cartaVira) + "\n\n");

		this->imprimirCartasDoJogador();

		imprimirPausadamente("\nDigite a carta que voce quer jogar ou pressione T para aumentar a aposta: ");

		if (cin >> aux) {
			if (aux == 't' || aux == 'T') {
				this->aumentarValorRodada();
			}
			else {
				indiceCarta = (int)aux - 48;
				if (indiceCarta > 0 && indiceCarta <= (int)cartasJogador.size()) {
					cartaJogada = cartasJogador.at(indiceCarta - 1);

					limpaConsole();
					imprimirPausadamente("Voce selecionou a carta: " + string(cartaJogada) + "\nDigite S para confirmar: ");
					cin >> confirmacao;
				}
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (confirmacao != 'S' && confirmacao != 's');

	this->jogador->removeCartaMao(cartaJogada);
	this->rodada->fazJogada(*this->jogador, cartaJogada);

	return cartaJogada;
}

Carta GerenciadorTurnos::fazerJogadaBot() {
	vector<Carta> cartasBot = this->bot->getMao();
	
	srand(time(NULL));
	int indiceAleatorioCartaBot = rand() % cartasBot.size();

	Carta cartaJogadaBot = this->bot->getCartaMao(indiceAleatorioCartaBot);
	this->bot->removeCartaMao(cartaJogadaBot);

	imprimirCarregamentoComIcone("A maquina pondera sobre sua jogada... ");

	this->bot->removeCartaMao(cartaJogadaBot);
	this->rodada->fazJogada(*this->bot, cartaJogadaBot);

	return cartaJogadaBot;
}

void GerenciadorTurnos::imprimirJogadas(Carta cartaJogador, Carta cartaBot) {
	Carta cartaVira = this->baralho.getCartaVira();
	
	limpaConsole();

	imprimirPausadamente("A carta vira eh: " + string(cartaVira) + "\n\n\n");

	imprimirPausadamente("Voce jogou um " + string(cartaJogador) + "\n\n\n");

	this_thread::sleep_for(chrono::milliseconds(500));

	imprimirPausadamente("A maquina jogou um " + string(cartaBot) + "\n\n");
}

void GerenciadorTurnos::imprimirVencedor() {
	vector<Jogador> vencedores = this->rodada->getVencedoresTurnoAtual();

	if (vencedores.size() == 2) {
		imprimirPausadamente("Voces empataram!\n");
	}
	else if (vencedores.size() == 1) {
		if (vencedores.front() == *this->jogador) {
			imprimirPausadamente("Voce venceu este turno :)\n");
		}
		if (vencedores.front() == *this->bot) {
			imprimirPausadamente("A maquina venceu este turno :(\n");
		}
	}
}

void GerenciadorTurnos::executarTurno()
{
	Carta cartaJogada = this->fazerJogada();

	Carta cartaJogadaBot = this->fazerJogadaBot();

	this->imprimirJogadas(cartaJogada, cartaJogadaBot);

	imprimirCarregamentoVertical();

	this->imprimirVencedor();

	aguardarTecla();
}

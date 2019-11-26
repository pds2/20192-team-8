#include <GerenciadorTurnos.hpp>

GerenciadorTurnos::GerenciadorTurnos(Rodada* rodada, Jogador* jogador, Jogador* bot)
{
	this->rodada = rodada;
	this->jogador = jogador;
	this->bot = bot;
	this->baralho = Baralho();
}

void GerenciadorTurnos::distribuirCartas() {
	imprimirCarregamentoComIcone("Embaralhando... ");

	this->jogador->limparCartasMao();
	this->bot->limparCartasMao();

	this->baralho.defineManilhas();

	vector<Carta> cartasJogador = this->baralho.compraCartas(3);
	vector<Carta> cartasBot = this->baralho.compraCartas(3);

	this->jogador->setMao(cartasJogador);
	this->bot->setMao(cartasBot);
}

void GerenciadorTurnos::imprimirCartasDoJogador() {
	imprimirPausadamente("Suas cartas sao: \n");

	vector<Carta> cartasJogador = this->jogador->getMao();
	for (size_t i = 0; i < cartasJogador.size(); i++) {
		Carta carta = cartasJogador[i];
		imprimirPausadamente(to_string(i + 1) + ":\t" + string(carta) + "\n");
	}
}

Carta GerenciadorTurnos::fazerJogada() {
	int indiceCarta;
	Carta cartaJogada;
	char confirmacao = '\0';

	Carta cartaVira = this->baralho.getCartaVira();

	vector<Carta> cartasJogador = this->jogador->getMao();

	do {
		limpaConsole();

		imprimirPausadamente("A carta vira eh: " + string(cartaVira) + "\n\n");

		this->imprimirCartasDoJogador();

		imprimirPausadamente("\nDigite a carta que voce quer jogar: ");

		if (cin >> indiceCarta && indiceCarta > 0 && indiceCarta <= cartasJogador.size()) {
			cartaJogada = cartasJogador.at(indiceCarta - 1);

			limpaConsole();
			imprimirPausadamente("Voce selecionou a carta: " + string(cartaJogada) + "\nDigite S para confirmar: ");
			cin >> confirmacao;
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
	limpaConsole();
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

Jogador GerenciadorTurnos::executarTurno()
{
	this->distribuirCartas();

	Carta cartaJogada = this->fazerJogada();

	Carta cartaJogadaBot = this->fazerJogadaBot();

	this->imprimirJogadas(cartaJogada, cartaJogadaBot);

	imprimirCarregamentoVertical();

	this->imprimirVencedor();

	aguardarTecla();

	return *this->jogador;
}

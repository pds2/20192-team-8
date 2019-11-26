#include <GerenciadorTurnos.hpp>

GerenciadorTurnos::GerenciadorTurnos(Rodada* rodada, Jogador* jogador, Jogador* bot, Baralho baralho)
{
	this->rodada = rodada;
	this->jogador = jogador;
	this->bot = bot;
	this->baralho = baralho;
	nomeAumentoValor = {
		{2, "truco"},
		{4, "seis"},
		{6, "nove"},
		{9, "doze"},
	};
}

void GerenciadorTurnos::imprimirCartasDoJogador() {
	imprimirPausadamente("Suas cartas sao: \n");

	vector<Carta> cartasJogador = this->jogador->getMao();
	for (int i = 0; i < (int)cartasJogador.size(); i++) {
		Carta carta = cartasJogador[i];
		imprimirPausadamente(to_string(i + 1) + ":\t" + string(carta) + "\n");
	}
}

void GerenciadorTurnos::aguardarRespostaTrucoJogador(){
	limpaConsole();
	char opcaoJogador;

	cout << "Digite S para aceitar, F para fugir ou T para pedir " + this->nomeAumentoValor.at(this->rodada->getValor());
	cin >> opcaoJogador;

	if(opcaoJogador == 'S' || opcaoJogador == 's'){
		return;
	} else if(opcaoJogador == 'F' || opcaoJogador == 'f'){
		//TODO implementar desistencia
		return;
	} else if(opcaoJogador == 'T' || opcaoJogador == 't'){
		this->aumentarValorRodada(*this->jogador);
		return;
	}
}

void GerenciadorTurnos::aguardarRespostaTrucoBot(){
	srand(time(NULL));

	int respostaBot = this->rodada->getValor() == 12 ? rand() % 2 : rand() % 3;
	limpaConsole();

	switch(respostaBot){
		case 0:
			//TODO implementar desistencia
			imprimirPausadamente("A maquina recusou seu truco.");
			this_thread::sleep_for(chrono::milliseconds(1000));
			break;
		case 1:
			imprimirPausadamente("A maquina aceitou seu truco.");
			this_thread::sleep_for(chrono::milliseconds(1000));
			break;
		case 2:
			this->aumentarValorRodada(*this->bot);
			break;
	}
}

void GerenciadorTurnos::aumentarValorRodada(Jogador jogadorTrucou) {
	switch(this->rodada->getValor()){
		case 2:
			imprimirTruco();
			break;
		case 4:
			imprimirSeis();
			break;
		case 6:
			imprimirNove();
			break;
		case 9:
			imprimirDoze();
			break;
	}

	this->rodada->aumentarValor(*this->jogador);
	
	if(jogadorTrucou == *this->jogador){
		this->aguardarRespostaTrucoBot();
	}else {
		this->aguardarRespostaTrucoJogador();
	}
}

Carta GerenciadorTurnos::aguardaJogadaUsuario()
{
	char confirmacao = '\0';
	char aux;
	int indiceCarta;
	Carta cartaJogada = Carta();

	vector<Carta> cartasJogador = this->jogador->getMao();

	string comandoAumentoValor = " ou pressione T para pedir " + this->nomeAumentoValor.at(this->rodada->getValor());
	string comandoJogada = "\nDigite a carta que voce quer jogar";

	if(this->rodada->getJogadorTrucou() != *this->jogador){
		comandoJogada += comandoAumentoValor;
	}

	imprimirPausadamente(comandoJogada + ": ");

	if (cin >> aux) {
		if (aux == 't' || aux == 'T') {
			this->aumentarValorRodada(*this->jogador);
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

	return cartaJogada;
}

Carta GerenciadorTurnos::fazerJogada() {
	Carta cartaJogada;
	char confirmacao = '\0';

	Carta cartaVira = this->baralho.getCartaVira();

	vector<Carta> cartasJogador = this->jogador->getMao();

	do {
		limpaConsole();

		imprimirPausadamente("A carta vira eh: " + string(cartaVira) + "\n\n");

		this->imprimirCartasDoJogador();

		cartaJogada = this->aguardaJogadaUsuario();
		
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

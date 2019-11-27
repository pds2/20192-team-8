#include <GerenciadorRodadas.hpp>

GerenciadorRodadas::GerenciadorRodadas(Rodada* rodada, Jogador* jogador, Jogador* bot) {
	this->rodada = rodada;
	this->jogador = jogador;
	this->bot = bot;
	this->baralho = Baralho();
}

void GerenciadorRodadas::distribuirCartas() {
	imprimirCarregamentoComIcone("Embaralhando... ");

	this->jogador->limparCartasMao();
	this->bot->limparCartasMao();

	this->baralho.defineManilhas();

	vector<Carta> cartasJogador = this->baralho.compraCartas(3);
	vector<Carta> cartasBot = this->baralho.compraCartas(3);

	this->jogador->setMao(cartasJogador);
	this->bot->setMao(cartasBot);
}

void GerenciadorRodadas::imprimirVencedor(){
	limpaConsole();

	if(this->rodada->getVencedores().size() > 1){
		imprimirPausadamente("A rodada terminou empatada!");
	} else if(this->rodada->getVencedores().at(0) == *this->jogador){
		imprimirPausadamente("Parabéns, você venceu a rodada! :)");
	} else if(this->rodada->getVencedores().at(0) == *this->bot){
		imprimirPausadamente("Aff! A maquina venceu a rodada! :(");
	}
	cout << "\n\n";

	aguardarEnter();
}

void GerenciadorRodadas::executarRodada() {
	this->distribuirCartas();

	GerenciadorTurnos gerenciadorTurnos = GerenciadorTurnos(this->rodada, this->jogador, this-> bot, this->baralho);
	
	while (!this->rodada->estaFinalizada()) {
		gerenciadorTurnos.executarTurno();
	}

	this->imprimirVencedor();
}
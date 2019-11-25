#include <Baralho.hpp>

Baralho::Baralho()
{
	this->resetarBaralho();
}

void Baralho::resetarBaralho()
{
	this->cartas.clear();
	this->simboloManilha = '\0';
	for (int i = 0; i < 10; i++) {
		this->cartas.push_back(Carta(OUROS, simbolosBaralho[i]));
		this->cartas.push_back(Carta(ESPADAS, simbolosBaralho[i]));
		this->cartas.push_back(Carta(COPAS, simbolosBaralho[i]));
		this->cartas.push_back(Carta(PAUS, simbolosBaralho[i]));
	}
}

Carta Baralho::compraCarta()
{
	srand(time(NULL));
	int indiceAleatorio = rand() % this->cartas.size();
	
	Carta carta = this->cartas[indiceAleatorio];
	this->cartas.erase(cartas.begin() + indiceAleatorio);

	return carta;
}

vector<Carta> Baralho::compraCartas(int qtd)
{
	vector<Carta> cartas;
	
	for (int i = 0; i < qtd; i++) {
		cartas.push_back(this->compraCarta());
	}

	return cartas;
}

void Baralho::defineManilhas()
{
	Carta cartaVira = this->compraCarta();
	this->simboloManilha = mapProximaCarta.find(cartaVira.getSimbolo())->second;

	for (int i = 0; i < this->cartas.size(); i++) {
		bool ehManilha = this->cartas[i].getSimbolo() == this->simboloManilha;
		this->cartas[i].setManilha(ehManilha);
	}
}

char Baralho::getSimboloManilha() {
	return this->simboloManilha;
}

vector<Carta> Baralho::getCartas() {
	return this->cartas;
}

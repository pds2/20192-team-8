#include "Carta.hpp"
using namespace std;

Carta::Carta() {
	this->simbolo = 'N';
	this->valor = -1;
	this->manilha = false;
}

Carta::Carta(string naipe, char simbolo) {
	this->naipe = naipe;
	this->simbolo = simbolo;
	this->manilha = false;
	setValor();
	inicializaMaps();
}

void Carta::inicializaMaps() {
	inicializaMapCartas();
	inicializaMapNaipes();
}

void Carta::inicializaMapCartas() {
	this->VALOR_CARTAS.insert(pair<char, int>('4', 1));
	this->VALOR_CARTAS.insert(pair<char, int>('5', 2));
	this->VALOR_CARTAS.insert(pair<char, int>('6', 3));
	this->VALOR_CARTAS.insert(pair<char, int>('7', 4));
	this->VALOR_CARTAS.insert(pair<char, int>('Q', 5));
	this->VALOR_CARTAS.insert(pair<char, int>('J', 6));
	this->VALOR_CARTAS.insert(pair<char, int>('K', 7));
	this->VALOR_CARTAS.insert(pair<char, int>('A', 8));
	this->VALOR_CARTAS.insert(pair<char, int>('2', 9));
	this->VALOR_CARTAS.insert(pair<char, int>('3', 10));
}

void Carta::inicializaMapNaipes() {
	this->VALOR_NIPES.insert(pair<string, int>(OUROS, 11));
	this->VALOR_NIPES.insert(pair<string, int>(ESPADAS, 12));
	this->VALOR_NIPES.insert(pair<string, int>(COPAS, 13));
	this->VALOR_NIPES.insert(pair<string, int>(PAUS, 14));

}

int Carta::getValor() {
	return this->valor;
}

void Carta::setValor() {
	if(!this->manilha)
	this->valor = this->VALOR_CARTAS[this->simbolo];
}

string Carta::getNaipe() {
	return this->naipe;
}

void Carta::setNaipe(string naipe) {
	this->naipe = naipe;
}
bool Carta::getManilha() {
	return this->manilha;
}
void Carta::setManilha(bool manilha) {
	this->valor = (manilha == true) ? VALOR_NIPES[this->naipe] : VALOR_CARTAS[this->simbolo];
	this->manilha = manilha;
}
char Carta::getSimbolo() {
	return this->simbolo;
}
void Carta::setSimbolo(char simbolo) {
	this->simbolo = simbolo;
}
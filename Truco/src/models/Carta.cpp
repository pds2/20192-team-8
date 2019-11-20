#include<iostream>
#include<map>
#include "../include/models/Carta.hpp"
using namespace std;

Carta::Carta() {

}

Carta::Carta(string nipe, char simbolo) {
	this->nipe = nipe;
	this->simbolo = simbolo;
	this->manilha = false;
	setValor();
	inicializaMaps();
}

void Carta::inicializaMaps() {
	inicializaMapCartas();
	inicializaMapNipes();
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

void Carta::inicializaMapNipes() {
	this->VALOR_NIPES.insert(pair<string, int>("OURO", 11));
	this->VALOR_NIPES.insert(pair<string, int>("ESPADAS", 12));
	this->VALOR_NIPES.insert(pair<string, int>("COPAS", 13));
	this->VALOR_NIPES.insert(pair<string, int>("PAUS", 14));

}

int Carta::getValor() {
	return this->valor;
}

void Carta::setValor() {
	if(!this->manilha)
	this->valor = this->VALOR_CARTAS[this->simbolo];
}

string Carta::getNipe() {
	return this->nipe;
}

void Carta::setNipe(string nipe) {
	this->nipe = nipe;
}
bool Carta::getManilha() {
	return this->manilha;
}
void Carta::setManilha(bool manilha) {
	this->valor = (manilha == true) ? VALOR_NIPES[this->nipe] : VALOR_CARTAS[this->simbolo];
	this->manilha = manilha;
}
char Carta::getSimbolo() {
	return this->simbolo;
}
void Carta::setSimbolo(char simbolo) {
	this->simbolo = simbolo;
}
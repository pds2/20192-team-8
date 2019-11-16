#include<iostream>
#include "models/Carta.hpp"
using namespace std;

Carta::Carta() {

}

Carta::Carta(int valor, string nipe, char simbolo) {
	this->valor = valor;
	this->nipe = nipe;
	this->simbolo = simbolo;
	this->manilha = false;
}

int getValor() {
	return this->valor;
}

void setValor(int valor) {
	this->valor = valor;

}

string getNipe() {
	return this.nipe;
}

void setNipe(string nipe) {
	this->nipe = nipe;
}
bool getManilha() {
	return this.manilha;
}
void setManilha(bool manilha) {
	if (manilha == true) {
		this->manilha = manilha;
		switch (this->nipe) {
		case "COPAS":
			this->valor = this.COPAS;
			break;
		case "OUROS" :
			this->valor = this.OUROS;
			break;
		case "ESPADAS":
			this->valor = this.ESPADAS;
			break;
		case "PAUS":
			this->valor = this.PAUS;
			break;
		default:
			printf("Nipe invalido\n");
			break;
		}
	}else {
		
	}
	
}
char getSimbolo() {
	return this->simbolo;
}
void setSimbolo(char simbolo) {
	this->simbolo = simbolo;
}
#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string>

using namespace std;

class Carta {
private:
	int valor;
	string nipe;
	bool manilha;
	char simbolo;
public:

	const int COPAS = 13;
	const int OUROS = 11;
	const int ESPADAS = 12;
	const int PAUS = 14;

	Carta();
	Carta(int valor, string nipe, char simbolo);
	int getValor();
	void setValor(int valor);
	string getNipe();
	void setNipe(string nipe);
	bool getManilha();
	void setManilha(bool manilha);
	char getSimbolo();
	void setSimbolo(char simbolo);


};

#endif
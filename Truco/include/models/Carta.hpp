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
	map <string, int> VALOR_NIPES;
	map <char, int> VALOR_CARTAS;
public:

	Carta();
	Carta(string nipe, char simbolo);
	void inicializaMaps();
	void inicializaMapNipes();
	void inicializaMapCartas();
	int getValor();
	void setValor();
	string getNipe();
	void setNipe(string nipe);
	bool getManilha();
	void setManilha(bool manilha);
	char getSimbolo();
	void setSimbolo(char simbolo);


};

#endif
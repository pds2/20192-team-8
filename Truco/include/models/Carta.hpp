#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <map>
#include <Constants.hpp>

using namespace std;

class Carta {
private:
	int valor;
	string naipe;
	bool manilha;
	char simbolo;
	map <string, int> VALOR_NIPES;
	map <char, int> VALOR_CARTAS;
public:
	Carta();
	Carta(string nipe, char simbolo);
	void inicializaMaps();
	void inicializaMapNaipes();
	void inicializaMapCartas();
	int getValor();
	void setValor();
	string getNaipe();
	void setNaipe(string nipe);
	bool getManilha();
	void setManilha(bool manilha);
	char getSimbolo();
	void setSimbolo(char simbolo);


};

#endif
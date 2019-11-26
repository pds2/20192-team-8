#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include <Carta.hpp>
#include <Constants.hpp>
#include <time.h>

using namespace std;

class Baralho {
private:
	vector <Carta> cartas;
	Carta cartaVira;
	char simboloManilha;
public:
	Baralho();
	void resetarBaralho();
	Carta compraCarta();
	vector<Carta> compraCartas(int qtd);
	void defineManilhas();
	Carta getCartaVira();
	char getSimboloManilha();
	vector<Carta> getCartas();
};

const char simbolosBaralho[10] = { '4', '5', '6', '7', 'Q', 'J', 'K', 'A', '2', '3' };

const map<char, char> mapProximaCarta = {
	{'4', '5'},
	{'5', '6'},
	{'6', '7'},
	{'7', 'Q'},
	{'Q', 'J'},
	{'J', 'K'},
	{'K', 'A'},
	{'A', '2'},
	{'2', '3'},
	{'3', '4'}
};

#endif
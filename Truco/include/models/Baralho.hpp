#ifndef BARALHO_H
#define BARALHO_H

#include <vector>
#include <Carta.hpp>
#include <Constants.hpp>
#include <time.h>

using namespace std;

class Baralho {
private:

	/**
	 * @brief vector de cartas do baralho
	 *
	 */
	vector <Carta> cartas;
	
  Carta cartaVira;
  
	/**
	 * @brief Define o símbolo das manilhas do truco paulista
	 *
	 */
	char simboloManilha;
public:

	/**
	 * @brief Construtor da classe Baralho
	 *
	 */
	Baralho();

	/**
	 * @brief Reseta o baralho  do jogo
	 *
	 */
	void resetarBaralho();

	/**
	 * @brief Define a carta que o jogador irá retirar do baralho
	 *
	 */
	Carta compraCarta();

	/**
	 * @brief Define quantas cartas o jogador irá retirar do trabalho
	 *
	 */
	vector<Carta> compraCartas(int qtd);

	/**
	 * @brief Define a carta vira do truco paulista
	 *
	 */
	void defineManilhas();

	Carta getCartaVira();
	/**
	 * @brief Retorna o símbolo da manilha do jogo
	 * @return char - simbolo da manilha
  */
	char getSimboloManilha();

	/**
	 * @brief Retorna as cartas do jogador
	 * @return vector<Carta> - vetor de cartas do jogador
	 */
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
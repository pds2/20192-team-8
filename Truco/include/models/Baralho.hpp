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

	/**
	 * @brief Define o s�mbolo da carta "vira" do truco paulista ( que define quais s�o as manilhas do truco paulista)
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
	 * @brief Define a carta que o jogador ir� retirar do baralho
	 *
	 */
	Carta compraCarta();

	/**
	 * @brief Define quantas cartas o jogador ir� retirar do trabalho
	 *
	 */
	vector<Carta> compraCartas(int qtd);

	/**
	 * @brief Define a carta vira do truco paulista
	 *
	 */
	void defineManilhas();

	/**
	 * @brief Retorna o s�mbolo da manilha do jogo
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
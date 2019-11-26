#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <map>
#include <Constants.hpp>

using namespace std;

class Carta {
private:

	/**
	 * @brief valor da carta
	 *
	 */
	int valor;
	/**
	 * @brief naipe da carta
	 *
	 */
	string naipe;

	/**
	 * @brief Bool que define se carta é ou não manilha
	 *
	 */
	bool manilha;
	/**
	 * @brief Símbolo da carta
	 *
	 */
	char simbolo;

	/**
	 * @brief Map de Valor dos Naipes
	 *
	 */
	map <string, int> VALOR_NIPES;
	/**
	 * @brief Map de Valor das cartas
	 *
	 */
	map <char, int> VALOR_CARTAS;
public:

	/**
	 * @brief Construtor Default da classe carta
	 *
	 */
	Carta();

	/**
	 * @brief Construtor da classe carta
	 *
	 * @param nipe
	 * @param simbolo
	 */
	Carta(string nipe, char simbolo);

	/**
	 * @brief Realiza as chamadas das funções que inicializam os Maps
	 *
	 */
	void inicializaMaps();
	/**
	 * @brief Inicializa o Map de Nipes
	 *
	 */
	void inicializaMapNaipes();

	/**
	 * @brief Inicializa o Map de Cartas
	 *
	 */
	void inicializaMapCartas();

	/**
	 * @brief Retorna o valor da carta
	 *
	 * @return int
	 */
	int getValor();

	/**
	 * @brief Define o valor da carta
	 *
	 */
	void setValor();
	/**
	 * @brief Retorna o nipe da carta
	 *
	 * @return string
	 */
	string getNaipe();

	/**
	 * @brief Define o nipe da carta
	 *
	 * @param nipe - string que define o naipe da carta 
	 */
	void setNaipe(string naipe);
	/**
	 * @brief Retorna o bool manilha que diz se a carta é manilha ou não
	 *
	 * @return bool
	 */
	bool getManilha();

	/**
	 * @brief Define se a carta é manilha 
	 *
	 * @param manilha - bool que define a manilha da carta
	 */
	void setManilha(bool manilha);
	/**
	 * @brief Retorna o símbolo da carta
	 *
	 * @return char
	 */
	char getSimbolo();

	/**
	 * @brief Define o símbolo da carta 
	 *
	 * @param simbolo - char que define o símbolo da carta
	 */
	void setSimbolo(char simbolo);


	/**
	 * @brief Sobrescrita do operador <
	 *
	 * @param outraCarta - ponteiro de Carta que envia a carta a ser comparada
	 */
	bool operator<(const Carta& outraCarta) const;
	/**
	 * @brief Sobrescrita do operador >
	 *
	 * @param outraCarta - ponteiro de Carta que envia a carta a ser comparada
	 */
	bool operator>(const Carta& outraCarta) const;
	/**
	 * @brief Sobrescrita do operador ==
	 *
	 * @param outraCarta - ponteiro de Carta que envia a carta a ser comparada
	 */
	bool operator==(const Carta& outraCarta) const;
	/**
	 * @brief Sobrescrita do operador >=
	 *
	 * @param outraCarta - ponteiro de Carta que envia a carta a ser comparada
	 */
	bool operator>=(const Carta& outraCarta) const;
	/**
	 * @brief Sobrescrita do operador <=
	 *
	 * @param outraCarta - ponteiro de Carta que envia a carta a ser comparada
	 */
	bool operator<=(const Carta& outraCarta) const;
	operator std::string() const;
};

#endif
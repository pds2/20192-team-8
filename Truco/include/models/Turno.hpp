#ifndef TURNO_H
#define TURNO_H

#include <map>
#include <vector>
#include <Carta.hpp>
#include <Jogador.hpp>
#include <TurnoIncompleto.hpp>

using namespace std;

class Turno {
private:
	/**
	 * @brief map de jogadas 
	 */
	map<Jogador, Carta> jogadas;

	/**
	 * @brief variável que armazena o número de jogadores 
	 */
	int numeroJogadores;
public:
	/**
	 * @brief Construtor Default da classe turno 
	 */
	Turno();

	/**
	 * @brief Construtor da classe turno
	 * @param numeroJogadores 
	 */
	Turno(int numeroJogadores);

	/**
	 * @brief Função que recebe como parâmetro a carta e o jogador e registra sua jogada
	 * @param jogador - jogador que realizou a jogada
	  * @param carta - carta jogada
	 */
	void registrarJogada(Jogador jogador, Carta carta);

	/**
	 * @brief Retorna os vencedores do turno
	 * @return vector<Jogador>
	 */
	vector<Jogador> getVencedores();
};

#endif
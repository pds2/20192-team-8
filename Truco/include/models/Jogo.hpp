#ifndef JOGO_H
#define JOGO_H

#include <vector>
#include "Jogador.hpp"
#include "Rodada.hpp"

using namespace std;

class Jogo {
	/**
	 * @brief N�mero de pontos necessarios para ganhar a partida
	 *
	 */
	const int PONTOS_MAXIMOS = 12;

private:

	/**
	 * @brief Pontos do Jogador Humano
	 *
	 */
	int pontosJogador = 0;

	/**
	 * @brief Pontos do Jogador Bot
	 *
	 */
	int pontosBot = 0;

	/**
	 * @brief Lista com as Rodadas que comp�em a partida
	 *
	 */
	vector<Rodada> rodadas;

	/**
	* @brief Objeto Jogador participante da partida
	*
	*/
	Jogador jogador;

	/**
	* @brief Objeto Jogador Bot participante da partida
	*
	*/
	Jogador bot;

public:
	/**
	 * @brief Construtor Default da Partida
	 *
	 */
	Jogo();

	/**
	 * @brief Construtor da Partida
	 *
	 * @param jogador - Jogador Humano participante da Partida
	   @param bot - Jogador Bot participante da partida
	 */
	Jogo(Jogador jogador, Jogador bot);

	/**
	 * @brief Retorna os pontos do Jogador
	 *
	 * @return int
	 */
	int getPontosJogador();

	/**
	 * @brief Retorna os pontos do Bot
	 *
	 * @return int
	 */
	int getPontosBot();

	/**
	 * @brief Acrescenta n pontos para o jogador
	 *
	 * @param pontos - Pontos a serem adicionados
	 */
	void acrescentaPontosJogador(int pontos);

	/**
	 * @brief Retorna a Rodada atual
	 *
	 * @return Rodada
	 */
	Rodada* getRodadaAtual();
};

#endif
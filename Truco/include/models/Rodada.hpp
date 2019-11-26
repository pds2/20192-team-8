#ifndef RODADA_H
#define RODADA_H

#include <map>
#include <vector>
#include <Turno.hpp>
#include <RodadaIncompleta.hpp>
#include <RodadaJaFinalizada.hpp>

using namespace std;

class Rodada {
private:

	/**
	 * @brief vector de turnos da Rodada
	 */
	vector<Turno> turnos;
	/**
	 * @brief Jogador da Rodada
	 */
	Jogador jogador;

	/**
	 * @brief Bot da Rodada
	 */
	Jogador bot;


	/**
	 * @brief pontua��o do jogador 
	 */
	int pontuacaoJogador;


	/**
	 * @brief pontua��o do bot 
	 */
	int pontuacaoBot;

	/**
	 * @brief valor da rodada 
	 */
	int valorRodada;


	/**
	 * @brief Fun��o que verifica o fim da rodada 
	 * @return bool 
	*/
	bool estaFinalizada();


	/**
	 * @brief Retorna o turno atual
	 * @return int - turno atual
	 */
	Turno* getTurnoAtual();
	
	/**
	 * @brief Recebe os jogadores a serem pontuados e os pontos para atribuir a eles
	 * @param jogadores - jogadores do turno
	 * @param pontos 
	 */
	void setPontuacao(vector<Jogador> jogadores, int pontos);

	/**
	 * @brief Aumenta a pontua��o dos vencedores do turno
	 */
	void pontuarTurnoAtual();
public:

	/**
	 * @brief Construtor Default da classe Rodada
	 */
	Rodada();
	/**
	 * @brief Construtor da classe rodada
	 * @param jogador1 
	 * @param jogador2
	 */
	Rodada(Jogador jogador1, Jogador jogador2);
	/**
	 * @brief Realiza a jogada 
	 * @param jogador
	 * @param carta
	 */
	void fazJogada(Jogador jogador, Carta carta);
	
	/**
	 * @brief Finaliza o turno 
	 */
	void finalizarTurno();

	/**
	 * @brief Retorna o(s) vencedor(es) do turno
	 * @return vector<Jogador> - vencedores do turno
	 */
	vector<Jogador> getVencedores();
};

#endif
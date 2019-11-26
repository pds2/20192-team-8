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
	 * @brief Jogador que fez o ultimo aumento de valor
	 */
	Jogador jogadorTrucou;


	/**
	 * @brief pontuação do jogador 
	 */
	int pontuacaoJogador;


	/**
	 * @brief pontuação do bot 
	 */
	int pontuacaoBot;

	/**
	 * @brief valor da rodada 
	 */
	int valorRodada;


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
	 * @brief Aumenta a pontuação dos vencedores do turno
	 */
	void pontuarTurnoAtual();
public:

	/**
	 * @brief Construtor Default da classe Rodada
	 */
	Rodada();
	/**
	 * @brief Construtor da classe rodada
	 * @param jogador
	 * @param bot
	 */
	Rodada(Jogador jogador, Jogador bot);

	/**
	 * @brief Função que verifica o fim da rodada
	 * @return bool
	*/
	bool estaFinalizada();

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
	 * @brief Aumenta o valor da Rodada
	 */
	void aumentarValor(Jogador jogadorTrucou);

	/**
	 * @brief Retorna o(s) vencedor(es) do turno
	 * @return vector<Jogador> - vencedores do turno
	 */
	vector<Jogador> getVencedores();

	/**
	 * @brief Retorna o valor da Rodada
	 * @return int - valor da Rodada
	 */
	int getValor();
	
	/**
	 * @brief Retorna o ultimo jogador que aumentou o valor
	 * @return Jogador - ultimo jogador que aumentou o valor
	 */
	Jogador getJogadorTrucou();

	vector<Jogador> getVencedoresTurnoAtual();
};

const map<char, char> mapProximoValor = {
	{2, 4},
	{4, 6},
	{6, 8},
	{8, 10},
	{10, 12},
};

#endif
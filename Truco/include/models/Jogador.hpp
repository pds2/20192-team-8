#ifndef JOGADOR_H
#define JOGADOR_H

#include <Carta.hpp>
#include <vector>
#include<string>

using namespace std;

class Jogador {
private:
	/**
	 * @brief Nome do jogador
	 *
	 */
	string nome;
	/**
	 * @brief Bool que controla se jogador � bot
	 *
	 */
	bool ehBot;
protected:
	/**
	 * @brief Vector de cartas do jogador
	 *
	 */
	vector<Carta> mao;
public:
	/**
	 * @brief Construtor Jogador Default
	 *
	 */
	Jogador();

	/**
	 * @brief Construtor da classe Jogador
	 *
	 * @param nome
	 */
	Jogador(string nome);

	/**
	 * @brief Construtor da classe Jogador
	 *
	 * @param nome
	 * @param cartas - vector de cartas do jogador
	 * @param ehBot - bool que define se jogador � bot
	 */
	Jogador(string nome, vector<Carta> cartas,bool ehBot);

	/**
	 * @brief Define o bool ehBot do jogador
	 *
	 * @param ehBot - define se jogador � ou n�o bot
	 */
	void setEhBot(bool ehBot);

	/**
	* @brief Retorna se o jogador � bot
	*
	* @return bool
	*/
	bool getEhBot();
	/**
	* @brief Retorna nome do jogador
	*
	* @return string
	*/
	string  getNome();

	/**
	* @brief Define o nome do jogador
	*
	* @param nome
	*/
	void setNome(string nome);

	/**
	* @brief Adiciona carta ao vector de cartas "m�o" do jogador 
	*
	* @param carta - carta a ser adicionada
	*/
	void addCartaMao(Carta carta);
	/**
	* @brief Remove carta do vector de cartas "mao" do jogador
	*
	* @param carta - carta a ser removida
	*/
	void removeCartaMao(Carta carta);

	/**
	* @brief Retorna carta de determinada posi��o da m�o do jogador
	*
	* @return Carta - Carta na posi��o indicada
	*/
	Carta getCartaMao(int posicao);
	/**
	* @brief Retorna o vetor de cartas "mao" do jogador
	*
	* @return std::vector<Carta> - Vector de cartas do jogador
	*/
	std::vector<Carta> getMao();

	/**
	* @brief Retorna o n�mero de cartas da "mao" do jogador
	*
	* @return int - numero de cartas da m�o do jogador
	*/
	int getNumeroCartas();

	/**
	* @brief Limpa o vector de cartas do jogador
	*
	*/
	void limparCartasMao();
	/**
	 * @brief Sobrescrita do operador <
	 *
	 * @param outroJogador - ponteiro de Jogador que envia o jogador a ser comparado
	 */
	bool operator <(const Jogador& outroJogador) const;
	/**
	 * @brief Sobrescrita do operador >
	 *
	 * @param outroJogador - ponteiro de Jogador que envia o jogador a ser comparado
	 */
	bool operator >(const Jogador& outroJogador) const;
	/**
	 * @brief Sobrescrita do operador ==
	 *
	 * @param outroJogador - ponteiro de Jogador que envia o jogador a ser comparado
	 */
	bool operator ==(const Jogador& outroJogador) const;
};

#endif

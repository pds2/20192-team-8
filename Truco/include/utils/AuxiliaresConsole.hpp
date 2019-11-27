#ifndef AUXILIARES_CONSOLE_H
#define AUXILIARES_CONSOLE_H

#include <iostream>
#include <thread>
#include <cstring>

using namespace std;

namespace auxiliaresConsole {
	void limpaConsole();

	void imprimirPausadamente(string mensagem, int velocidade = 20);

	void imprimirCentralizadoPausadamente(string s);

	void imprimirCentralizado(string s);

	void imprimirCarregamentoComIcone(string mensagem, double segundos = 2);

	void imprimirCarregamentoVertical(int velocidade = 700);

	void aguardarEnter();

	void imprimirTruco(int velocidade = 400);

	void imprimirSeis(int velocidade = 400);

	void imprimirNove(int velocidade = 400);

	void imprimirDoze(int velocidade = 400);
}

#endif
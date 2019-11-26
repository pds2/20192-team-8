#ifndef AUXILIARES_CONSOLE_H
#define AUXILIARES_CONSOLE_H

#include <iostream>
#include <thread>

using namespace std;

namespace auxiliaresConsole {
	static void limpaConsole() {
		cout << "\033[2J\033[1;1H";
	}

	static void imprimirPausadamente(string mensagem, int velocidade = 20) {
		for (char const& c : mensagem) {
			cout << c;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
		}
	}

	static void imprimirCentralizadoPausadamente(string s) {
		limpaConsole();

		const char* mensagem = s.c_str();

		int l = strlen(mensagem);
		int pos = (int)((3000 - l) / 2);
		for (int i = 0; i < pos; i++) {
			cout << " ";
		}

		imprimirPausadamente(mensagem, 60);
	}

	static void imprimirCentralizado(string s) {
		limpaConsole();

		const char* mensagem = s.c_str();

		int l = strlen(mensagem);
		int pos = (int)((3000 - l) / 2);
		for (int i = 0; i < pos; i++)
			cout << " ";

		cout << mensagem;
	}

	static void imprimirCarregamentoComIcone(string mensagem, double segundos = 2) {
		imprimirCentralizadoPausadamente(mensagem);
		cout << '-' << flush;
		while (segundos >= 0) {
			this_thread::sleep_for(chrono::milliseconds(100));
			cout << "\b\\" << flush;
			this_thread::sleep_for(chrono::milliseconds(100));
			cout << "\b|" << flush;
			this_thread::sleep_for(chrono::milliseconds(100));
			cout << "\b/" << flush;
			this_thread::sleep_for(chrono::milliseconds(100));
			cout << "\b-" << flush;
			segundos -= 0.4;
		}
	}

	static void imprimirCarregamentoVertical(int velocidade = 700) {
		cout << ".";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n.";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n.";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n\n";
	}

	static void aguardarTecla() {
		cout << '\n' << "Pressione <ENTER> para continuar...";
		std::cin.ignore();
		
		#ifdef _WIN32
			system("pause >nul");
		#else
			system("read");
		#endif
	}
}

#endif
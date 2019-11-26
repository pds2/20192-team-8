#include <AuxiliaresConsole.hpp>

namespace auxiliaresConsole {
	void limpaConsole() {
		cout << "\033[2J\033[1;1H";
	}

	void imprimirPausadamente(string mensagem, int velocidade) {
		for (char const& c : mensagem) {
			cout << c << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
		}
	}

	void imprimirCentralizadoPausadamente(string s) {
		limpaConsole();

		const char* mensagem = s.c_str();

		int l = strlen(mensagem);
		int pos = (int)((4950 - l) / 2);
		for (int i = 0; i < pos; i++) {
			cout << " ";
		}

		imprimirPausadamente(mensagem, 60);
	}

	void imprimirCentralizado(string s) {
		limpaConsole();

		const char* mensagem = s.c_str();

		int l = strlen(mensagem);
		int pos = (int)((3000 - l) / 2);
		for (int i = 0; i < pos; i++)
			cout << " ";

		cout << mensagem;
	}

	void imprimirCarregamentoComIcone(string mensagem, double segundos) {
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

	void imprimirCarregamentoVertical(int velocidade) {
		cout << ".";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n.";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n.";
		this_thread::sleep_for(chrono::milliseconds(velocidade));
		cout << "\n\n";
	}

	void aguardarTecla() {
		cout << '\n' << "Pressione <ENTER> para continuar...";
		std::cin.ignore();

		#ifdef _WIN32
				system("pause >nul");
		#else
				cin.ignore();
		#endif
	}

	void imprimirTruco(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 4; i++) {
			cout << "\t\t\t\t\t\t.___________..______     __    __   ______   ______      ____" << endl << flush;
			cout << "\t\t\t\t\t\t|           ||   _  \\   |  |  |  | /      | /  __  \\     |  |  " << endl << flush;
			cout << "\t\t\t\t\t\t`---|  |----`|  |_)  |  |  |  |  ||  ,----'|  |  |  |    |  |   " << endl << flush;
			cout << "\t\t\t\t\t\t    |  |     |      /   |  |  |  ||  |     |  |  |  |    |__|  " << endl << flush;
			cout << "\t\t\t\t\t\t    |  |     |  |\\  \\   |  `--'  ||  `----.|  `--'  |    /  \\  "<< endl << flush;
			cout << "\t\t\t\t\t\t    |__|     | _| `._`.  \\______/  \\______| \\______/     \\__/   " << endl << flush;
			cout << "" << endl << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirSeis(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 4; i++) {
			cout << "\t\t\t\t\t\t     _______. _______  __      _______." << endl << flush;
			cout << "\t\t\t\t\t\t    /       ||   ____||  |    /       |" << endl << flush;
			cout << "\t\t\t\t\t\t   |   (----`|  |__   |  |   |   (----`" << endl << flush;
			cout << "\t\t\t\t\t\t    \\   \\    |   __|  |  |    \\   \\    " << endl << flush;
			cout << "\t\t\t\t\t\t.----)   |   |  |____ |  |.----)   |   " << endl << flush;
			cout << "\t\t\t\t\t\t|_______/    |_______||__||_______/    " << endl << flush;
			cout << "" << endl << flush;
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirNove(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 4; i++) {
			cout << "\t\t\t\t\t\t.__   __.  ______  ____    ____ _______ " << endl << flush;
			cout << "\t\t\t\t\t\t|  \\ |  | /  __  \\ \\   \\  /   /|   ____|" << endl << flush;
			cout << "\t\t\t\t\t\t|   \\|  ||  |  |  | \\   \\/   / |  |__   " << endl << flush;
			cout << "\t\t\t\t\t\t|  . `  ||  |  |  |  \\      /  |   __|  " << endl << flush;
			cout << "\t\t\t\t\t\t|  |\\   ||  `--'  |   \\    /   |  |____ " << endl << flush;
			cout << "\t\t\t\t\t\t|__| \\__| \\______/     \\__/    |_______|" << endl << flush;
			cout << "" << endl << flush;
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirDoze(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 4; i++) {
			cout << "\t\t\t\t\t\t _______    ______   ________   _______ " << endl << flush;
			cout << "\t\t\t\t\t\t|       \\  /  __  \\ |       /  |   ____|" << endl << flush;
			cout << "\t\t\t\t\t\t|  .--.  ||  |  |  |`---/  /   |  |__   " << endl << flush;
			cout << "\t\t\t\t\t\t|  |  |  ||  |  |  |   /  /    |   __|  " << endl << flush;
			cout << "\t\t\t\t\t\t|  '--'  ||  `--'  |  /  /----.|  |____ " << endl << flush;
			cout << "\t\t\t\t\t\t|_______/  \\______/  /________||_______|" << endl << flush;
			cout << "" << endl << flush;
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			cout << flush;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
		}
	}
}
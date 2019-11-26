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
		int pos = (int)((3000 - l) / 2);
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
		for (int i = 0; i < 5; i++) {
			cout << ".___________..______       __    __      ______   ______  " << endl;
			cout << "|           ||   _  \\     |  |  |  | /      | /  __  \\ " << endl;
			cout << "`---|  |----`|  |_)  |    |  |  |  ||  ,----'|  |  |  |" << endl;
			cout << "    |  |     |      /     |  |  |  ||  |     |  |  |  |" << endl;
			cout << "    |  |     |  |\\  \\----.|  `--'  ||  `----.|  `--'  |" << endl;
			cout << "    |__|     | _| `._____| \\______/  \\______| \\______/ " << endl;
			cout << "" << endl;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirSeis(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 5; i++) {
			cout << "     _______. _______  __      _______." << endl;
			cout << "    /       ||   ____||  |    /       |" << endl;
			cout << "   |   (----`|  |__   |  |   |   (----`" << endl;
			cout << "    \\   \\    |   __|  |  |    \\   \\    " << endl;
			cout << ".----)   |   |  |____ |  |.----)   |   " << endl;
			cout << "|_______/    |_______||__||_______/    " << endl;
			cout << "" << endl;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirNove(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 5; i++) {
			cout << ".__   __.  ______  ____    ____ _______ " << endl;
			cout << "|  \\ |  | /  __  \\ \\   \\  /   /|   ____|" << endl;
			cout << "|   \\|  ||  |  |  | \\   \\/   / |  |__   " << endl;
			cout << "|  . `  ||  |  |  |  \\      /  |   __|  " << endl;
			cout << "|  |\\   ||  `--'  |   \\    /   |  |____ " << endl;
			cout << "|__| \\__| \\______/     \\__/    |_______|" << endl;
			cout << "" << endl;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}

	void imprimirDoze(int velocidade) {
		limpaConsole();
		for (int i = 0; i < 5; i++) {
			cout << " _______    ______   ________   _______ " << endl;
			cout << "|       \\  /  __  \\ |       /  |   ____|" << endl;
			cout << "|  .--.  ||  |  |  |`---/  /   |  |__   " << endl;
			cout << "|  |  |  ||  |  |  |   /  /    |   __|  " << endl;
			cout << "|  '--'  ||  `--'  |  /  /----.|  |____ " << endl;
			cout << "|_______/  \\______/  /________||_______|" << endl;
			cout << "" << endl;
			this_thread::sleep_for(chrono::milliseconds(velocidade));
			limpaConsole();
			this_thread::sleep_for(chrono::milliseconds(velocidade));

		}
	}
}
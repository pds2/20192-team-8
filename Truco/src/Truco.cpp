// Truco.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <Carta.hpp>
#include <Baralho.hpp>
#include <Jogador.hpp>
#include <Turno.hpp>
#include <Rodada.hpp>

using namespace std;

int main()
{
	Jogador gabriel = Jogador("Gabriel");
	Jogador jamal = Jogador("Jamal");

	vector<Jogador> jogadores = { gabriel, jamal };
	Rodada rodada = Rodada(jogadores);

	rodada.fazJogada(gabriel, Carta(COPAS, '2'));
	rodada.fazJogada(jamal, Carta(COPAS, 'J'));
	rodada.finalizarTurno();

	rodada.fazJogada(gabriel, Carta(COPAS, 'K'));
	rodada.fazJogada(jamal, Carta(COPAS, 'J'));
	rodada.finalizarTurno();

	rodada.fazJogada(gabriel, Carta(COPAS, 'Q'));
	rodada.fazJogada(jamal, Carta(COPAS, 'Q'));
	rodada.finalizarTurno();

	try {
		vector<Jogador> vencedores = rodada.getVencedores();
		return 0;
	}
	catch (const RodadaIncompleta& e) {
		cout << e.what();
	}
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln

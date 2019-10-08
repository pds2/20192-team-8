# 20192-team-8 : Truco

Projeto da disciplina Programação e Desenvolvimento de Software II do curso Sistemas de Informação da UFMG

## User Stories

- Como usuário eu quero iniciar o programa e ver um menu para eu iniciar o jogo, ver o ranking de jogadores e sair do sistema


- Como usuário eu quero clicar no botão de iniciar jogo e aparecer uma tela de iniciar jogo contra um jogador e iniciar jogo contra a máquina

- Como usuário quero clicar no botão de ranking e ver uma lista ordenada pelos jogadores que mais ganharam e quantas partidas ganharam

- Como usuário quero clicar no botão para jogar contra a máquina, o sistema perguntar meu nome e ir para uma tela que irá ter informações sobre o jogo ( cartas, rodada, pontuação, etc ) e botões para pedir truco,seis,nove ou queda.

- Como usuário espero que quando alguém peça truco, seis, nove ou queda, eu tenha o opção de aceitar ou correr.

- Como usuário espero que quando alguém ganhe ou perca o jogo apareça uma tela falando quem venceu e redirecionar para o menu.

- Como usuário espero que quando clique para jogar contra outro jogador faça o mesmo fluxo que quando estou jogando contra a máquina, porém terão dois usuário dando inputs para a tela.

- Como usuário espero que depois que clicar em sair fechar o sistema.

## CRC's

| **Classe** | **Jogador** |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| Gerenciar as cartas de sua mão | Carta|
| realizar as jogadas  | Jogo |
|| Rodada|


| **Classe** | **Carta** |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| O valor da carta | Baralho|
| O naipe da carta  |Jogador |
|| Rodada|
|| JogadorBot|

| **Classe** | **Baralho** |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| Armazenar cartas disponiveis para a rodada | Carta |
| Disponibilizar cartas para os jogadores |Rodada |
| Embaralhar cartas||

| **Classe** | **Jogo** |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| Armazenar os jogadores | Jogador |
| Armazenar o placar |Rodada |

| **Classe** | **Rodadas** |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| Armazenar os vencedores de cada turno | Jogador |
| Valor da rodada |Baralho |
|| Cartas|

| **Classe** | **JogadorBot** :: Herança com Jogador |
|---------------|-----------------|
|Responsabilidades:| Colaborações: |
| Gerenciar as cartas de sua mão | Carta|
| realizar as jogadas automatizadas  | Jogo |
|| Rodada|



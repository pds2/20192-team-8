#include <Jogador.hpp>

Jogador::Jogador()
{
}

Jogador::Jogador(string nome) {
	this->nome = nome;
}

Jogador::Jogador(string nome, vector<Carta> cartas) {
	this->nome = nome;
	this->mao = cartas;
}

string Jogador::getNome() {
	return this->nome;
}

void Jogador::setNome(string nome) {
	this->nome = nome;
}
void Jogador::addCartaMao(Carta carta) {
	this->mao.push_back(carta);
}

void Jogador::removeCartaMao(Carta carta) {
	for (unsigned int i = 0; i < this->mao.size(); i++) {
		if (this->mao[i] == carta){
			this->mao.erase(this->mao.begin() + i);
		}
	}
}

Carta Jogador::getCartaMao(int posicao) {
	return this->mao.at(posicao);
}

vector<Carta> Jogador::getMao() {
	return this->mao;
}

int Jogador::getNumeroCartas() {
	return this->mao.size();
}

void Jogador::limparCartasMao() {
	this->mao = {};
}

bool Jogador::operator <(const Jogador& outroJogador) const
{
	return this->nome < outroJogador.nome;
}

bool Jogador::operator>(const Jogador& outroJogador) const
{
	return this->nome > outroJogador.nome;
}

bool Jogador::operator==(const Jogador& outroJogador) const
{
	return this->nome == outroJogador.nome;
}
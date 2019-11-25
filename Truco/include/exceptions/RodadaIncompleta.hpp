#ifndef RODADA_INCOMPLETA_H
#define RODADA_INCOMPLETA_H

#include <stdexcept>

using namespace std;

class RodadaIncompleta: public runtime_error
{
public:
	RodadaIncompleta();
	RodadaIncompleta(string mensagem);
};

#endif
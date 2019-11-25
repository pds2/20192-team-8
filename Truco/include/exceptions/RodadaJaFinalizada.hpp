#ifndef RODADA_JA_FINALIZADA_H
#define RODADA_JA_FINALIZADA_H

#include <stdexcept>

using namespace std;

class RodadaJaFinalizada : public runtime_error
{
public:
	RodadaJaFinalizada();
	RodadaJaFinalizada(string mensagem);
};

#endif

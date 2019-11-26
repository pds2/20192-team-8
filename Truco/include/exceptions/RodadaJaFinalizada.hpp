#ifndef RODADA_JA_FINALIZADA_H
#define RODADA_JA_FINALIZADA_H

#include <stdexcept>

using namespace std;

class RodadaJaFinalizada : public runtime_error
{
public:


	/**
	 * @brief Exceção para quando a rodada esta finalizada
	 *
	 */
	RodadaJaFinalizada();
	RodadaJaFinalizada(string mensagem);
};

#endif

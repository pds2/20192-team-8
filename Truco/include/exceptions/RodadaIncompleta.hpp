#ifndef RODADA_INCOMPLETA_H
#define RODADA_INCOMPLETA_H

#include <stdexcept>

using namespace std;

class RodadaIncompleta: public runtime_error
{
public:

	/**
	 * @brief Exceção para quando a rodada esta incompleta
	 *
	 */
	RodadaIncompleta();
	RodadaIncompleta(string mensagem);
};

#endif
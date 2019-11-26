#ifndef TURNO_INCOMPLETO_H
#define TURNO_INCOMPLETO_H

#include <stdexcept>

using namespace std;

class TurnoIncompleto : public runtime_error
{
public:
	  /**
	   * @brief Exce��o para quando o turno esta incompleto
	   *
	   */
	  TurnoIncompleto();
	  TurnoIncompleto(string mensagem);
};

#endif
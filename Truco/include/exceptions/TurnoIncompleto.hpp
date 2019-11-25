#ifndef TURNO_INCOMPLETO_H
#define TURNO_INCOMPLETO_H

#include <stdexcept>

using namespace std;

class TurnoIncompleto : public runtime_error
{
public:
	TurnoIncompleto();
	TurnoIncompleto(string mensagem);
};

#endif
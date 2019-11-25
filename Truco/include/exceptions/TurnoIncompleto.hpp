#ifndef TURNO_INCOMPLETA_H
#define TURNO_INCOMPLETA_H

#include <stdexcept>

using namespace std;

class TurnoIncompleto : public runtime_error
{
public:
	TurnoIncompleto();
	TurnoIncompleto(string mensagem);
};

#endif
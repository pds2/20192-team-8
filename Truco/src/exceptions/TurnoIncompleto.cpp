#include <TurnoIncompleto.hpp>

TurnoIncompleto::TurnoIncompleto() : runtime_error("N�o � poss�vel realizar a opera��o, pois o Turno ainda n�o terminou.")
{
}

TurnoIncompleto::TurnoIncompleto(string mensagem) : runtime_error(mensagem)
{
}

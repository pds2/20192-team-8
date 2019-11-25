#include <TurnoIncompleto.hpp>

TurnoIncompleto::TurnoIncompleto() : runtime_error("Não é possível realizar a operação, pois o Turno ainda não terminou.")
{
}

TurnoIncompleto::TurnoIncompleto(string mensagem) : runtime_error(mensagem)
{
}

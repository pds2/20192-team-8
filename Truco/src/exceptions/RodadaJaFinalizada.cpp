#include <RodadaJaFinalizada.hpp>


RodadaJaFinalizada::RodadaJaFinalizada() : runtime_error("N�o � poss�vel realizar a opera��o, pois a Rodada ainda n�o terminou.")
{
}

RodadaJaFinalizada::RodadaJaFinalizada(string mensagem) : runtime_error(mensagem)
{
}

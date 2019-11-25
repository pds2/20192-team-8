#include <RodadaIncompleta.hpp>

RodadaIncompleta::RodadaIncompleta() : runtime_error("N�o � poss�vel realizar a opera��o, pois a Rodada ainda n�o terminou.")
{
}

RodadaIncompleta::RodadaIncompleta(string mensagem) : runtime_error(mensagem)
{
}

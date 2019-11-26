#include <RodadaJaFinalizada.hpp>


RodadaJaFinalizada::RodadaJaFinalizada() : runtime_error("Não é possível realizar a operação, pois a Rodada ainda não terminou.")
{
}

RodadaJaFinalizada::RodadaJaFinalizada(string mensagem) : runtime_error(mensagem)
{
}

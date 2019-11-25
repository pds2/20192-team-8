#include <RodadaIncompleta.hpp>

RodadaIncompleta::RodadaIncompleta() : runtime_error("Não é possível realizar a operação, pois a Rodada ainda não terminou.")
{
}

RodadaIncompleta::RodadaIncompleta(string mensagem) : runtime_error(mensagem)
{
}

#include "funcs.h"
#include <string>
#include <vector>

namespace mc {

std::string diaDaSemana(int dia, int mes, int ano) {
  std::vector dias_no_mes{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool bissexto{};
  if (mod(400, ano) == 0) {
    bissexto = true;
  } else if (mod(100, ano) == 0) {
    bissexto = false;
  } else if (mod(4, ano) == 0) {
    bissexto = true;
  }

  if (bissexto) {
    dias_no_mes[2] = 29;
  }

  int anos_passados = ano - 1;

  int bissextos_passados =
      div(4, anos_passados) - div(100, anos_passados) + div(400, anos_passados);

  int total_dias = (anos_passados * 365) + bissextos_passados;

  for (int i = 1; i < mes; i++) {
    total_dias += dias_no_mes[i];
  }

  total_dias += dia;

  // se o dia 01/01/0001 foi uma segunda
  int h = mod(7, total_dias);

  std::vector<std::string> dias = {
      "Domingo",      "Segunda-feira", "Terça-feira", "Quarta-feira",
      "Quinta-feira", "Sexta-feira",   "Sábado"};

  return dias[h];
}

} // namespace mc

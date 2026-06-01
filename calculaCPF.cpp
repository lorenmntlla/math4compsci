#include "funcs.h"
#include <string>
#include <vector>

namespace mc {

int calculaVerificador(const std::vector<int> &vetor_cpf) {
  int verificador{0};

  int i = static_cast<int>(vetor_cpf.size() + 1);
  for (auto digito : vetor_cpf) {
    verificador += digito * i;
    i--;
  }

  verificador = mod(11, verificador * 10);

  if (verificador == 10)
    verificador = 0;

  return verificador;
}

std::string calculaCPF(std::vector<int> vetor_cpf) {
  std::string cpf{};

  vetor_cpf.push_back(calculaVerificador(vetor_cpf));
  vetor_cpf.push_back(calculaVerificador(vetor_cpf));

  for (size_t i{0}; i < vetor_cpf.size(); i++) {
    if (i > 0 and mod(3, static_cast<int>(i)) == 0 and i < 9)
      cpf.push_back('.');

    if (i > 0 and mod(9, static_cast<int>(i)) == 0)
      cpf.push_back('-');

    cpf.push_back(static_cast<char>(vetor_cpf[i]) + '0');
  }

  return cpf;
}
} // namespace mc

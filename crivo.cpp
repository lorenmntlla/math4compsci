#include "funcs.h"
#include <vector>

namespace mc {
std::vector<int> crivo(int inicio, int final) {
  std::vector<int> primos;

  if (final < 2)
    return primos;

  std::vector<bool> ehPrimo(final + 1, true);

  ehPrimo[0] = false;
  ehPrimo[1] = false;

  for (int p{2}; p * p <= final; p++) {
    if (!ehPrimo[p])
      continue;

    for (int i{p * p}; i <= final; i += p)
      ehPrimo[i] = false;
  }

  // Popula o vetor de retorno
  int partida = (inicio < 2) ? 2 : inicio;

  for (int i{partida}; i <= final; i++) {
    if (!ehPrimo[i])
      continue;

    primos.push_back(i);
  }

  return primos;
}
}; // namespace mc

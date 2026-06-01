#include "funcs.h"
#include <vector>

namespace mc {
std::pair<int, int> fatora_primo(int primo, int fatorando) {
  std::pair<int, int> fatorPrimo{primo, 0};

  while (mod(primo, fatorando) == 0) {
    fatorPrimo.second++;
    fatorando = div(primo, fatorando);
  }

  return fatorPrimo;
}

std::vector<std::pair<int, int>> fatora(int a) {
  std::vector<std::pair<int, int>> fatoresPrimos;

  auto primos = crivo(2, a);

  for (int primo : primos) {
    if (fatora_primo(primo, a).second == 0)
      continue;

    fatoresPrimos.push_back(fatora_primo(primo, a));
  }

  return fatoresPrimos;
}
}; // namespace mc

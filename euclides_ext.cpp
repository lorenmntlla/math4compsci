#include "funcs.h"
#include <iostream>

namespace mc {

ResultadoBezout euclidesEstendido(int a, int b) {
  int r0 = a, r1 = b;
  int s0 = 1, s1 = 0;
  int t0 = 0, t1 = 1;

  std::cout << "\n=== Algoritmo de Euclides Estendido ===\n";

  while (r1 != 0) {
    int q = div(r1, r0);
    int r_atual = mod(r1, r0);

    int s_atual = s0 - q * s1;
    int t_atual = t0 - q * t1;

    std::cout << "Divisão: " << r0 << " = " << q << " * " << r1 << " + "
              << r_atual << '\n';
    std::cout << "s = " << s0 << " - (" << q << ") * " << s1 << " = " << s_atual
              << '\n';
    std::cout << "t = " << t0 << " - (" << q << ") * " << t1 << " = " << t_atual
              << '\n';
    std::cout << "----------------------------------------\n";

    r0 = r1;
    r1 = r_atual;
    s0 = s1;
    s1 = s_atual;
    t0 = t1;
    t1 = t_atual;
  }

  return {r0, s0, t0};
}

} // namespace mc

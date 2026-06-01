#include <iostream>
#include <optional>

namespace mc {
int div_neg(int a, int b, int q = -1) {
  if (a * q == b)
    return q;

  if (a * q > b)
    return q + 1;

  return div_neg(a, b, q - 1);
}

int div_pos(int a, int b, int q = 1) {
  if (a * q == b)
    return q;

  if (a * q > b)
    return q - 1;

  return div_pos(a, b, q + 1);
}

std::optional<int> div_safe(int a, int b) {
  if (b == 0)
    return {}; // Divisão por 0 é indefinida.

  if (a == 0)
    return 0;

  if ((a < 0) xor (b < 0))
    return div_neg(a, b);

  return div_pos(a, b);
}

int div(int a, int b) {
  auto resultado {div_safe(a, b)};
  if (resultado)
    return *resultado;

  std::cerr << "Divisão por 0 é indefinida.\n";
  std::abort();
}
}; // namespace mc

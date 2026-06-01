#include "funcs.h"

namespace mc {
double teto(double a) {
  if (piso(a) == a)
    return a;

  return piso(a) + 1;
}
}; // namespace mc

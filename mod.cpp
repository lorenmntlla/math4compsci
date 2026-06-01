#include "funcs.h"

namespace mc {
int mod(int a, int b) {
  return b - div(a, b) * a;
}
};

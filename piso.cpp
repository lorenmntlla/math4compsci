namespace mc {
double acha_max_potencia2(double a, double potencia = 1.0) {
  if (potencia * 2.0 > a)
    return potencia;

  return acha_max_potencia2(a, potencia * 2.0);
}

double piso_pos_passo(double a, double potencia) {
  if (a - potencia < 1.0)
    return potencia;

  return potencia +
         piso_pos_passo(a - potencia, acha_max_potencia2(a - potencia));
}

double piso_pos(double a) {
  if (a < 1.0)
    return 0.0;

  return piso_pos_passo(a, acha_max_potencia2(a));
}

double piso(double a) {
  if (a >= 0.0)
    return piso_pos(a);

  if (piso_pos(-a) == -a)
    return a;

  return -(piso_pos(-a) + 1.0);
}
}; // namespace mc

#pragma once
#include <string>
#include <vector>

namespace mc {
struct ResultadoBezout {
  int mdc;
  int s;
  int t;
};

double piso(double a);
double teto(double a);

int div(int divisor, int dividendo);
int mod(int divisor, int dividendo);

std::vector<int> crivo(int inicio, int final);
std::vector<std::pair<int, int>> fatora(int a);

int mdc(int a, int b);
ResultadoBezout euclidesEstendido(int a, int b);

std::string diaDaSemana(int dia, int mes, int ano);

std::string calculaCPF(std::vector<int> vetor_cpf);
}; // namespace mc

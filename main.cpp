#include "funcs.h"
#include <iostream>
#include <string>

int main() {

  while (true) {
    std::cout << "\n<====================================>\n";
    std::cout << "          Escolha uma opção:\n";
    std::cout << "0. encerrar programa\n";
    std::cout << "1. piso e teto\n";
    std::cout << "2. divisão e mod\n";
    std::cout << "3. fatoração em primos\n";
    std::cout << "4. primos em um intervalo\n";
    std::cout << "5. algoritmo de Euclides\n";
    std::cout << "6. algoritmo de Euclides Extendido\n";
    std::cout << "7. dia da semana de uma data\n";
    std::cout << "8. dígitos verificadores de CPF\n";
    std::cout << "<====================================>\n";
    std::cout << "Opção: ";

    int escolha{};
    std::cin >> std::ws;
    std::cin >> escolha;

    std::cout << '\n';

    switch (escolha) {
    case 0:
      return 0;
    case 1: {
      // Questão 1.1
      std::cout << "Digite um número para calcular seu piso e teto: ";
      double a{};
      std::cin >> a;

      std::cout << "Piso(" << a << ") = " << mc::piso(a) << '\n';
      std::cout << "Teto(" << a << ") = " << mc::teto(a) << '\n';
      break;
    }
    case 2: {
      // Questão 1.2
      std::cout << "Digite dois inteiros para serem divididos: ";
      int b{}, c{};
      std::cin >> b >> c;
      int div = mc::div(b, c);
      int mod = mc::mod(b, c);

      std::cout << b << " div " << c << " = " << div << '\n';
      std::cout << b << " mod " << c << " = " << mod << '\n';
      break;
    }
    case 3: {
      // Questão 1.3
      std::cout << "Digite um número > 1 para ser fatorado: ";
      int d{};
      std::cin >> d;

      auto fatores = mc::fatora(d);
      std::cout << "Fatores primos: ";
      std::cout << '{';
      for (size_t i{0}; i < fatores.size() - 1; i++)
        std::cout << fatores[i].first << '^' << fatores[i].second << ", ";
      std::cout << fatores.back().first << '^' << fatores.back().second
                << "}\n";
      break;
    }
    case 4: {
      // Questão 1.4
      std::cout << "Digite um intervalo para calcular os primos entre eles: ";
      int e{}, f{};
      std::cin >> e >> f;

      auto primos = mc::crivo(e, f);
      std::cout << "Primos: ";
      std::cout << '{';
      for (size_t i{0}; i < primos.size() - 1; i++)
        std::cout << primos[i] << ", ";
      std::cout << primos.back() << "}\n";
      break;
    }
    case 5: {
      // Questão 2
      std::cout << "Digite dois inteiros para encontrar o MDC deles: ";
      int g{}, h{};
      std::cin >> g >> h;
      int mdc = mc::mdc(g, h);

      if (mdc == 1)
        std::cout << g << " e " << h << " são coprimos\n";
      else
        std::cout << "MDC(" << g << ", " << h << ") = " << mdc << '\n';
      break;
    }
    case 6: {
      // Questão 3
      std::cout << "Digite dois inteiros para a Identidade de Bezout: ";
      int i{}, j{};
      std::cin >> i >> j;
      mc::ResultadoBezout res = mc::euclidesEstendido(i, j);

      std::cout << "\n=> Identidade de Bezout Final: \n";
      std::cout << res.mdc << " = (" << res.s << ") * " << i << " + (" << res.t
                << ") * " << j << "\n";
      break;
    }
    case 7: {
      // Questão 
      std::cout << "Digite uma data (DD MM AAAA): ";
      int dia{}, mes{}, ano{};
      std::cin >> dia >> mes >> ano;
      std::cout << "O dia " << dia << "/" << mes << "/" << ano
                << " cai em um(a) " << mc::diaDaSemana(dia, mes, ano) << '\n';
      break;
    }
    case 8: {
      // Questão 4
      std::cout << "Digite um CPF para calcular os digitos verificadores: ";
      std::string cpf{};
      std::getline(std::cin >> std::ws, cpf);

      std::vector<int> vetor_cpf{};
      for (const auto &c : cpf) {
        if (vetor_cpf.size() == 9)
          break;

        if (c >= '0' and c <= '9')
          vetor_cpf.push_back(c - '0');
      }

      std::cout << "CPF: " << mc::calculaCPF(vetor_cpf) << '\n';
      break;
    }
    default: {
      std::cout << "Opção Inválida.\n";
      break;
    }
    }
  }
}

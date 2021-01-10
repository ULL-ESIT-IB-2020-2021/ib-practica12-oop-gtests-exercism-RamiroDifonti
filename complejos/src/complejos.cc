#include <iostream>
#include "complejos.h"

int main() {
  Complejo complejo1{3, 2}, complejo2{-1, 2};
  Complejo resultado;
  resultado = resultado.add(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.sub(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.mult(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.div(complejo1, complejo2);
  resultado.print(resultado);
}
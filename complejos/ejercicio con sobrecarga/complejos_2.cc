#include <iostream>
#include "complejos_2.h"

int main() {
  Complejo complejo1{3, 2}, complejo2{-1, 2};
  Complejo resultado;
  unsigned int numero_entero= 4;
  float numero_real = -4.5;
  resultado = resultado.add(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.add(complejo1, numero_real);         //MODIFICACION
  resultado.print(resultado);
  resultado = resultado.add(complejo1, numero_entero);    //MODIFICACION
  resultado.print(resultado);
  resultado = resultado.sub(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.mult(complejo1, complejo2);
  resultado.print(resultado);
  resultado = resultado.div(complejo1, complejo2);
  resultado.print(resultado);
}
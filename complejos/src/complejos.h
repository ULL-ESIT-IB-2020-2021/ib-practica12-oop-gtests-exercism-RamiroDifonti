#include <iostream>
#include <string>

class Complejo{

 public:
  Complejo();
  Complejo(float,float);
  Complejo add(Complejo complejo1,Complejo complejo2);
  Complejo sub(Complejo complejo1,Complejo complejo2);
  Complejo mult(Complejo complejo1,Complejo complejo2);
  Complejo div(Complejo complejo1,Complejo complejo2);
  void print(Complejo resultado);

 private:
  float real;
  float compleja;
  float numero;
};


Complejo::Complejo(float _real, float _compleja){
  real = _real;
  compleja = _compleja;
}
Complejo::Complejo(){}

Complejo Complejo::add(Complejo _complejo1,Complejo _complejo2){

    int suma_real = _complejo1.real + _complejo2.real;
    int suma_iman = _complejo1.compleja + _complejo2.compleja;
    Complejo suma(suma_real, suma_iman);
    std::cout<<"La suma de los complejos es: ";
    return suma;   
}
Complejo Complejo::sub(Complejo _complejo1,Complejo _complejo2){

    int resta_real = _complejo1.real - _complejo2.real;
    int resta_iman = _complejo1.compleja - _complejo2.compleja;
    Complejo resta(resta_real, resta_iman);
    std::cout<<"La resta de los complejos es: ";
    return resta;   
}
Complejo Complejo::mult(Complejo _complejo1,Complejo _complejo2){

    int mult_real = (_complejo1.real * _complejo2.real)+(-1*(_complejo1.compleja*_complejo2.compleja));
    int mult_iman = (_complejo1.real * _complejo2.compleja)+(_complejo2.real * _complejo1.compleja);
    Complejo multiplicacion(mult_real, mult_iman);
    std::cout<<"La multiplicación de los complejos es: ";
    return multiplicacion;   
}
Complejo Complejo::div(Complejo _complejo1,Complejo _complejo2){
    float compleja_cambio_signo= -1*(_complejo2.compleja);
    float multipl_numerador_real = (_complejo1.real * _complejo2.real)+(-1*(_complejo1.compleja* compleja_cambio_signo));
    float multipl_numerador_iman = (_complejo1.real* compleja_cambio_signo)+(_complejo1.compleja*_complejo2.real);
    float denominador = (_complejo2.real*_complejo2.real)+(-1*(_complejo2.compleja*compleja_cambio_signo));
    float div_real = multipl_numerador_real/denominador;
    float div_iman = multipl_numerador_iman/denominador;
    Complejo division(div_real, div_iman);
    std::cout<<"La división de los complejos es: ";
    return division;   
}
void Complejo::print(Complejo _resultado){
  
  std::cout<< "( "<<_resultado.real<<" , "<<_resultado.compleja<<"i )\n";
}


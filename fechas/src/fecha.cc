#include <iostream>
#include "fecha.h"
#include <string>
#include <fstream>

int main(int argc, char* argv[]){
  Usage(argc, argv);
  Foreword(argv);
  std::vector<int> dias= Archivos_dias(argv);
  std::vector<int> meses= Archivos_meses(argv);
  std::vector<int> anios= Archivos_anios(argv);
  std::vector<int> fechas_ordenadas = my_days.Ordenador(dias,meses,anios);
  my_days.Archivo_salida(fechas_ordenadas);
}
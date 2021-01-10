#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <array>
#include <algorithm>

std::string texto_usage = "fichero_entrada fichero_salida\nFichero_entrada: Fichero con fechas\nFichero_salida:  Fichero con fechas ordenado\n";       
void Usage(int argc, char* argv[]){
  std::string parameter = argv[1];
  if(parameter=="--help"&&argc==2){
    std::cout<<"Modo de uso: "<<argv[0]<<" "<<texto_usage;
    exit(EXIT_SUCCESS);
  }
  if(argc!=3){
    std::cout<<"Error en la sintaxis del programa, por favor introduzca "<<argv[0]<<" --help"<<std::endl;
    exit(EXIT_SUCCESS);
  }
  }
 
void Foreword(char* argv[]) {
  std::string entrada = argv[1];
  std::string salida = argv[2];
  std::cout << "Este programa ordena fechas y ademas dice si su año es bisiesto o no.\nPor favor, escriba las fechas en el archivo, cuando termine ejecute el programa devuelta. "<<entrada<<"\nLas fechas saldrán ordenadas en el archivo "<<salida<<"\n";
}

class Fecha {

 private:
  int day_{};
  int month_{};
  int year_{};
  int comprobador_bisiesto{};
  std::vector<int> years_{};
  std::vector<int> months_{};
  std::vector<int> days_{};
 public:
   bool Bisiesto(int numero){
      numero=numero+2000;
      if(numero%4==0){
        if(numero%100==0){
          if(numero%400==0){
            return 1;
          }else{return 0;}
        }else{return 1;}
      }else{return 0;}}
  std::vector<int> Ordenador(std::vector<int> dias,std::vector<int> meses,std::vector<int> anios){

    std::vector<int> fechas;
    int dias_2 = dias.size();
    for(int i=0;i!=dias_2;i++){
      fechas.push_back ((10000*(anios[i]+2000))+(meses[i]*100)+dias[i]);
    }
    sort(fechas.begin(), fechas.end()) ;
    return fechas;
  }
  void Archivo_salida(std::vector<int> fechas){

    std::string respuesta_bis;
    int anio{},mes{},dia{};
    std::ofstream archivo_salida;
    int fechas_2 = fechas.size();
    archivo_salida.open("salida.txt");
    archivo_salida<<"";
    for(int i=0;i!=fechas_2;i++){
      anio=fechas[i]/10000;
      mes=(fechas[i]-(anio*10000))/100;
      dia=(fechas[i]-(anio*10000))-(mes*100);
      archivo_salida<<dia;
      archivo_salida<<"/";
      archivo_salida<<mes;
      archivo_salida<<"/";
      archivo_salida<<anio;
      archivo_salida<<"   ";
      if(Bisiesto(anio)==1){
        respuesta_bis="BISIESTO";
      }else{respuesta_bis="NO BISIESTO";}
      archivo_salida<< respuesta_bis;
      archivo_salida<<"\n";
    }
    archivo_salida.close();
    std::ofstream archivo_entrada;
    archivo_entrada.open("entrada.txt");
    archivo_entrada.close();
  }
};

Fecha my_days;

std::vector<int> Archivos_dias(char* argv[]){

  std::string entrada{argv[1]}, frase;
  std::ifstream entrada_lectura;
  std::vector<std::string> dias{2};
  std::vector<int> vec_dia{};
  int dia{}, digito_1{},digito_2{};
  entrada_lectura.open(entrada);

  while(std::getline (entrada_lectura, frase)){

    dias[0]={frase[0]};
    dias[1]={frase[1]};
    digito_1 = std::stoi(dias[0]);
    digito_2 = std::stoi(dias[1]);
    dia=(digito_1*10)+digito_2;

    vec_dia.push_back(dia);
  }
  return vec_dia;
}
std::vector<int> Archivos_meses(char* argv[]){

  std::string entrada{argv[1]}, frase;
  std::ifstream entrada_lectura;
  std::vector<std::string> meses{2};
  std::vector<int> vec_mes{};
  int mes{}, digito_1{},digito_2{};
  entrada_lectura.open(entrada);

  while(std::getline (entrada_lectura, frase)){   

    meses[0]={frase[3]};
    meses[1]={frase[4]};
    digito_1 = std::stoi(meses[0]);
    digito_2 = std::stoi(meses[1]);
    mes=(digito_1*10)+digito_2;
    
    vec_mes.push_back(mes);   
  }
   return vec_mes;
  
}
std::vector<int> Archivos_anios(char* argv[]){

  std::string entrada{argv[1]}, frase;
  std::ifstream entrada_lectura;
  std::vector<std::string> anios{2};
  std::vector<int> vec_anio{};
  int anio{}, digito_1{},digito_2{};
  entrada_lectura.open(entrada);

  while(std::getline (entrada_lectura, frase)){   

    anios[0]={frase[6]};
    anios[1]={frase[7]};
    digito_1 = std::stoi(anios[0]);
    digito_2 = std::stoi(anios[1]);
    anio=(digito_1*10)+digito_2;

    vec_anio.push_back(anio);
  }
  return vec_anio;
}





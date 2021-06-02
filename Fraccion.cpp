#include "Fraccion.h"

//Constructores

Fraccion::Fraccion()
{
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int num, int den){
    if(den == 0 || num == 0){
      numerador = 0;
      denominador = 1;
    }
    else{
      reduccion(num,den);

      if(den < 0 ){
          num = -num;
          den = -den;
      }

      numerador = num;
      denominador = den;
    }
}

//Getters

int Fraccion::getNumerador()
{
  return numerador;
}

int Fraccion::getDenominador()
{
  return denominador;
}

//Setters

void Fraccion::setNumerador(int num){
  this -> numerador = num;
}

void Fraccion::setDenominador(int den){
  this -> denominador = den;
}

//Métodos

void Fraccion::reduccion(int &num, int &den){
  int a,b,res;

  if(num<den){
    a = den;
    b = num;
  }
  else{
    a = num;
    b = den;
  }

  do{
    res = b;
    b = a%b;
    a = res;
  }while(b!=0); //res va a ser el MCD

  num = num/res;
  den = den/res;
}

void Fraccion::imprimir(){
    cout << numerador << "/" << denominador << endl;
}

Fraccion Fraccion::operator+(Fraccion f2)
{
  int num = numerador * f2.getDenominador() +  denominador * f2.getNumerador();
  int den = denominador * f2.getDenominador();
  Fraccion fresultado(num, den);
  return fresultado;
}

Fraccion Fraccion::operator-(Fraccion f2)
{
  int num = numerador * f2.getDenominador() -  denominador * f2.getNumerador();
  int den = denominador * f2.getDenominador();
  Fraccion fresultado(num, den);
  return fresultado;
}

Fraccion Fraccion::operator*(Fraccion f2)
{
  int num = numerador * f2.getNumerador();
  int den = denominador * f2.getDenominador();
  Fraccion fresultado(num, den);
  return fresultado;
}

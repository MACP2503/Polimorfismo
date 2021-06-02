#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fraccion {

  private:
    int numerador;
    int denominador;
    
  public:
    //Constructores
    Fraccion();
    Fraccion(int,int);

    //Getters
    int getNumerador();
    int getDenominador();

    //Setters
    void setDenominador(int);
    void setNumerador(int);

    //Métodos
    void reduccion(int &,int &); //Simplificar Fraccion
    void imprimir(); //imprimir nuestra Fraccion

    //Polimorfismo (sobrecarga de operadores)
    Fraccion operator+(Fraccion); 
    Fraccion operator-(Fraccion);
    Fraccion operator*(Fraccion);
    
};

#endif // FRACCION_H
#ifndef VECTOR_H
#define VECTOR_H

#include "Fraccion.h"
#include <string>
#include <cmath>

#include <iostream>
using namespace std;

class Vector{
private:
    Fraccion * arr;  
    int size;  
    int sizeMem;
    //void setSize() //cuando modifiquemos el ejercicio usando la clase vector
public:
    //Constructores
    Vector();
    Vector(int);
    Vector(int, Fraccion *);  

    //Getters
    Fraccion getFraccion(int);
    int getSize();

    //Setters
    void setFraccion(int, Fraccion);

    //Métodos

    void agregarFraccion(Fraccion);
    void eliminarFraccion(); // ultimo elemento
    void imprimir();

    Vector operator+(Vector);
    Vector operator-(Vector);
    Fraccion operator*(Vector);

    float magnitud();
    Vector producto(Vector);
    float angulo(Vector);
    //Escalamiento
    Vector producto(int);
};


#endif // VECTOR_H

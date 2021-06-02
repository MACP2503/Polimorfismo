#include "Fraccion.h"
#include "Vector.h"
#include <iostream>
#include <stdio.h>
using namespace std;

//Tarea de polimorfismo
//Programación orientada a objetos

/*
-Sofia Ingigerth Cañas Urbina A01173828

-Marco Antonio Camalich Pérez A01351725

-Alejandro Paredes Balgañón A01351746

-Jesús Julián Madrid Castro A00227101

-Stephanie Ruiz Díaz A00227730

-2 de junio de 2021

-Iván Alejandro García Ramírez
*/

int main() {
	Fraccion f1(2, 4); 
	Fraccion f2(3,9);
  Fraccion f3(7,8);
  Fraccion f4(9,4);
  Fraccion f5(6,7);
  Fraccion f6(4,2);
  Fraccion f7(7,1);
  Fraccion f8(8,6);
  
  Fraccion ArrF1[] = {f1,f2,f3,f4};
  Fraccion ArrF2[] = {f5,f6,f7,f8};

  Vector v1(4, ArrF1);
  Vector v2(4, ArrF2);

  cout << "Dos vectores de dimensión 4"<<endl;

  cout << "v1: ";
  v1.imprimir();
  cout << "v2: ";
  v2.imprimir();

  Vector reSuma = v1 + v2;
  Vector reResta = v1 - v2;
  Fraccion reProductoPunto = v1 * v2;
  cout << "Producto cruz: ";
  Vector reProductoCruz = v1.producto(v2);
  Vector reProductoEsc1 = v1.producto(3);
  Vector reProductoEsc2 = v2.producto(4);

  cout << "Suma: "; reSuma.imprimir();

  cout << "Resta: "; reResta.imprimir();

  cout << "Producto punto: "; reProductoPunto.imprimir();

  cout << "Angulo: " << v1.angulo(v2) <<endl;

  cout << "Magnitud de v1: " << v1.magnitud()<<endl;
  
  cout << "Magnitud de v2: " << v2.magnitud()<<endl;

  cout << "Producto escalar de v1 por 3: "; reProductoEsc1.imprimir();

  cout << "Producto escalar de v2 por 4: "; reProductoEsc2.imprimir();

  cout<<endl<<endl;
  cout << "Dos vectores de dimensión 3"<<endl;

  Fraccion ArrF3[] = {f1, f2, f3};
  Fraccion ArrF4[] = {f4, f5, f6};

  Vector v3(3, ArrF3);
  Vector v4(3, ArrF4);

  cout << "v3: ";
  v3.imprimir();
  cout << "v4: ";
  v4.imprimir();

  Vector re2Suma = v3 + v4;
  Vector re2Resta = v3 - v4;
  Fraccion re2ProductoPunto = v3 * v4;
  Vector re2ProductoCruz = v3.producto(v4);
  Vector re2ProductoEsc1 = v3.producto(3);
  Vector re2ProductoEsc2 = v4.producto(4);

  cout << "Suma: "; re2Suma.imprimir();

  cout << "Resta: "; re2Resta.imprimir();

  cout << "Producto punto: "; re2ProductoPunto.imprimir();

  cout << "Producto cruz: "; re2ProductoCruz.imprimir();

  cout << "Angulo: " << v3.angulo(v4)<<endl;

  cout << "Magnitud de v3: " << v3.magnitud()<<endl;

  cout << "Magnitud de v4: " << v4.magnitud()<<endl;

  cout << "Producto escalar de v3 por 3: "; re2ProductoEsc1.imprimir();

  cout << "Producto escalar de v4 por 4: "; re2ProductoEsc2.imprimir();
  
  cout<<endl<<endl;
  cout << "Un vector de dimensión 3 y otro de 4"<<endl;

  cout << "v1: ";
  v1.imprimir();
  cout << "v3: ";
  v3.imprimir();

  cout << "Suma: ";
  Vector re3Suma = v1 + v3;

  cout << "Resta: ";
  Vector re3Resta = v1 - v3;

  cout << "Producto punto: ";
  Fraccion re3ProductoPunto = v1 * v3;

  cout << "Producto cruz: ";
  Vector re3ProductoCruz = v1.producto(v3);

  cout << "Angulo: " << v1.angulo(v3) <<endl;

	return 0;

}


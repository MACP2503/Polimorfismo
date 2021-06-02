#include "Vector.h"
#include "Fraccion.h"


//Constructor sin argumentos
Vector::Vector(){
    arr = new Fraccion[1];
    size = 1;
    sizeMem = 1;
}

//Constructor con tamaño especifico
Vector::Vector(int s){
    size = s;
    arr = new Fraccion[s];
    sizeMem = s;
}

//Constructor con arreglo especifico
Vector::Vector(int s, Fraccion * arrf){
    arr = arrf;
    size = s;
    sizeMem = s;
}

//Getters
//Obtener Fraccion por indice
Fraccion Vector::getFraccion(int i){
    return arr[i];
}

int Vector::getSize(){
  return this -> size;
}

//Setters
//Cambiar una fraccion por indice
void Vector::setFraccion(int i, Fraccion f){
    arr[i] = f;
}

//Métodos

void Vector::agregarFraccion(Fraccion f){
    // Se duplica el tamaño de la memoria para evitar trasladar arreglos de elementos cada que se agrega una fraccion
    if(size+1 > sizeMem){
        //Se crea un nuevo arreglo de fracciones con el doble de memoria
        Fraccion * newArr = new Fraccion[size*2];
        //Se copia el arreglo en el nuevo arreglo
        for (int i=0; i<size; i++){
            newArr[i] = arr[i];
        }
        newArr[size+1] = f;
        arr = newArr;
        sizeMem = size*2;
        size = size+1;
    }else{
        //Si hay suficiente memoria reservado, entonces, simplemente agregalo
        arr[size+1] = f;
        size++;
    }
}

void Vector::eliminarFraccion(){ //ultimo elemento
    arr[size].setNumerador(0);
    arr[size].setDenominador(1);
    size--;
}

void Vector::imprimir(){
    cout << "[";
    for (int i=0; i<size; i++){
        cout << arr[i].getNumerador() << "/" << arr[i].getDenominador();
        if( i < size-1)
            cout << ", ";
    }
    cout << "]" << endl;
}

//----------------------------------------------------------

Vector Vector::operator+(Vector v2)
{
// Si los tamaños de los arreglos coinciden
  if(size == v2.getSize()){
    Vector newVector(size);
      for (int i=0; i<size; i++){
        //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
            newVector.setFraccion(i, arr[i]+v2.getFraccion(i));
        }
        return newVector;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vector();
    }
}

Vector Vector::operator-(Vector v2)
{
// Si los tamaños de los arreglos coinciden
  if(this -> size == v2.getSize())
  {
    Vector newVector(size);
      for (int i=0; i<size; i++)
      {
        //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
            newVector.setFraccion(i, arr[i]-v2.getFraccion(i));
      }
        return newVector;
  }
  else
    {
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Vector();
    }
}

Fraccion Vector::operator*(Vector v2)
{
// Si los tamaños de los arreglos coinciden
  if(this -> size == v2.getSize())
  {
    Fraccion res = Fraccion();
      for (int i=0; i<size; i++)
      {
        //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
          res = res + arr[i] * v2.getFraccion(i);
      }
        return res;
    }else{
        cout << "Los vectores no tienen el mismo numero de elemetos" << endl;
        return Fraccion();
    }
}

float Vector::magnitud()
{
  double mag = 0.0;
  double div, c;

  for (int i=0; i<size; i++)
  {
    float num = arr[i].getNumerador();
    float den = arr[i].getDenominador();
    div=num/den;
    c=pow(div,2);
    mag+=c;//sumar cuadrados
  }
  mag = sqrt(mag); //sacar raíz
  return mag;
}

Vector Vector::producto(Vector v2)
{
  // Si los tamaños de los arreglos son ambos 3
  if(this -> size == 3 && v2.getSize() == 3){
    Vector newVector(3);
    //En el nuevo vector establece el resultado correspondiente al 
    //producto cruz en cada dimension
    newVector.setFraccion(0, (arr[1] * v2.getFraccion(2)) - (arr[2] * v2.getFraccion(1)));
    newVector.setFraccion(1, (arr[2] * v2.getFraccion(0)) - (arr[0] * v2.getFraccion(2)));
    newVector.setFraccion(2, (arr[0] * v2.getFraccion(1)) - (arr[1] * v2.getFraccion(0)));
    
    return newVector;
    }else{
        cout << "Ambos vectores deben ser de tamaño 3" << endl;
        return Vector();
    }
}

float Vector::angulo(Vector v2)
{
  if(this -> size == 3 && v2.getSize() == 3){
    Vector v1(size, arr);
    Fraccion punto = v2 * v1;
    float grad; 
    float num = punto.getNumerador();
    float den = punto.getDenominador();
    grad = acos((num/den)/(abs(v1.magnitud())*abs(v2.magnitud())));
    grad *= (180/M_PI);
    return grad;
  }else{
        cout << "Ambos vectores deben ser de tamaño 3" << endl;
        return 0;
  }
}

//Escalamiento
Vector Vector::producto(int esc)
{
  Fraccion fracEsc(esc, 1);
  Vector newVector(size);
  for (int i=0; i<size; i++){
    //En la nueva fraccion estable el resultado de la suma entre las 2 fracciones con el mismo indice
    newVector.setFraccion(i, arr[i] * fracEsc);
  }
  return newVector;
}
#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include <string>
#include "Video.h"
#include "Temporada.h"

using namespace std;

class Serie: public Video {

  public:
    Temporada * temporadas;
    int ntemporadas;

  public:
    //Constructores
  Serie();
  Serie(string, string, float, string,Temporada *,int);
  void EvaluacionSerie();

};

#endif
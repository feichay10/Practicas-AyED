// AUTOR: Cheuk Kelly Ng Pante
// FECHA: 4/03/2020
// EMAIL: alu0101364544@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>


# define EPSILON 1e-6

using namespace std;

class rational_t {
  //Elemento publico
  public: 
  //Constructor
  rational_t(const int = 0, const int = 1); 
  //Destructor
  ~rational_t() {} 
  
  
  // getters: sirve para devolver el valor de un atributo
  int get_num() const;
  int get_den() const;
  
  // setters: sirve para dar valor a un atributo
  void set_num(const int);
  void set_den(const int);

  double value(void) const;

  // FASE II
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  bool is_EqualZero(const rational_t&, const double precision = EPSILON) const;
  
  // FASE III
  rational_t add(const rational_t&);
  rational_t substract(const rational_t&);
  rational_t multiply(const rational_t&);
  rational_t divide(const rational_t&);

  //Modificacion
  rational_t reciprocal(void);
  
  //Entrada y Salida
  void write(ostream& = cout) const;
  void read(istream& = cin);
  
  //Elemento privado
private: 
  //Atributos
  int num_, den_; 

};

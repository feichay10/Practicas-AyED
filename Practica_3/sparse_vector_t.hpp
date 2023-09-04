// AUTOR: Cheuk Kelly Ng Pante
// FECHA: 01/04/2020
// EMAIL: alu0101364544@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"
#include "pair_t.hpp"

using namespace std;


typedef vector_t<pair_t<double>> pair_vector_t; //Elemento público

class sparse_vector_t //Elemento privado
{
public: //Comienzo de los elementos públicos
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia
  
  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t(); //Destructor
  
  // getters
   int get_nz(void) const;  
   int get_n(void) const;
   
   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);
   int inx_min(void);
   
   // E/S
   void write(ostream& = cout) const; //Método para la escritura en pantalla

private:  //Comienzo de los elementos privados
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original
  
  bool is_not_zero(double, double = 1e-6) const;  
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(),
nz_(0),
n_(0)
{
int j = 0;
  n_ = v.get_size();
  for (int i = 0; i < v.get_size(); ++i){
    if(is_not_zero(v[i])){
      nz_++;
    }
  }
  pv_.resize(nz_);
  for (int i = 0; i < v.get_size(); i++){
    if(is_not_zero(v[i])){
      pv_[j].set(v[i], i);
      j++;
    }
  }
}



// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}



sparse_vector_t::~sparse_vector_t()
{}



inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}



void
sparse_vector_t::write(ostream& os) const
{ 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}



bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  double s = 0;
    assert (get_n() == v.get_size());
    for (int i = 0; i < get_nz(); i++){
      s = s + pv_[i].get_val() * v[pv_[i].get_val()];
    }
  return s;
}


// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  double s = 0;
  int j=0;
     assert (get_n() == sv.get_n());
      for (int i = 0; i < pv_.get_size(); i++){
        j = pv_[i].get_inx();
        for (int k = 0; k < sv.get_nz(); k++){
          if (sv.pv_[k].get_inx() == j){
            s = s + pv_[i].get_val() * sv.pv_[k].get_val();
          }
        }
      }
  return s;
}


//Modificación
int 
sparse_vector_t::inx_min(void)
{
  int min = INFINITY;
  double indice;
  for (int i = 0; i < pv_.get_size(); i++){
    if (min > pv_[i].get_val()){
      min = pv_[i].get_val();
      indice = pv_[i].get_inx();
    }
  return indice;
  }
}

//Si a lo que se refería a la practica con el indice con la posición debería cambiar el indice pv_[i].get_inx por i
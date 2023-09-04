// AUTOR: Cheuk Kelly Ng Pante
// FECHA: 4/03/2020
// EMAIL: alu0101364544@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

int rational_t::get_num() const
{
  return num_;
}

int rational_t::get_den() const
{
  return den_;
}

void rational_t::set_num(const int n)
{
  num_ = n;
}

void rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}

double
rational_t::value() const
{
  return double(get_num()) / get_den();
}

// comparaciones
bool rational_t::is_equal(const rational_t &r, const double precision) const
{
  if (fabs(value() - r.value()) < precision)
    return true;
  else
    return false;
}

bool rational_t::is_greater(const rational_t &r, const double precision) const
{
  if (fabs(value() - r.value()) > precision)
    return true;
  else
    return false;
}

bool rational_t::is_less(const rational_t &r, const double precision) const
{
  if (fabs(r.value() - value()) < precision)
    return true;
  else
    return false;
}

bool rational_t::is_EqualZero(const rational_t &r, const double precision) const
{
  if (fabs(value()) < precision)
    return true;
  else
    return false;
}

// operaciones
rational_t rational_t::add(const rational_t &r)
{
  rational_t add((get_num() * r.get_den() + r.get_num() * get_den()), (get_den() * r.get_den()));
  return (add);
}

rational_t rational_t::substract(const rational_t &r)
{
  rational_t substract((get_num() * r.get_den() - r.get_num() * get_den()), (get_den() * r.get_den()));
  return (substract);
}

rational_t rational_t::multiply(const rational_t &r)
{
  rational_t multiply(get_num() * r.get_num(), get_den() * r.get_den());
  return (multiply);
}

rational_t rational_t::divide(const rational_t &r)
{
  rational_t divide(get_num() * r.get_den(), get_den() * r.get_num());
  return (divide);
}

//Modificacion
rational_t rational_t::reciprocal(void)
{
  rational_t reciprocal(get_den(), get_num());
  return (reciprocal);
}

// E/S
void rational_t::write(ostream &os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream &is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

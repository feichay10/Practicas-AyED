// AUTOR: Cheuk Kelly Ng Pante  
// FECHA: 26/05/2020  
// EMAIL: alu0101364544@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include "maze_t.hpp"

// Incluyo en la parte publica de la clase maze_t en el archivo maze_t.hpp "int count_wall(int);"

// constructor
maze_t::maze_t():
matrix_(),
visited_(),
i_start_(-1),
j_start_(-1),
i_end_(-1),
j_end_(-1)
{}


// destructor
maze_t::~maze_t()
{}



// método que resuelve el laberinto invocando al método recursivo
bool
maze_t::solve()
{
  return solve_(i_start_, j_start_);
}



// lee el laberinto en forma de matriz desde la entrada
istream&
maze_t::read(istream& is)
{
  //Modificación
  int count = 0;
  
  int m, n;
  is >> m >> n;
  assert(m > 0 && n > 0);

  matrix_.resize(m, n);
  visited_.resize(m, n);

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      short s;
      is >> s;

      // si el dato es un START_ID -> entrada al laberinto
      if (s == START_ID)
      {
        i_start_ = i;
        j_start_ = j;
      }
      // si el dato es un END_ID -> salida al laberinto
      else if (s == END_ID)
      {
        i_end_ = i;
        j_end_   = j;
      }

      //Modificación
      if (s == WALL_ID)
        count = count_wall(count);

      matrix_(i, j) = s;
    }
  }

  // comprobamos que se han leído correctamente la entrada y la salida
  assert (i_start_ != -1 && j_start_ != -1 && i_end_ != -1 && j_end_ != -1);
  
  //Modificación
  cout << "El número de muros son: " << count << endl;

  return is;
}



// muestra el laberinto por pantalla
ostream&
maze_t::write(ostream& os) const
{
  os << matrix_.get_m() << "x" << matrix_.get_n() << endl;
  for (int i = 1; i <= matrix_.get_m(); i++)
  {
    for (int j = 1; j <= matrix_.get_n(); j++)
      switch (matrix_(i, j))
      {
        case START_ID: os << START_CHR; break;
        case END_ID:   os << END_CHR;   break;
        case WALL_ID:  os << WALL_CHR;  break;
        case PASS_ID:  os << PASS_CHR;  break;
        case PATH_ID:  os << PATH_CHR;  break;
      }
    os << endl;
  }

  return os;
}

//Modificación
int
maze_t::count_wall(int count)
{
  return count += 1;
} 



// FASE I
// comprueba que la fila i y columna j son válidas antes de pasar a ellas
bool
maze_t::is_ok_(const int i, const int j) const
{
  // retornar true si se cumplen TODAS estas condiciones:
  // - fila i y la columna j están dentro de los límites del laberinto,
  // - la celda en (i, j) no puede ser un muro,
  // - la celda (i, j) no puede haber sido visitada antes.
  return (i >= 1 && i <= matrix_.get_m()) && 
         (j >= 1 && j <= matrix_.get_n()) &&
         matrix_(i, j) != WALL_ID && 
         !visited_(i, j);
}



// FASE II y FASE III
// método recursivo que resuelve el laberinto
bool
maze_t::solve_(const int i, const int j)
{
  // CASO BASE:
  // retornar 'true' si 'i' y 'j' han llegado a la salida
  if(matrix_(i, j) == END_ID)
    return true;
  
  // marcamos la celda como visitada
  visited_(i, j) = true;
  
  // CASO GENERAL:
  // para cada una de las 4 posibles direcciones (N, E, S, W) ver si es posible
  // el desplazamiento (is_ok_) y, en ese caso, intentar resolver el laberinto
  // llamando recursivamente a 'solve'. 
  // Si la llamada devuelve 'true', poner en la celda el valor PATH_ID, y
  // propagarla retornando también 'true'
  //N
  if(is_ok_(i-1,j) && solve_(i-1,j)){
    matrix_(i-1,j) = PATH_ID;
    return true;
  }

  //E
  if(is_ok_(i,j+1) && solve_(i,j+1)){
    matrix_(i,j+1) = PATH_ID;
    return true;
  }

  //S
  if(is_ok_(i+1,j) && solve_(i+1,j)){
    matrix_(i+1,j) = PATH_ID;
    return true;
  }
  
  //W
  if(is_ok_(i,j-1) && solve_(i,j-1)){
    matrix_(i,j-1) = PATH_ID;
    return true;
  }
  
  // desmarcamos la celda como visitada (denominado "backtracking") y
  // retornamos 'false'
  visited_(i, j) = false;
  return false;
}



// operador de entrada sobrecargado
istream&
operator>>(istream& is, maze_t& M)
{
  return M.read(is);
}



// operador de salida sobrecargado
ostream&
operator<<(ostream& os, const maze_t& M)
{
  return M.write(os);
}



// AUTOR: Cheuk Kelly Ng Pante  
// FECHA: 10/05/2020  
// EMAIL: alu0101364544@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c))
		{
		  int i = c - '0';
		  // poner código
		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
		  stack_.push(i);
		}
		else {
		  cout << " (es un operador)" << endl;
		  // poner código
		  this->operate_(c);
		}
	}
	// poner código
	return stack_.top();
}


template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'c');
  // código
    int a, b;
  b = stack_.top();
  stack_.pop();
  cout << "   Sacamos de la pila un operando: " << b << endl;

  
  if (c != 'l' || c != 'r' || c != 'c')
  {
  	// código
  	a = stack_.top();
  	stack_.pop();
	cout << "   Sacamos de la pila otro operando: " << a << endl;
  }
  int result;
	switch (c)
	{
	 	case '+': // código
			result = a + b;
	    	break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case 'r':
			result = sqrt(b);
			break;
		case '^':
			result = pow(a, b);
			break;
		case 'l':
			result = log2(b);
			break;
		case 'c':
			result = pow(b, 2);
			break;
	  // resto de operadores
	}

	// código
	stack_.push(result);
	cout << "   Metemos en la pila el resultado: " << result << endl;
}


}

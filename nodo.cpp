#include "nodo.h"
using namespace std;


template<class T>
Nodo<class T>::Nodo(T ndato):
	dato(ndato),
	siguiente(NULL)
{
}

template<class T>
Nodo<class T>::~Nodo()
{}

template<class T>
void Nodo<class T>::set_dato(T ndato)
{
	dato=ndato;
}

template<class T>
T Nodo<class T>::get_dato()
{
	return dato;
}

template<class T>
void Nodo<class T>::set_siguiente(Nodo<class T>* n)
{
	siguiente=n;
}
template<class T>
Nodo<class T>* Nodo<class T>::get_siguiente()
{
	return siguiente;
}

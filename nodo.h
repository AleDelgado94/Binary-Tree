#include <iostream>
#include "typedef.h"

template<class T>
class Nodo
{
	private:
	
		T dato;
		Nodo<class T>* siguiente;

	public:
	
		Nodo(T ndato);
		~Nodo();
		void set_dato(T ndato);
		T get_dato();
		Nodo<class T>* get_siguiente();
		void set_siguiente(Nodo<class T>* n);
		
};



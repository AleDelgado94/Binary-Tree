#include<iostream>


template<class CLAVE>
class NodoB
{
	public:
	
	CLAVE dato;
	CLAVE clave;
	NodoB *izdo;
	NodoB *dcho;
	
	NodoB(const CLAVE dat, NodoB *izq=NULL, NodoB *der=NULL):
		dato(dat),
		izdo(izq),
		dcho(der)
	{}
	
	NodoB(const CLAVE dat, CLAVE cl, NodoB *iz=NULL, NodoB *de=NULL):
		dato(dat),
		clave(cl),
		izdo(iz),
		dcho(de)
	{}
		
	
	~NodoB(){}		
};

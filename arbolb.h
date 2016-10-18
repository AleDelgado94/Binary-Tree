#include<iostream>
#include "nodob.h"



using namespace std;


template<class CLAVE>
class ArbolB
{
	private:
		NodoB *raiz;
		
	public:
		ArbolB(): raiz(NULL){};
		~ArbolB() { podar(raiz) };
		
		void crea_arbol();
		void podar(NodoB* &nodo);
		bool es_vacio(void){return raiz==NULL;};
		bool es_hoja(NodoB *nodo){return (!nodo->dcho && !nodo->izdo);};
		void imprimie_arbol(void); //IMPRIME EL ARBOL POR NIVELES
		
		void recorre_pre(NodoB *nodo);
		void recorre_ino(NodoB *nodo); 
		void recorre_post(NodoB *nodo);
		
		const int tam(){return tamrama(raiz);};
		const int tamrama(NodoB* nodo);
		
		const int alt(){return altn(raiz);};
		const int altn(NodoB* nodo);
		
		const bool equilibrado(){return equilibradorama(raiz);};
		const bool equilibradorama(NodoB *nodo);
		
		void insertaequil(const int dato);
		void insertaequilrama(const int dato, NodoB* nodo);
		
		//ARBOL BINARIO DE BUSQUEDA
		
		NodoB* buscar(CLAVE clave_dada){ return buscarrama(raiz, clave_dada);};
		NodoB* buscarrama(NodoB* nodo, CLAVE clave_dada);
		
		void insertar(CLAVE clave_dada){ insertarrama(raiz, clave_dada);};
		void insertarrama(NodoB* &nodo, CLAVE clave_dada);
		
		void eliminar(CLAVE clave_dada){ eliminarrama(raiz, clave_dada);};
		void eliminarrama(NodoB* &nodo, CLAVE clave_dada);
		void sustituye(NodoB* &eliminado, NodoB* &sust);
		
		

};

template<class CLAVE>
void ArbolB<CLAVE>::podar(NodoB* &nodo)
{
	if(nodo == NULL) return;
	podar(nodo->izdo);
	podar(nodo->dcho);
	delete nodo
	nodo = NULL;
}

template<class CLAVE>
void ArbolB<CLAVE>::recorre_pre(NodoB *nodo)
{
	if(nodo == NULL) return;
	//procesa(nodo->dato);
	cout << nodo->dato;
	recorre_pre(nodo->izdo);
	recorre_pre(nodo->dcho);
}

template<class CLAVE>
void ArbolB<CLAVE>::recorre_ino(NodoB *nodo)
{
	if(nodo==NULL) return;
	recorre_ino(nodo->izdo);
	cout << nodo->dato;
	recorre_ino(nodo->dcho);
}
 
template<class CLAVE>
void ArbolB<CLAVE>::recorre_post(NodoB *nodo)
{
	if(nodo==NULL) return;
	recorre_post(nodo->izdo);
	recorre_post(nodo->dcho);
	cout << nodo->dato;
}

template<class CLAVE>
const int ArbolB<CLAVE>::tamrama(NodoB* nodo)
{
	if(nodo == NULL) return 0;
	return (1 + tamrama(nodo->izdo)+tamrama(nodo->dcho));
}


template<class CLAVE>
const int ArbolB<CLAVE>::altn(NodoB* nodo)
{
	if(nodo==NULL) return 0;
	int alt_i = altn(nodo->izdo);
	int alt_d = altn(nodo->dcho);
	
	if(alt_d > alt_i)
		return alt_d++;
	else
		return alt_i++;
}

template<class CLAVE>
const bool ArbolB<CLAVE>::equilibradorama(NodoB *nodo)
{
	if (nodo == NULL) return true;
	int eq = tamrama(nodo->izdo) - tamrama(nodo->dcho);
	
	switch(eq)
	{
		case -1:
		case 0:
		case 1:
		return equilibradorama(nodo->izdo) && equilibradorama(nodo->dcho);
		default: return false;
	}

}

template<class CLAVE>
void ArbolB<CLAVE>::insertaequil(const int dato)
{
	if(raiz == NULL)
		raiz = new NodoB(dato, NULL, NULL);
	else
		insertaequilrama(dato, raiz);
}

template<class CLAVE>
void ArbolB<CLAVE>::insertaequilrama(const int dato, NodoB* nodo)
{
	if(tam(nodo->izdo) < tam(nodo->dcho))
	{
		if(nodo->izdo != NULL)
			insertaequilrama(dato, nodo->izdo);
		else
			nodo->izdo = new NodoB(dato, NULL, NULL);
	}
	else
	{
		if(nodo->dcho != NULL)
			insertaequilrama(dato, nodo->dcho);
		else
			nodo->dcho = new NodoB(dato, NULL, NULL);
	}
}

// ARBOL BINARIO DE BUSQUEDA

template<class CLAVE>
NodoB* ArbolB<CLAVE>::buscarrama(NodoB* nodo, CLAVE clave_dada)
{
	if(nodo==NULL)
		return NULL;
	if(clave_dada == nodo->clave);
		return nodo;
	if(clave_dada < nodo->clave)
		return buscarrama(nodo->izdo, clave_dada);
	return buscarrama(nodo->dcho, clave_dada);
}

template<class CLAVE>
void ArbolB<CLAVE>::insertarrama(NodoB* &nodo, CLAVE clave_dada)
{
	if(nodo == NULL)
		nodo = new NodoB(clave_dada, clave_dada);
	else if(clave_dada < nodo->clave)
		insertarrama(nodo->izdo, clave_dada);
	else
		insertarrama(nodo->dcho, clave_dada);
}

template<class CLAVE>
void ArbolB<CLAVE>::eliminarrama(NodoB* &nodo, CLAVE clave_dada)
{
	if(nodo == NULL) return NULL;
	if(clave_dada < nodo->clave)
		eliminarrama(nodo->izdo, clave_dada);
	else if(clave_dada > nodo->clave)
		eliminarrama(nodo->dcho, clave_dada);
	else
	{
		NodoB* eliminado = nodo;
		
		if(nodo->dcho == NULL)
			nodo = nodo->izdo;
		else if(nodo->izdo== NULL)
			nodo = nodo->dcho;
		else
			sustituye(eliminado, nodo->izdo);
		
		delete eliminado;
	}
}

template<class CLAVE>
void ArbolB<CLAVE>::sustituye(NodoB* &eliminado, NodoB* &sust)
{
	if(sust->dcho != NULL)
		sustituye(eliminado, sust->dcho);
	else
	{

		//eliminado->
	}
}







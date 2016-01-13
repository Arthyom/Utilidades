/******************************************************************************
    ********************** tipo lista *********************************
*******************************************************************************/

# include "fwsNodo.h"

/******************************************************************************
    ******************** declaracion del lista enlazada ********************
*******************************************************************************/
typedef struct {

  nodo    * cabeza;
  nodo    * cola;
  int       dms;

}lista;

lista     * crearLista  ( ){
  lista *nuevaLista = (lista*) malloc ( sizeof(lista) );
  nuevaLista->cabeza = NULL;
  nuevaLista->cola   = NULL;
  nuevaLista->dms    = 0;

  return nuevaLista;
}

/******************************************************************************
    ******************** funiones de la lista ********************
*******************************************************************************/

/*****-> funciones para agregar elementos  */
void actIndx ( lista    * listaActual ){

  nodo * nodoAux = listaActual->cabeza;

  /* iterear paracada nodo de la lista hasta que termine */
  while ( nodoAux )
    nodoAux->indice += 1 ;

}

void addFnl  ( lista    * listaActual, nodo  * nuevoNodo ){

  nodo *nodoAux = listaActual->cabeza;

  if ( !listaActual->cabeza )
  {
    listaActual->cabeza = nuevoNodo;
    listaActual->cabeza->indice = 1;
  }
  else
  {
    while ( nodoAux->nodoSiguiente )
      nodoAux = nodoAux->nodoSiguiente;

    nodoAux->nodoSiguiente = nuevoNodo;
    nuevoNodo->indice = nodoAux->indice  + 1 ;
  }

  listaActual->dms ++ ;

}


// agrega el nodo en el indice especifiado
/************************************************************************
*************************************************************************
int  addAtt  ( lista    * listaActual, nodo  * nuevoNodo, int indx ){

  nodo *nodoAux = listaActual->cabeza;
  nodo *nodoAnt = NULL;
  nodo *nodoBus = NULL;

  if ( !listaActual->cabeza ){
      listaActual->cabeza = nuevoNodo
      listaActual->dms ++;
      return 1;
  }
  else{
    // buscar el indice en la lista
    while ( nodoAux )
    {
      /// comparar el indice
      if ( nodoAux->indice == indx )
      {
        nodoBuscado = nodoAux;
        break;
      }
      // moverse entre el siguiente y el anterior del nodoaux
      nodoAnt = nodoAux;
      nodoAux = nodoAux->siguiente;
    }
    /// conectar nodos ant->aux->sig
    nuevoNodo->siguiente = nodoAux;
    nodoAnt = nuevoNodo;
    listaActual->dms ++;
    return 1;
  }

  return 0;
}
*************************************************************************
************************************************************************/

/*****-> funciones para eliminar elementos  */
void  elmnFnl   ( lista * listaActual ){
  nodo *nodoAux = listaActual->cabeza;
  nodo *nodoAnt = NULL;

  if ( listaActual->cabeza ){
    while ( listaActual->cabeza && nodoAux->nodoSiguiente ){
      nodoAnt = nodoAux;
      nodoAux = nodoAux->nodoSiguiente;
    }
   nodoAnt->nodoSiguiente = NULL;
   listaActual->dms--;
  }
  else
    return ;
}

void  elmnInt   ( lista * listaActual ){

  nodo *nodoAux = listaActual->cabeza;
  if ( listaActual->cabeza )
    listaActual->cabeza = listaActual->cabeza->nodoSiguiente;
  else
    return;

}

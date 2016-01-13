/******************************************************************************
    ********************** tipo nodo *********************************
*******************************************************************************/

# include <stdio.h>
# include <stdlib.h>

/******************************************************************************
    ******************** declaracion del tipo nodo ********************
*******************************************************************************/
typedef struct {

          void    * valorInterno ;
          int       numHijos;
          int       indice;
  struct  nodo    * nodoSiguiente;
  struct  nodo    * nodoPadre;
  struct  nodo    * nodosHijo;

}nodo;

nodo  *crearNodo (){

  nodo * nuevoNodo = (nodo*) malloc ( sizeof(nodo) );

  nuevoNodo->valorInterno = NULL;
  nuevoNodo->numHijos = 0;
  nuevoNodo->indice = 0;
  nuevoNodo->nodoSiguiente = NULL;
  nuevoNodo->nodoPadre = NULL;
  nuevoNodo->nodosHijo = NULL;

  return nuevoNodo;
}

/******************************************************************************
    ******************** declaracion del lista enlazada ********************
*******************************************************************************/

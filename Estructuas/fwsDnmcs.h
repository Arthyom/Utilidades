/* ###############################################################################
########### biblioteca de utilidades, reserva de memoria dinamica
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
    *********** memoria dinamica para vectores ****************
*******************************************************************************/
int     * dinVectorInt           ( int dimencionVector ){
  int i;

  /// reservar memoria
  int * memoriaDinamica = (int*) malloc ( sizeof(int) * dimencionVector );

  /// iniciar la memoria a 0
  for ( i = 0 ; i < dimencionVector ; i ++ )
      memoriaDinamica[i] = 0;

  return memoriaDinamica;
}

float   * dinVectorFloat         ( int dimencionVector ){
  int i;

  /// reservar memoria
  float * memoriaDinamica = (float*) malloc ( sizeof(float) * dimencionVector );

  /// iniciar la memoria a 0
  for ( i = 0 ; i < dimencionVector ; i ++ )
      memoriaDinamica[i] = 0.0;

  return memoriaDinamica;
}

double  * dinVectorDouble        ( int dimencionVector ){
  int i;

  /// reservar memoria
  double * memoriaDinamica = (double*) malloc ( sizeof(double) * dimencionVector );

  /// iniciar la memoria a 0
  for ( i = 0 ; i < dimencionVector ; i ++ )
      memoriaDinamica[i] = 0.0;

  return memoriaDinamica;
}

char    * dinVectorChar          ( int dimencionVector ){
  int i;

  /// reservar memoria
  char * memoriaDinamica = (char*) malloc ( sizeof(char) * dimencionVector );

  /// iniciar la memoria a 0
  for ( i = 0 ; i < dimencionVector ; i ++ )
      memoriaDinamica[i] = '0';

  return memoriaDinamica;
}

void    * dinVectorEstr          ( int dimencionVector){
  int i;

  void *contenedor = malloc ( sizeof(dimencionVector));

  return contenedor;
}

  /************** IMPRESION DE VECTORES ******************/
void      impVectorInt           ( int dmsVector, int   * vectorInt ){
  int i;

  for ( i = 0 ; i < dmsVector ; i ++ )
    printf("%d ",vectorInt[i] );

  printf("\n \n" );
}

void      impVectorFloat         ( int dmsVector, float * vectorFloat ){
  int i;

  for ( i = 0 ; i < dmsVector ; i ++ )
    printf("%f ",vectorFloat[i] );

  printf("\n \n" );
}

void      impVectorchar          ( int dmsVector, char  * vectorChar ){
  printf("%s \n \n ",vectorChar );
}

  /************** IMPRESION DE VECTORES ******************/
void      lbrVectorInt           ( int dmsVector, int      * vectorInt ){
  int i;
  for ( i = 0 ; i < dmsVector ; i ++ )
    free (&vectorInt[i]);
}

void      lbrVectorFloat         ( int dmsVector, float    * vectorFloat ){
  int i;
  for ( i = 0 ; i < dmsVector ; i ++ )
    free (&vectorFloat[i]);
}

void      lbrVectorDouble        ( int dmsVector, double   * vectorDouble ){
  int i;
  for ( i = 0 ; i < dmsVector ; i ++ )
    free (&vectorDouble[i]);
}

void      lbrVectorChar          ( int dmsVector, char     * vectorChar ){
  int i;
  for ( i = 0 ; i < dmsVector ; i ++ )
    free (&vectorChar[i]);
}

/******************************************************************************
    *********** memoria dinamica para matrices ****************
*******************************************************************************/
int     ** dinMatrixInt            ( int dimFilas, int dimColumnas){

  int i, j ;

  /// reservar espacio para la matriz de enteros
  int **mtrx = (int**) malloc ( sizeof (int*) * dimFilas );
  for ( i = 0 ; i < dimFilas ; i ++ )
    mtrx[i] = (int*) malloc ( sizeof(int) * dimColumnas );

  /// iniciar la matriz
  for ( i = 0 ; i < dimFilas ; i ++  )
    for ( j = 0 ; j < dimColumnas ; j ++ )
      mtrx[i][j] = 0;

  return mtrx;
}

float   ** dinMatrixFloat          ( int dimFilas, int dimColumnas){

  int i, j ;

  /// reservar espacio para la matriz de enteros
  float **mtrx = (float**) malloc ( sizeof (float*) * dimFilas );
  for ( i = 0 ; i < dimFilas ; i ++ )
    mtrx[i] = (float*) malloc ( sizeof(float) * dimColumnas );

  /// iniciar la matriz
  for ( i = 0 ; i < dimFilas ; i ++  )
    for ( j = 0 ; j < dimColumnas ; j ++ )
      mtrx[i][j] = 0.0;

  return mtrx;
}

double  ** dinMatrixDouble         ( int dimFilas, int dimColumnas){

  int i, j ;

  /// reservar espacio para la matriz de enteros
  double **mtrx = (double**) malloc ( sizeof (double*) * dimFilas );
  for ( i = 0 ; i < dimFilas ; i ++ )
    mtrx[i] = (double*) malloc ( sizeof(double) * dimColumnas );

  /// iniciar la matriz
  for ( i = 0 ; i < dimFilas ; i ++  )
    for ( j = 0 ; j < dimColumnas ; j ++ )
      mtrx[i][j] = 0.0;

  return mtrx;
}

char    ** dinMatrixChar           ( int dimFilas, int dimColumnas){

  int i, j ;

  /// reservar espacio para la matriz de enteros
  int **mtrx = (char**) malloc ( sizeof (char*) * dimFilas );
  for ( i = 0 ; i < dimFilas ; i ++ )
    mtrx[i] = (char*) malloc ( sizeof(char) * dimColumnas );

  /// iniciar la matriz
  for ( i = 0 ; i < dimFilas ; i ++  )
    for ( j = 0 ; j < dimColumnas ; j ++ )
      mtrx[i][j] = '0';

  return mtrx;
}

void    ** dinMatrixEstr           ( int dimFilas, int dimColumnas){
  int i, j ;

  void ** mtrx = malloc( sizeof(void*) * dimFilas );
  for ( i = 0 ; i < dimFilas ; i ++ )
    mtrx[i] = malloc ( sizeof(void) * dimColumnas);

    return mtrx;
}

/************** IMPRESION DE MATRICES ******************/
void       impMatrxInt             ( int dmsColumna, int dmsFilas, int    ** mtrx ){

  int i,j;

  for ( i = 0 ; i < dmsColumna ; i ++ ){
    printf(" \n");
    for ( j = 0 ; j < dmsColumna ; j ++ )
      printf("%d ",mtrx[i][j] );
  }

}

void       impMatrxDouble          ( int dmsColumna, int dmsFilas, double ** mtrx ){

  int i,j;

  for ( i = 0 ; i < dmsColumna ; i ++ ){
    printf(" \n" );
    for ( j = 0 ; j < dmsColumna ; j ++ )
      printf("%g ",mtrx[i][j] );
  }

}

void       impMatrxFloat           ( int dmsColumna, int dmsFilas, float  ** mtrx ){

  int i,j;

  for ( i = 0 ; i < dmsColumna ; i ++ ){
    printf(" \n" );
    for ( j = 0 ; j < dmsColumna ; j ++ )
      printf("%f ",mtrx[i][j] );
  }

}

void       impMatrxChar            ( int dmsColumna, int dmsFilas, char   ** mtrx ){

  int i,j;

  for ( i = 0 ; i < dmsColumna ; i ++ ){
    printf(" \n");
    for ( j = 0 ; j < dmsColumna ; j ++ )
      printf("%c ",mtrx[i][j] );
  }

}

#include "FwsVision.h"

int main(void)
{
    printf(" \"hola\" ");
    // cargar imagenes

      /* hacer otras cosas */
        contenedorBmp* entradaBmp = cargarImagenBmp("C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/02.bmp","02.bmp" );

        // guadar imagenes
     contenedorBmp * salidaBmp  = guardarImagenBmp(entradaBmp,"C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/02s.bmp","02s.bmp");

     mostrarImagenes(entradaBmp, salidaBmp, "C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/muestra.html" );
      /* verificar si ya pasó un segundo */

printf("-------->");
   //imprimirMatriz(*entradaBmp);


}


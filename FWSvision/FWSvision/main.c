#include "FwsVision.h"

int main(void)
{

      // cargar imagen
    //  contenedorBmp* entradaBmp = FwsVcargarImagenBmpColor("C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/rd.bmp","rd.bmp" );

     // guadar imagenes
   //  contenedorBmp * salidaBmp  = FwsVguardarImagenBmpColor(entradaBmp,"C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/rd.bmp","rds.bmp");

     // mostrar imagenes
   //  FwsVmostrarImagenes('@',entradaBmp, salidaBmp, "C:/Users/frodo/Documents/herramientas/Utilidades/FWSvision/FWSvision/htmlView.html" );

    contenedorBmp * vectorContendores = FwsVcargarImagenesBmpColor(3,"rutas","nombre1","nombre2","nombre3");

       FwsVimprmrRutas(vectorContendores,3);
    return 0;

}


#ifndef FWSVISION_H
#define FWSVISION_H

    /**************************************************************************************/
    /*********                                                                  ***********/
    /*********          conjunto de utilidades para vision computacional        ***********/
    /*********                                                                  ***********/
    /**************************************************************************************/

    # include <stdio.h>
    # include <stdlib.h>
    # include <stdarg.h>
    # include <math.h>

        /******************************************/
        /******** contenedor imagen BmP   *********/
        /******************************************/

        typedef struct {

            /****** cabecera de la imagen ********/

            FILE *      nombreRuta;     // ruta o nombre de la imagen
            int         vectorDims;     // dimenciones para un vector de imagenes BMP

            char *      imagenTipo;     // tipo de imagen BMP, JPEG etc
            int         imagenDims;     // tamanio de la imagen en bytes
            int         imagenResrv;
            int         imagenOffst;    // despalazamiento hasta los datos
            int         imagenDmsMt;    // dimenciones en bytes de los metadatos

            int         imagenAlto;
            int         imagenAncho;

            int         imagenNmPlns;   // numero de planos
            int         imagenPrfClr;   // profundidad de color

            int         imagenTpCmp;    // tipo de comprencion
            int         imagenDEstr;    // dimenciones en bytes de la estructura imagen
            int         imagenPxMH;     // pixeles por metro horizontal
            int         imagenPxMV;     // pixeles por metro vertical
            int         imagenClrUs;    // cantidad de colores usados
            int         imagenClrImp;   // cantidad de colores importantes
            char **     imagenMtrzPxl;  // matriz de pixeles para la imagen





        }contenedorBmp;

        /******************************************/
        /******** prototips y declaracion *********/
        /******************************************/
        // FUNCIONES MISELANEAS
        contenedorBmp *     crearContenedor           ( ){

            // crear un nuevo contnedor
            contenedorBmp * nuevoContenedor = ( contenedorBmp * ) malloc ( sizeof(contenedorBmp));

            // iniciar propiedades a valores conocidos
            nuevoContenedor->nombreRuta = ' ';
            nuevoContenedor->vectorDims = 0;

            return nuevoContenedor;


        }

        // FUNCIONES DE CARGAR DE IMAGENES BMP
        contenedorBmp *     cargarImagenBmp          ( char * nombreImagen ){

            // intentar cargar ruta especificada
            FILE * nuevaImagenBmp = fopen( nombreImagen, "rb+");
            if (  nuevaImagenBMP ){

                // crear contenedor para la nueva imagen
                contenedorBmp * nuevoContenedor = crearContenedor();

                // leer datos extra
                nuevoContenedor->nombreRuta = nombreImagen;


                // leer imagen BMP
                fread(&nuevoContenedor->imagenTipo, sizeof(char),2,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenDims, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenResrv, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenOffst, sizeof(int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenDmsMt, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenAlto, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenAncho, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenNmPlns, sizeof(int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenPrfClr, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenTpCmp, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenDEstr, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenPxMH, sizeof(int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenPxMV, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenClrUs, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenClrImp, sizeof(int),1,nuevaImagenBmp);

                // pasar l


            }
            else
                return NULL;
        }

        contenedorBmp *    cargarImagenesBmp        ( char * nombreImagenes, int dims );



        // FUNIONES DE ESCITURA DE IMAGENES BMP
        int       guardarImagenBmp          ( );
        int       guardarImagenesBmp()      ( );



#endif // FWSVISION_H

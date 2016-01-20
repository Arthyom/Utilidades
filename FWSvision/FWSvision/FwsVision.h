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

            char *      nombreRuta;     // ruta o nombre de la imagen
            int         vectorDims;     // dimenciones para un vector de imagenes BMP
            char        nmbrRtSv;       // ruta o nombre de guardado

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

        char **             crearMatriz               ( int dimsX, int dimsY ){

            // reservar una nueva matriz
            char ** matriz = (char**) malloc(sizeof(char*) * dimsX);
            int i,j;
            for ( i = 0 ; i < dimsX ; i ++ )
                matriz[i] = (char*) malloc (sizeof(char) * dimsY);

            // iniciar la matriz a algo conocido
            for ( i = 0 ; i < dimsX ; i ++ )
                for ( j = 0 ; j < dimsY ; j ++ )
                    matriz[i][j] = '0';

            return matriz;

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

                // pasar de la imagen a la matriz del contenedor
                char ** nuevaMatriz = crearMatriz(nuevoContenedor->imagenAlto, nuevoContenedor->imagenAncho);

                int i, j ;
                char r,g,b;
                for ( i = 0 ; i < nuevoContenedor->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < nuevoContenedor->imagenAncho ; j ++ )
                    {
                        fread(&b,sizeof(char),1,nuevaImagenBmp);
                        fread(&g,sizeof(char),1,nuevaImagenBmp);
                        fread(&r,sizeof(char),1,nuevaImagenBmp);

                        nuevoContenedor->imagenMtrzPxl[i][j] = r+g+b / 3;

                    }
                }

                // cerrar el archivo y regresar la imagen ya cargada
                fclose(nuevaImagenBmp);
                return nuevoContenedor;



            }
            else
                return NULL;
        }

        contenedorBmp *    cargarImagenesBmp         ( char * nombreImagenes, int dims );



        // FUNIONES DE ESCITURA DE IMAGENES BMP
        int       guardarImagenBmp          ( contenedorBmp * bmpEntrada, char * nombreSalida ){

            // crear el nuevo archivo
            FILE * nuevaImagenSalida = fopen( nombreSalida, "wb+");

            // verificar si se ha podifo salvar la imagen
            if ( nuevaImagenSalida ){

                // crear contenedor para la imagen de salida
                contenedorBmp * nuevoContenedorSalida = crearContenedor();

                // leer la imagen indicada
                fwrite(&nuevoContenedorSalida->imagenTipo,sizeof(char),2,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenDims,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenResrv,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenOffst,sizeof(int),1,nuevaImagenSalida);

                fwrite(&nuevoContenedorSalida->imagenMtrzPxl ,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenAlto,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenAncho,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenNmPlns,sizeof(int),1,nuevaImagenSalida);

                fwrite(&nuevoContenedorSalida->imagenPrfClr,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenTpCmp,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenDEstr,sizeof(int),1,nuevaImagenSalida);

                fwrite(&nuevoContenedorSalida->imagenPxMH,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenPxMV,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenClrUs,sizeof(int),1,nuevaImagenSalida);
                fwrite(&nuevoContenedorSalida->imagenClrImp,sizeof(int),1,nuevaImagenSalida);

                // mover la matriz del contenedor de entrada al contenedor de salida
                int i, j ;

                for ( i = 0 ; i < bmpEntrada->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < bmpEntrada->imagenAncho ; j ++ )
                    {
                        fwrite(&nuevoContenedorSalida->imagenMtrzPxl[i][j],sizeof(char),1,nuevaImagenSalida);
                        fwrite(&nuevoContenedorSalida->imagenMtrzPxl[i][j],sizeof(char),1,nuevaImagenSalida);
                        fwrite(&nuevoContenedorSalida->imagenMtrzPxl[i][j],sizeof(char),1,nuevaImagenSalida);
                    }
                }

                // cerrar el archivo y regresar estado
                fclose(nuevaImagenSalida);
                return 0;
            }
            else
                return 1;
        }

        int       guardarImagenesBmp()      ( );



#endif // FWSVISION_H

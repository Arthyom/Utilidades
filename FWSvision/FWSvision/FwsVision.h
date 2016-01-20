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
    # include <time.h>

        /******************************************/
        /******** contenedor imagen BmP   *********/
        /******************************************/

        typedef struct {

            /****** cabecera de la imagen ********/

            char *      nombreRuta;     // ruta o nombre de la imagen
            char *      nombreImagen;   //
            int         vectorDims;     // dimenciones para un vector de imagenes BMP
            char        nmbrRtSv;       // ruta o nombre de guardado

            char        imagenTipo [2];     // tipo de imagen BMP, JPEG etc
            int         imagenDims;     // tamanio de la imagen en bytes
            int         imagenResrv;
            int         imagenOffst;    // despalazamiento hasta los datos
            int         imagenDmsMt;    // dimenciones en bytes de los metadatos

            int         imagenAlto;
            int         imagenAncho;

            short int   imagenNmPlns;   // numero de planos
            short int   imagenPrfClr;   // profundidad de color

            int         imagenTpCmp;    // tipo de comprencion
            int         imagenDEstr;    // dimenciones en bytes de la estructura imagen
            int         imagenPxMH;     // pixeles por metro horizontal
            int         imagenPxMV;     // pixeles por metro vertical
            int         imagenClrUs;    // cantidad de colores usados
            int         imagenClrImp;   // cantidad de colores importantes
            unsigned char **     imagenMtrzPxlR;  // matriz de pixeles para la imagen
            unsigned char **     imagenMtrzPxlG;  // matriz de pixeles para la imagen
            unsigned char **     imagenMtrzPxlB;  // matriz de pixeles para la imagen

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

        void                mostrarImagenes           ( contenedorBmp * contenedorEntrada, contenedorBmp * conentenedorSalida, char *nombreDestino ){

            // crear archivo html para incrustar las imagenes creadas
            FILE * archivo = fopen(nombreDestino,"w");
            char html [] = "<!DOCTYPE html><html><head><title> muestra de imagenes </title></head><boy><div><img src = \"%s \"> entrada<br><img src= \" %s \"> salida</div></body></html>";

            fprintf(archivo,html,contenedorEntrada->nombreImagen, conentenedorSalida->nombreImagen);
            fclose(archivo);
            system(nombreDestino);






        }

        void                esperar                   ( int retardo ){

            while (1) {

            clock_t tInicio, tFinal;
            int segun = 0;

            tInicio = clock() + CLOCKS_PER_SEC;

                printf("%d", ++segun);
                tFinal = tInicio + CLOCKS_PER_SEC;

            }

        }

        // FUNCIONES DE CARGAR DE IMAGENES BMP
        contenedorBmp *     cargarImagenBmp          ( char * nombreImagen,char * nombreImagene ){

            // intentar cargar ruta especificada
            FILE * nuevaImagenBmp = fopen( nombreImagen, "rb+");
            if (  nuevaImagenBmp ){

                // crear contenedor para la nueva imagen
                contenedorBmp * nuevoContenedor = crearContenedor();

                // leer datos extra
                nuevoContenedor->nombreRuta = nombreImagen;
                nuevoContenedor->nombreImagen = nombreImagene;


                // leer imagen BMP
                fseek(nuevaImagenBmp,0,SEEK_SET);
                fread(&nuevoContenedor->imagenTipo, sizeof(char),2,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenDims, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenResrv, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenOffst, sizeof(int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenDmsMt, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenAlto, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenAncho, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenNmPlns, sizeof(short int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenPrfClr, sizeof(short int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenTpCmp, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenDEstr, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenPxMH, sizeof(int),1,nuevaImagenBmp);

                fread(&nuevoContenedor->imagenPxMV, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenClrUs, sizeof(int),1,nuevaImagenBmp);
                fread(&nuevoContenedor->imagenClrImp, sizeof(int),1,nuevaImagenBmp);
                //if(nuevoContenedor->imagenPrfClr != 24 )
                  //  exit(1);

                // pasar de la imagen a la matriz del contenedor
                int i,j;

                /********** codigo peligroso ************/
                nuevoContenedor->imagenMtrzPxlB = (char **) malloc(sizeof(char**)* nuevoContenedor->imagenAlto);
                for (i=0; i<nuevoContenedor->imagenAlto;i++)
                    nuevoContenedor->imagenMtrzPxlB[i] =(char*) malloc(sizeof(char)*nuevoContenedor->imagenAncho);

                nuevoContenedor->imagenMtrzPxlR = (char **) malloc(sizeof(char**)* nuevoContenedor->imagenAlto);
                for (i=0; i<nuevoContenedor->imagenAlto;i++)
                    nuevoContenedor->imagenMtrzPxlR[i] =(char*) malloc(sizeof(char)*nuevoContenedor->imagenAncho);

                nuevoContenedor->imagenMtrzPxlG = (char **) malloc(sizeof(char**)* nuevoContenedor->imagenAlto);
                for (i=0; i<nuevoContenedor->imagenAlto;i++)
                    nuevoContenedor->imagenMtrzPxlG[i] =(char*) malloc(sizeof(char)*nuevoContenedor->imagenAncho);


                char r,g,b;
                for ( i = 0 ; i < nuevoContenedor->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < nuevoContenedor->imagenAncho ; j ++ )
                    {
                        fread(&r,sizeof(char),1,nuevaImagenBmp);


                        nuevoContenedor->imagenMtrzPxlR[i][j] = r;
                      //  nuevoContenedor->imagenMtrzPxl[i][j] = (b+g+r)/3;

                    }
                }

                for ( i = 0 ; i < nuevoContenedor->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < nuevoContenedor->imagenAncho ; j ++ )
                    {
                        fread(&r,sizeof(char),1,nuevaImagenBmp);


                        nuevoContenedor->imagenMtrzPxlB[i][j] = r;
                      //  nuevoContenedor->imagenMtrzPxl[i][j] = (b+g+r)/3;

                    }
                }

                for ( i = 0 ; i < nuevoContenedor->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < nuevoContenedor->imagenAncho ; j ++ )
                    {
                        fread(&r,sizeof(char),1,nuevaImagenBmp);


                        nuevoContenedor->imagenMtrzPxlG[i][j] = r;
                      //  nuevoContenedor->imagenMtrzPxl[i][j] = (b+g+r)/3;

                    }
                }

                /******************* codigo peligroso *********************/

                // cerrar el archivo y regresar la imagen ya cargada
                fclose(nuevaImagenBmp);
                return nuevoContenedor;



            }
            else
                return NULL;
        }

        contenedorBmp *    cargarImagenesBmp         ( char * nombreImagenes, int dims );



        // FUNIONES DE ESCITURA DE IMAGENES BMP
        contenedorBmp *      guardarImagenBmp          ( contenedorBmp * bmpEntrada, char * nombreSalida, char *nombreImagens ){

            // crear el nuevo archivo
            FILE * nuevaImagenSalida = fopen( nombreSalida, "wb+");

            // verificar si se ha podifo salvar la imagen
            if ( nuevaImagenSalida ){

                // crear contenedor para la imagen de salida
                contenedorBmp * nuevoContenedorSalida = crearContenedor();
                nuevoContenedorSalida->nombreRuta   = nombreSalida;
                nuevoContenedorSalida->nombreImagen = nombreImagens;

                // leer la imagen indicada
                fseek(nuevaImagenSalida,0,SEEK_SET);
                fwrite(&bmpEntrada->imagenTipo,sizeof(char),2,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenDims,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenResrv,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenOffst,sizeof(int),1,nuevaImagenSalida);

                fwrite(&bmpEntrada->imagenDmsMt ,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenAlto,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenAncho,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenNmPlns,sizeof(short int),1,nuevaImagenSalida);

                fwrite(&bmpEntrada->imagenPrfClr,sizeof(short int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenTpCmp,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenDEstr,sizeof(int),1,nuevaImagenSalida);

                fwrite(&bmpEntrada->imagenPxMH,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenPxMV,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenClrUs,sizeof(int),1,nuevaImagenSalida);
                fwrite(&bmpEntrada->imagenClrImp,sizeof(int),1,nuevaImagenSalida);

                // mover la matriz del contenedor de entrada al contenedor de salida
                int i, j ;



                for ( i = 0 ; i < bmpEntrada->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < bmpEntrada->imagenAncho ; j ++ )
                    {
                        fwrite(&bmpEntrada->imagenMtrzPxlB[i][j],sizeof(char),1,nuevaImagenSalida);

                    }
                }

                for ( i = 0 ; i < bmpEntrada->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < bmpEntrada->imagenAncho ; j ++ )
                    {
                        fwrite(&bmpEntrada->imagenMtrzPxlG[i][j],sizeof(char),1,nuevaImagenSalida);

                    }
                }

                for ( i = 0 ; i < bmpEntrada->imagenAlto ; i ++ )
                {
                    for ( j = 0 ; j < bmpEntrada->imagenAncho ; j ++ )
                    {
                        fwrite(&bmpEntrada->imagenMtrzPxlR[i][j],sizeof(char),1,nuevaImagenSalida);

                    }
                }


                // cerrar el archivo y regresar estado
                fclose(nuevaImagenSalida);
                return nuevoContenedorSalida;
            }
            else
                return NULL;
        }

       // int       guardarImagenesBmp()      ( );



#endif // FWSVISION_H

///Matias Jesus Caballero - Com. 1
#ifndef ARCHIEXTRA_H_INCLUDED
#define ARCHIEXTRA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idPelicula;
    char nombrePelicula[30];
    char director[20];
    char genero[20];
    char pais[20];
    int anio;
    int valoracion;
    int pm; // (0- si es ATP / 13: mayor de trece /16: mayor de 16 / 18: mayor de 18
    int eliminado; // indica 1 o 0 si la película fue eliminada

} stPelicula;

///onst int LIMITE = 100;
///const int DIM_PAL = 30;

///Prototipados de las funciones:
int main();
void menuDePeliculas();

///Funcion de carga (alta):
int cargaPelicula (stPelicula arr[], int validos);

void mostrarPelisCargadas(stPelicula arrPeli[], int validos);

void mostrarUnaPelicula (stPelicula p);

int verificarSiExiste (char nombreArchivoActual[], char nombreBuscado[30]);


#endif // ARCHIEXTRA_H_INCLUDED

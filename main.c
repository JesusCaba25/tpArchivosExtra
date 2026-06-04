///Matias Jesus Caballero - Com. 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIEXTRA_H_INCLUDED

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

//const int LIMITE = 100;


///funcion MAIN:
int main()
{
    menuDePeliculas();
    return 0;
}

///Funcion del menú:
void menuDePeliculas()
{
    int opcion;

    stPelicula arrPelis[100];
    int validos = 0;

    do
    {

        printf("\n\nBIENVENIDO!\n");
        printf("1 - ALTA.\n");
        printf("2 - BAJA.\n");
        printf("3 - MODIFICACION.\n");
        printf("4 - CONSULTA.\n");
        printf("5 - LISTADOS.\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        {
            FILE* archivo = fopen ("archivoPelicula", "rb");

            validos = cargaPelicula (archivo, arrPelis , validos);

            printf("\nPeliculas cargadas: %d \n", validos);

            fclose(archivo);
        }
        break;

        case 2:
        {
            mostrarPelisCargadas(arrPelis, validos);

        }
        break;

        case 3:
        {

        }
        break;

        case 4:
        {

        }
        break;

        case 5:
        {

        }
        break;

        default:
            printf("Opcion invalida\n");
        }
    }
    while (opcion != 0);

}

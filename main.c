///Matias Jesus Caballero - Com. 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIEXTRA_H_INCLUDED

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

    stPelicula arrPelis[LIMITE];
    int validos = 0;

    do
    {

        printf("\n\nBIENVENIDO!\n");
        printf("1 - Funcion de carga de peliculas (alta)\n");
        printf("2 - \n");
        printf("3 - \n");
        printf("4 - \n");
        printf("5 - \n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        {
            validos = cargaPelicula ( arrPelis , validos);

            printf("\nPeliculas cargadas: %d \n", validos);
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

#define ARCHIEXTRA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Funcion de carga (alta):
int cargaPelicula (stPelicula arr[], int validos)
{
    int i = validos;
    char control = 's';

    FILE* archivo = fopen ("archivoPelicula", "ab"); ///agrega datos al final asi ("ab")

    if (archivo != NULL)
    {
        do
        {
            printf("\n--- Nueva pelicula: ---\n");

            arr[i].idPelicula = i + 1;
            printf("\nIdentificador de la pelicula: %d", arr[i].idPelicula);

            getchar();

            printf("\nIngrese el nombre de la PELICULA: ");
            gets (arr[i].nombrePelicula);

            printf("\nIngrese el NOMBRE del DIRECTOR: ");
            gets (arr[i].director);

            printf("\nIngrese el GENERO de la pelicula: ");
            gets (arr[i].genero);

            printf("\nIngrese el PAIS de la pelicula: ");
            gets (arr[i].pais);

            printf("\nIngrese el anio de ESTRENO: ");
            scanf ("%d", &arr[i].anio);

            printf("\nIngrese su VALORACION (1 al 10): ");
            scanf ("%d", &arr[i].valoracion);

            printf("\nIngrese su PUBLICO APTO (0: ATP / 13: +13 / 16: +16 / 18: +18): ");
            scanf ("%d", &arr[i].pm);

            arr[i].eliminado = 0; //arranca en 0 pq no va a ser eliminada.

            fwrite (&arr[i], sizeof(stPelicula), 1, archivo);
            i++;

            printf("\nDesea cargar otra pelicula? (s/n): ");
            scanf (" %c", &control);
        } while(control != 'n' && control != 'N');

        fclose (archivo);
    }
    else
    {
        printf("\nError al abrir el archivo.");
    }

    return i;
}

void mostrarUnaPelicula (stPelicula p)
{
    printf("\n---------------------------------------\n");
    printf("\nIdentificador de la pelicula: %d", p.idPelicula);
    printf("\nNombre de la PELICULA: %s", p.nombrePelicula );
    printf("\nNOMBRE del DIRECTOR: %s", p.director);
    printf("\nGENERO de la pelicula: %s", p.genero);
    printf("\nPAIS de la pelicula: %s", p.pais);
    printf("\nESTRENO: %d", p.anio);
    printf("\nVALORACION: %d", p.valoracion);
    printf("\nPUBLICO APTO: %d", p.pm);
    printf("\n---------------------------------------\n");
}

void mostrarPelisCargadas(stPelicula arrPeli[], int validos)
{
    FILE* archivo = fopen ("archivoPelicula", "rb");

    if(archivo != NULL)
    {
        stPelicula peliAux;

        printf("\n--- Listado de peliculas en el archivo ---\n");

        while(fread (&peliAux, sizeof (stPelicula), 1, archivo) > 0)
        {
            if (peliAux.eliminado == 0)
            {
                mostrarUnaPelicula(peliAux);
            }
        }

        fclose(archivo);

    }
    else
    {
        printf("Error al abrir el archivo.");
    }

}

///funcion para cargar una mas al final, si el usuario asi lo desea.


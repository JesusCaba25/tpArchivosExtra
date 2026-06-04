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

//const int LIMITE = 100;
//const int DIM_PAL = 30;


///Funcion de carga (alta):

int verificarSiExiste (char nombreArchivoActual[], char nombreBuscado[30])
{
    FILE* archivo = fopen ("archivoPelicula", "rb");
    int respuesta = 0;
    int i = 0;
    stPelicula aux;

    if(archivo != NULL)
    {
        while (fread(&aux, sizeof(stPelicula), 1, archivo) > 0)
        {
            if (strcmp (nombreArchivoActual, nombreBuscado) == 0)
            {
                respuesta = 1;
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("No existe el archivo.");
    }

    return respuesta;
}

int cargaPelicula (stPelicula arr[], int validos)
{
    int i = validos;
    char control = 's';
    int rta = 0;

    FILE* archivo = fopen ("archivoPelicula", "wb"); ///agrega datos al final asi ("ab")

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

            rta = verificarSiExiste (archivo, arr[i].nombrePelicula );

            while (rta != 0)
            {
                if (rta == 1)
                {
                    printf("\nLa pelicula ya existe. Por favor, intente otra vez: \n");

                    printf("\nIngrese el nombre de la PELICULA: ");
                    gets (arr[i].nombrePelicula);

                    rta = verificarSiExiste (archivo, arr[i].nombrePelicula );
                }
                else
                {
                    ///seguir...
                }
            }

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





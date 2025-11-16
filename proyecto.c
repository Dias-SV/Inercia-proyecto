#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inercia.h"

#define cantidad 50

/*void leerArchivo(const char *nombreArchivo) ;
void escribirArchivo(const char *nombreArchivo, const char *texto) ;
void sobrescribirArchivo(const char *nombreArchivo, const char *nuevoTexto) ;
*/


int main()
{
    
    int opcion;
    
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Mostrar muestras\n");
        printf("2. Nueva muestra\n");
        printf("3. Cambiar muestra\n");
        printf("4. Borrar muestra\n");
        printf("5. Salir\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        mostrar();
        break;
    
    case 5:
        printf("Saliendo del programa.\n");
        break;

    default:
        printf("Opcion invalida.\n");
        break;
    }
    } while (opcion != 5);
}


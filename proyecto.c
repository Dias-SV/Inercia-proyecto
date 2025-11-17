#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inercia.h"

#define cantidad 50

/*void leerArchivo(const char *nombreArchivo) ;
void sobrescribirArchivo(const char *nombreArchivo, const char *nuevoTexto) ;
*/

int main()
{
    int opcion;
    char texto[100];
    char textoNuevo[100];
    
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
        getchar();

    switch (opcion)
    {
    case 1:
        mostrar();
        break;

    case 2:
        printf("Ingrese el nombre de la muestra nueva: ");
        fgets(texto, sizeof(texto), stdin);
        texto[strcspn(texto, "\n")] = '\0';
        //Aqui va el procedimiento de la inercia
        nuevaMuestra(texto, 0.0);
        break;
        
    case 3:
        printf("Ingrese el nombre de la muestra: ");
        fgets(texto, sizeof(texto), stdin);
        texto[strcspn(texto, "\n")] = '\0';
        printf("Ingrese el nuevo nombre de la muestra: ");
        fgets(textoNuevo, sizeof(textoNuevo), stdin);
        textoNuevo[strcspn(textoNuevo, "\n")] = '\0';
        cambiarMuestra(texto, textoNuevo);
        break;
    
    case 4:
        printf("Ingrese el nombre de la muestra a borrar: ");
        fgets(texto, sizeof(texto), stdin);
        texto[strcspn(texto, "\n")] = '\0';
        borrarMuestra(texto);
        break;

    case 5:
        printf("Saliendo del programa.\n");
        break;

    default:
        printf("Opcion invalida.\n");
        break;
    }
    } while (opcion != 5);

    return 0;
}


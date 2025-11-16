#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inercia.h"

#define cantidad 50

void mostrar()
{   
    char linea[1000];
    char *campo;
    int i = 0;
    int j = 0;
    datos datos[cantidad];
    FILE *archivo = fopen("curvas.csv", "r"); // Abriren modo lectura
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura.\n");
        return;
    }

    while (fgets(linea, 1000, archivo) != NULL)
    {
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);
        i++;
    }
    
    fclose(archivo);

    if(i != 0)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d. %s, Inercia: %f\n", j+1, datos[j].nombre, datos[j].inercia);
        }
    }
    else
    {
        printf("No se tienen muestras registradas");
    }
}
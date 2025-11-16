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

    fclose(archivo);
}

void cambiarMuestra(const char *texto, const char *reemplazo)
{   
    char linea[1000];
    char *campo;
    int i = 0;
    int j = 0;
    datos datos[cantidad];

    FILE *archivo = fopen("curvas.csv", "r"); // Abrir en modo agregar
    FILE *temporal = fopen("temp.csv", "w");
    if (archivo == NULL || temporal == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    while (fgets(linea, 1000, archivo) != NULL)
    {
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        if (strcmp(datos[i].nombre, texto) == 0)
        {
            strcpy(datos[i].nombre, reemplazo);
        }
        fprintf(temporal, "%s,%f\n", datos[i].nombre, datos[i].inercia);
        i++;
    }
    
    fclose(archivo);
    fclose(temporal);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inercia.h"

#define Maximo 1000
#define Cantidad 50
char linea[Maximo];
char *campo;

void mostrar()
{   
    int i = 0;
    int j = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura.\n");
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL)
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

void nuevaMuestra(const char *texto, float inercia)
{   
    int i = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "a+");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL)
    {
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        if (strcmp(datos[i].nombre, texto) == 0)
        {
            printf("La muestra %s ya esta registrada, si decea cambiarla use la opcion 3\n", texto);
            fclose(archivo);
            return;
        }
        
        i++;
    }

    fprintf(archivo, "%s,%f", texto, inercia);
    fclose(archivo);

}

void cambiarMuestra(const char *texto, const char *reemplazo)
{   
    int i = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r");
    FILE *temporal = fopen("temp.csv", "w");
    if (archivo == NULL || temporal == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL)
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

    remove("curvas.csv");
    rename("temp.csv", "curvas.csv");
}




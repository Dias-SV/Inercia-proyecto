#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escritura.h"

#define Maximo 1000 //Cantidad de lineas maximas
#define Cantidad 200 //Cantidad de datos maximos
//Variables usadas en todos los prcoedimientos
char linea[Maximo];
char *campo;

//Enseñar muestras en pantalla
void mostrar()
{   
    int i = 0;
    int j = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r"); //Abrir en modo lectura
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo para lectura.\n");
        printf("Para registrar nuevas muestras use la opcion 2.\n");
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL && i<Cantidad)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);
        i++;
    }
    
    fclose(archivo);
    ///Muestra en pantalla
    if(i != 0) //Verifica que se hayan encontrado muestras
    {
        printf("Muestras:\n");
        for (j = 0; j < i; j++)
        {
            printf("%d. Nombre: %s, Inercia: %f\n", j+1, datos[j].nombre, datos[j].inercia);
        }
    }
    else
    {
        printf("No se tienen muestras registradas.\n");
        printf("Para registrar nuevas muestras use la opcion 2.\n");
    }
}


//Ingresar una nueva muestra
void nuevaMuestra(const char *texto, float inercia)
{   
    int i = 0, r=0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "a+"); //Abrir en modo agregar y lee al principio del archivo
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }
    
    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        //Verificacion de que la muestra no este registrada
        if (strcmp(datos[i].nombre, texto) == 0)
        {
            printf("\n------El nombre %s ya esta registrado.------\n", texto);
            printf("Para cambiar muestras use la opcion 3.\n");
            fclose(archivo);
            return; //Si esta registrada termina
        }
        else
        {
            r = 1;
        }
        i++;
    }
    fprintf(archivo, "\n%s,%f", texto, inercia);//Escritura al archivo de los datos
    fclose(archivo);
    //Mostrar que se hizo
    if(r == 1)
    {
        printf("Muestra agregada con exito.\n");
    }
}


//Cambia nombre a una muestra ya registrada
void cambiarMuestra(int numero, const char *reemplazo)
{   
    int i = 0, r = 0, j=0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r");//Abrir archivo principal en modo lectura
    FILE *temporal = fopen("temp.csv", "w");//Crea y abrir archivo temporal en modo escritura
    if (archivo == NULL || temporal == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        printf("Para registrar nuevas muestras use la opcion 2.\n");
        fclose(temporal);
        remove("temp.csv"); //Si no se puede abrir uno de estos archivos se borra el temporal
        return;
    }

    //Validacion de que se puede poner la muestra
    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        //Busqueda del nombre de la muestra ingresado
        if (strcmp(datos[i].nombre, reemplazo) == 0)
        {
            fclose(archivo);
            fclose(temporal);
            remove("temp.csv"); //Se quita el archivo temporal 
            printf("\n------El nombre %s ya esta registrado.------\n", reemplazo);
            printf("Para consultar las muestras registradas usa la opcion 1.\n");
            return;
        }
        i++;
    }
    
    rewind(archivo); //Regresa para volver a leer el archivo
    i=0;
    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        //Busqueda del numero de la muestra ingresado
        if (i == (numero-1))
        {
            strcpy(datos[i].nombre, reemplazo); //Si se encuentra el nombre de muestra se reemplaza
        }
        fprintf(temporal, "%s,%f\n", datos[i].nombre, datos[i].inercia);
        i++;
    }
    
    fclose(archivo);
    fclose(temporal);
    remove("curvas.csv");
    rename("temp.csv", "curvas.csv"); //El archivo temporal se vuelve el nuevo archivo principal

    printf("Nombre cambiado con exito.\n");
}


//Cambia valor de inercia a una muestra ya registrada
void cambiarInercia(int numero, float reemplazo)
{   
    int i = 0, r = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r");//Abrir archivo principal en modo lectura
    FILE *temporal = fopen("temp.csv", "w");//Crea y abir archivo temporal en modo escritura
    if (archivo == NULL || temporal == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        printf("Para registrar nuevas muestras use la opcion 2.\n");
        fclose(temporal);
        remove("temp.csv"); //Si no se puede abrir uno de estos archivos se borra el temporal
        return;
    }
    
    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        //Busqueda del nombre de la muestra ingresado
        if (i == (numero-1))
        {
            datos[i].inercia = reemplazo; //Si se encuentra numero de muestra se reemplaza
            r = 1;
        }
        fprintf(temporal, "%s,%f\n", datos[i].nombre, datos[i].inercia);
        i++;
    }
    
    fclose(archivo);
    fclose(temporal);
    remove("curvas.csv");
    rename("temp.csv", "curvas.csv"); //El archivo temporal se vuelve el nuevo archivo principal
    //Mostrar que se hizo
    if(r == 0)
    {
        printf("No hay una muestra con este numero.\n");
        printf("Para consultar las muestras disponibles usa la opcion 1.\n");
    }
    else
    {
        printf("Inercia cambiada con exito.\n");
    }
}


void borrarMuestra(int numero)
{   
    int i = 0, r = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r"); //Abre archivo principal en modo lectura
    FILE *temporal = fopen("temp.csv", "w"); //Crea y abrir archivo temporal en modo escritura
    if (archivo == NULL || temporal == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        printf("Para registrar nuevas muestras use la opcion 2.\n");
        fclose(temporal);
        remove("temp.csv"); //Si no se puede abrir uno de estos archivos se borra el temporal
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

         //Busqueda del nombre de la muestra ingresado
        if (i != (numero-1))
        {
            fprintf(temporal, "%s,%f\n", datos[i].nombre, datos[i].inercia);
            //Si en la iteracion no se encuentra se escriben los demas datos al archivo temporal
        }
        else
        {
            r=1;
            //Si se ecnuentra no la escribe al archivo temporal
        }
        i++;
    }

    fclose(archivo);
    fclose(temporal);
    remove("curvas.csv");
    rename("temp.csv", "curvas.csv"); //El archivo temporal se vuelve el nuevo archivo principal
    //Mostrar que se hizo
    if(r == 0)
    {
        printf("No se encontro ninguna muestra con este nombre.\n");
        printf("Para consultar las muestras disponibles usa la opcion 1.\n");
    }
    else
    {
        printf("Muestra borrada con exito.\n");
    }
}


void buscarMuestra(const char *texto)    
{   
    int i = 0, r = 0;
    base datos[Cantidad];

    FILE *archivo = fopen("curvas.csv", "r");//Abrir archivo principal en modo lectura
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fgets(linea, Maximo, archivo) != NULL)
    {
        //Lectura del campo nombre
        campo = strtok(linea, ",");
        strcpy(datos[i].nombre, campo);
        //Lectura del campo inercia
        campo = strtok(NULL, ",");
        datos[i].inercia = atof(campo);

        //Busqueda del nombre de la muestra ingresado
        if (strcmp(datos[i].nombre, texto) == 0)
        {
            printf("\nMuestra:\n");
            printf("%d. Nombre: %s, Inercia: %f\n", i+1, datos[i].nombre, datos[i].inercia);
            r = 1;
        }

        i++;
    }
    fclose(archivo);
    //Mostrar que se hizo
    if(r == 0)
    {
        printf("No se encontro ninguna muestra con este nombre.\n");
        printf("Para consultar las muestras disponibles usa la opcion 1.\n");
    }
}


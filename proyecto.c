#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escritura.h" //Libreria para escribri a archivo csv
#include "potencia.h" //Libreria con los calculos

int invalido(const char *s);
int confirmacion();

int main()
{
    int opcionM=0, opcionE=0, numeroM=0; //Opciones del menu
    float valorC=0, valor=0; //Calor y almacenamiento
    char texto[100];//Nombre muestra
    char textoNuevo[100];//Reemplazo de nombre
    
    printf("\n-----Horno Electrico-----\n\n");
    do
    {
        printf("\n---------Menu---------\n");
        printf("1. Consultar muestras\n");
        printf("2. Buscar muestra\n");
        printf("3. Nueva muestra\n");
        printf("4. Cambiar datos\n");
        printf("5. Borrar muestra\n");
        printf("6. Calibracion automatica\n");
        printf("7. Salir\n");
        printf("Opcion: ");

        scanf("%d", &opcionM);
        getchar();

    switch (opcionM)
    {
    case 1:
        printf("\n");
        mostrar();
        printf("\n");
        break;

    case 2:
        do
        {
            opcionE = confirmacion(); //Se valida el caracter para el proceso
            switch (opcionE) //Usada para cancelar o seguir
            {
            case 0:
                printf("\nIngrese el nombre de la muestra a buscar: ");
                fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
                texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
                buscarMuestra(texto);
                opcionE = 1; //Para no volver al loop
                break;
        
            case 1:
                printf("\nCerrando submenu.\n");
                break;
        
            default:
                printf("Opcion invalida.\n\n");
                break;
            }
        } while (opcionE != 1);
        break;

    
    case 3:
        do //Usado para que el submenu no se cancele al entrar en opcion invalida
        {
            opcionE = confirmacion(); //Se valida el caracter para el proceso
            switch (opcionE) //Usada para cancelar o seguir
            {
            case 0:
                do
                {
                    printf("\nIngrese el nombre de la nueva muestra (no se permiten comas): ");
                    fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
                    texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
                } while (invalido(texto)); //Verifica que no hayan comas
                printf("Ingrese el valor del calor especifico [J*k/K] (hasta 6 decimales): ");
                scanf("%f", &valorC);
                nuevaMuestra(texto, valorC);
                opcionE = 1; //Para no volver al loop
                break;
        
            case 1:
                printf("\nCerrando submenu.\n");
                break;
        
            default:
                printf("Opcion invalida.\n\n");
                break;
            }
        } while (opcionE != 1);
        break;
        
    case 4:
        do //Usado para que el submenu no se cancele al entrar en opcion invalida
        {
            opcionE=-1; //Para default
            //Submenu de eleccion
            printf("\nQue quiere cambiar: \n");
            printf("1. Nombre\n");
            printf("2. Calor especifico\n");
            printf("3. Ambos\n");
            printf("4. Cancelar\n");
            printf("Opcion: ");
            scanf("%d", &opcionE);
            getchar();
            
            switch (opcionE)
            {
            case 1:
                do
                {
                    printf("\n");
                    mostrar();
                    printf("\n");
                    printf("Ingrese el numero de la muestra: ");
                    scanf("%d", &numeroM); //Obtiene la posicion
                    getchar();
                    printf("Ingrese el nuevo nombre de la muestra (no se permiten comas): ");
                    fgets(textoNuevo, sizeof(textoNuevo), stdin);//Obtiene el texto escrito
                    textoNuevo[strcspn(textoNuevo, "\n")] = '\0'; //Quita salto de linea
                } while (invalido(textoNuevo)); //Verifica que no hayan comas

                cambiarMuestra(numeroM, textoNuevo);
                opcionE=4; //Para no volver al loop
                break;

            case 2:
                printf("\n");
                mostrar();
                printf("\n");
                printf("Ingrese el numero de la muestra: ");
                scanf("%d", &numeroM); //Obtiene la posicion
                getchar();
                printf("Ingrese el valor del calor especifico [J*k/K] (hasta 6 decimales): ");
                scanf("%f", &valorC);
                getchar();
                cambiarCalor(numeroM, valorC);
                opcionE=4; //Para no volver al loop
                break;       

            case 3:
                do
                {
                    printf("\n");
                    mostrar();
                    printf("\n");
                    printf("Ingrese el numero de la muestra: ");
                    scanf("%d", &numeroM); //Obtiene la posicion
                    getchar();
                    printf("Ingrese el nuevo nombre de la muestra (no se permiten comas): ");
                    fgets(textoNuevo, sizeof(textoNuevo), stdin);//Obtiene el texto escrito
                    textoNuevo[strcspn(textoNuevo, "\n")] = '\0'; //Quita salto de linea
                } while (invalido(textoNuevo)); //Verifica que no hayan comas

                printf("Ingrese el valor del calor especifico [J*k/K] (hasta 6 decimales): ");
                scanf("%f", &valorC);
                cambiarMuestra(numeroM, textoNuevo);
                cambiarCalor(numeroM, valorC);
                opcionE=4; //Para no volver al loop
                break;
                
            case 4:
                printf("Cerrando submenu.\n");
                break;
            
            default:
                printf("Opcion invalida.\n");
                break;
            }
        } while (opcionE != 4);
        break;
    
    case 5:
        do //Usado para que el submenu no se cancele al entrar en opcion invalida
        {
            opcionE = confirmacion(); //Se valida el caracter para el proceso
        
            switch (opcionE) //Usada para cancelar o seguir
            {
            case 0:
                printf("\n");
                mostrar();
                printf("\nIngrese el numero de la muestra: ");
                scanf("%d", &numeroM); //Obtiene la posicion
                getchar();
                borrarMuestra(numeroM);
                opcionE=1; //Para no volver al loop
                break;
            
            case 1:
                printf("Cerrando submenu.\n");
                break;
            
            default:
                printf("\nOpcion invalida.\n");
                break;
            }
            } while (opcionE != 1);
        break;

    case 6:
        do //Usado para que el submenu no se cancele al entrar en opcion invalida
        {
            opcionE = confirmacion(); //Se valida el caracter para el proceso
            switch (opcionE) //Usada para cancelar o seguir
            {
            case 0:
                printf("\n");
                mostrar();
                printf("\n");
                printf("Ingrese el numero de la muestra a calibrar: ");
                scanf("%d", &numeroM); //Obtiene la posicion
                getchar();
                valorC = buscarCalor(numeroM);
                if (valorC != 0)
                {
                    valor = calibracion(valorC);
                    printf("La cantidad de energia a suministrar es de %f w/s\n", valor);
                }
                opcionE=1; //Para no volver al loop
                break;

            case 1:
                printf("Cerrando submenu.\n");
                break;
            
            default:
                printf("\nOpcion invalida.\n");
                break;
            }
        } while (opcionE != 1);
        break;
    
    case 7:
        printf("Saliendo del programa.\n");
        break;

    default:
        printf("Opcion invalida.\n");
        break;
    }
    } while (opcionM != 7); //Termina el programa

    return 0;
}

//Verifica que no hayan comas
int invalido(const char *s)
{
    return strchr(s, ',') != NULL; //Mientras que no haya comas debe continuar
}


//Para no equivoarse de opcion
int confirmacion()
{
    char opcionSN[3];
    printf("Confirmacion [s/n]\n");
    fgets(opcionSN, sizeof(opcionSN), stdin);
    opcionSN[strcspn(opcionSN, "\n")] = '\0'; //Quita salto de lines
    if (strcmp(opcionSN, "s") == 0 || strcmp(opcionSN, "S") == 0)
    {
        return 0;
    }
    else if (strcmp(opcionSN, "n") == 0 || strcmp(opcionSN, "N") == 0)
    {
         return 1;
    }
    else
    {
        return -1;//Para que al leer otros caracteres no haya errores
    }
}
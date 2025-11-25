#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escritura.h" //Libreria para escribri a archivo csv
#include "inercia.h" //Libreria con los calculos

int main()
{
    int opcionM=0, opcionE=0; //Opciones del menu
    float valor=0;//Inercia
    char texto[100];//Nombre muestra
    char textoNuevo[100];//Reemplazo de nombre
    
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Mostrar muestras\n");
        printf("2. Nueva muestra\n");
        printf("3. Cambiar datos\n");
        printf("4. Borrar muestra\n");
        printf("5. Salir\n");
        printf("Opcion: ");

        scanf("%d", &opcionM);
        getchar();

    switch (opcionM)
    {
    case 1:
        mostrar();
        break;

    case 2:
        printf("Si quiere cancelar presione 1\n");
        printf("Si quiere seguir presione otro numero\n");
        scanf("%d", &opcionE);
        getchar();
        if (opcionE != 1) //Usada para cancelar o seguir
        {
            printf("Ingrese el nombre de la nueva muestra: ");
            fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
            texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
            valor = datos();//Hace el calculo de la inercia
            nuevaMuestra(texto, valor);
        }
        break;
        
    case 3:
        printf("\nQue quiere cambiar: \n");
        printf("1. Nombre\n");
        printf("2. Inercia\n");
        printf("3. Ambos\n");
        printf("4. Cancelar\n");
        scanf("%d", &opcionE);
        getchar();
        //Submenu de escritura
        switch (opcionE)
        {
            case 1:
                printf("Ingrese el nombre de la muestra: \n");
                fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
                texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
                printf("Ingrese el nuevo nombre de la muestra: \n");
                fgets(textoNuevo, sizeof(textoNuevo), stdin);//Obtiene el texto escrito
                textoNuevo[strcspn(textoNuevo, "\n")] = '\0'; //Quita salto de linea
                cambiarMuestra(texto, textoNuevo);
                break;

            case 2:
                printf("Ingrese el nombre de la muestra: \n");
                fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
                texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
                valor = datos();//Hace el calculo de la inercia
                cambiarInercia(texto, valor);
                break;

            case 3:
                printf("Ingrese el nombre de la muestra: \n");
                fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
                texto[strcspn(texto, "\n")] = '\0'; //Quita salto de linea
                printf("Ingrese el nuevo nombre de la muestra: \n");
                fgets(textoNuevo, sizeof(textoNuevo), stdin); //Obtiene el texto escrito
                textoNuevo[strcspn(textoNuevo, "\n")] = '\0'; //Quita salto de lines
                valor = datos();//Hace el calculo de la inercia
                cambiarMuestra(texto, textoNuevo);
                cambiarInercia(textoNuevo, valor);
                break;

            case 4:
                printf("Cerrando submenu.\n");
                break;
            
            default:
                printf("Opcion invalida.\n");
                break;
        }
        break;
    
    case 4:
        printf("Si quiere cancelar presione 1\n");
        printf("Si quiere seguir presione otro numero\n");
        scanf("%d", &opcionE);
        getchar();
        printf("%d", opcionE);
        if (opcionE != 1) //Usada para cancelar o seguir
        {
            printf("Ingrese el nombre de la muestra a borrar: ");
            fgets(texto, sizeof(texto), stdin);//Obtiene el texto escrito
            texto[strcspn(texto, "\n")] = '\0'; //Quita salto de lines
            borrarMuestra(texto);
        }
        break;

    case 5:
        printf("Saliendo del programa.\n");
        break;

    default:
        printf("Opcion invalida.\n");
        break;
    }
    } while (opcionM != 5); //Termina el programa

    return 0;
}


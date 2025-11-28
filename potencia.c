#include <stdio.h>
#include <math.h>
#include "potencia.h"

float calibracion(float calor)
{
    float tempI = 0.0, tempF=0.0, tiempo = 0, masa=0, energia=0, watts=0;
    printf("\nSe permiten hasta 6 decimales\n");
    printf("Ingrese el valor de la masa (kg): ");
    scanf("%f", &masa);
    printf("Ingrese el valor de temperatura inicial (K): ");
    scanf("%f", &tempI);
    printf("Ingrese el valor de temperatura final (K): ");
    scanf("%f", &tempF);
    printf("Ingrese el tiempo (s): ");
    scanf("%f", &tiempo);

    energia = masa*calor*(tempF-tempI);
    watts = energia/tiempo;
    
    return watts;
}
#include <stdio.h>
#include <math.h>
#include "inercia.h"

float datos()
{   
    float r = 0.0, conduc=0, densidad=0, calorE=0;
    printf("Ingrese la conductividad termica (W/m*K): ");
    scanf("%f", &conduc);
    printf("Ingrese la densidad (kg/m3) ");
    scanf("%f", &densidad);
    printf("Ingrese el calor especifico (J/kg*K) ");
    scanf("%f", &calorE);
    r = sqrt(conduc*densidad*calorE);
    return r;
}
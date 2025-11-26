#ifndef escritura_h
#define escritura_h

typedef struct
{
    char nombre[50];
    float calorE;
}base;

void mostrar();
void nuevaMuestra(const char *texto, float calorE);
void cambiarMuestra(int numero, const char *reemplazo);
void cambiarCalor(int numero, float reemplazo);
void borrarMuestra(int numero);
void buscarMuestra(const char *texto);
float buscarCalor(int numero);

#endif
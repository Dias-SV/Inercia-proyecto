#ifndef escritura_h
#define escritura_h

typedef struct
{
    char nombre[50];
    float inercia;
}base;

void mostrar();
void nuevaMuestra(const char *texto, float inercia);
void cambiarMuestra(const char *texto, const char *reemplazo);
void cambiarInercia(const char *texto, float reemplazo);
void borrarMuestra(const char *texto);


#endif
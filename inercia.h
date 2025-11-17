#ifndef inercia_h
#define inercia_h

typedef struct
{
    char nombre[50];
    float inercia;
}base;

void mostrar();
void nuevaMuestra(const char *texto, float inercia);
void cambiarMuestra(const char *texto, const char *reemplazo);


#endif
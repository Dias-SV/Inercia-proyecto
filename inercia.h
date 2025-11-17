#ifndef inercia_h
#define inercia_h

typedef struct
{
    char nombre[50];
    float inercia;
}datos;

void mostrar();
void cambiarMuestra(const char *texto, const char *reemplazo);


#endif
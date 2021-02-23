#ifndef EXERCICIOS_H
#define EXERCICIOS_H

#include "redesocial.h"

int AmigosEmComum(TRedeSocial rede, int id1, int id2);
int MaisAmigos(TRedeSocial rede);
void MatrizAmigosEmComum(TRedeSocial *rede);
void SemAmigosEmComum(TRedeSocial rede, TUsuarios userA, TUsuarios userB);



#endif // EXERCICIOS_H

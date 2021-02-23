#ifndef EXERCICIOS_H
#define EXERCICIOS_H

#include "redesocial.h"
#include "interface.h"
#include "amizade.h"

int AmigosEmComum(TRedeSocial rede, int id1, int id2);
int MaisAmigos(TRedeSocial rede);
int AmizadeIndireta1(TRedeSocial rede, TUsuarios userA, TUsuarios userB);
void MatrizAmigosEmComum(TRedeSocial *rede);
void SemAmigosEmComum(TRedeSocial rede, TUsuarios userA, TUsuarios userB);
void AmizadeIndireta2(TRedeSocial rede, TUsuarios userA, TUsuarios userB, int *id1, int *id2);


#endif // EXERCICIOS_H

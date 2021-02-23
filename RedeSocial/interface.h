#ifndef INTERFACE_H
#define INTERFACE_H

#include "redesocial.h"
#include "amizade.h"
#include "exercicios.h"

void MSG_REDE();

// MENU PRINCIPAL
void MSG_MENU();

// SUBMENU MÓDULOS
void MSG_SUBMENU(int numero_modulo);
void MSG_SUBMENU2(int numero_modulo);
void MSG_SUBMENU3(int numero_modulo);

void SubMenuModulo1(TRedeSocial *rede, TUsuarios user);
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user);
void SubMenuModulo3(TRedeSocial *rede, TUsuarios user);

#endif // INTERFACE_H





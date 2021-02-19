#ifndef INTERFACE_H
#define INTERFACE_H

#include "redesocial.h"
#include "amizade.h"

void MSG_REDE();
void MSG_MENU(); // MENU PRINCIPAL
void MSG_SUBMENU(int numero_modulo); // SUBMENU MÓDULOS
void MSG_SUBMENU2(int numero_modulo);
void SubMenuModulo1(TRedeSocial *rede, TUsuarios user);
void SubMenuModulo2(TRedeSocial *rede, TUsuarios user);

#endif // INTERFACE_H





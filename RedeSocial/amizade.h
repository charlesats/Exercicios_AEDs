#ifndef AMIZADE_H
#define AMIZADE_H

#include "redesocial.h"
#include "interface.h"

int PesquisarAmizades(TRedeSocial rede, TUsuarios userA, TUsuarios userB);
void CadastrarAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
void ExcluirAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB);
void ImprimirListaAmigos(TRedeSocial rede, TUsuarios user);

#endif // AMIZADE_H





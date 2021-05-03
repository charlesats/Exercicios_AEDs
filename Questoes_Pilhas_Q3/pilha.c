void FPVazia(TPilha *Pilha){
  Pilha->topo = (TCelula*)
      malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha){
 return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x,TPilha *Pilha){
  TCelula* Aux;
  Aux = (TCelula*)
         malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo = Aux;
  Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha,TProduto *Item){
  TCelula* q;
  if (Vazia(*Pilha)) {
      printf("Erro: lista vazia\n");
      return;
  }
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->item;
  free(q);
  Pilha->tamanho--;
}

void Imprimir(TPilha *Pilha){
    TPilha PilhaAux;
    FPVazia(&PilhaAux);

    TProduto Item;

    // Pop de PIlha e Push em Pilha auxiliar
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
        Empilhar(&PilhaAux, Item);
    }

    while(!Vazia(PilhaAux)){
        Desempilhar(&PilhaAux, &Item);
        ImprimiProduto(Item);// realizar a impressão
                            // de cada campo do produto
        Empilhar(Pilha, Item);
    }
    free(PilhaAux.topo);// eliminar a célula cabeça
}

void Liberar(TPilha *Pilha){
    TProduto Item;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha, &Item);
    }
    free(Pilha.topo);
}

int Tamanho(TPilha Pilha){
 return (Pilha.tamanho);
}


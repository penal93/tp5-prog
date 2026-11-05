// TAD Fila de prioridades (FPRIO) genérica
// Carlos Maziero, DINF/UFPR, Out 2024
// Marcos Castilho, inclui as structs no arquivo.c, Out 2025
// Implementação com lista encadeada simples

// descreve um nodo da fila de prioridades
// NAO altere estas estruturas
struct fpnodo_t
{
  void *item ;          // item associado ao nodo
  int   tipo ;          // tipo do item
  int   prio ;          // prioridade do item
  struct fpnodo_t *prox;    // próximo nodo
};

// descreve uma fila de prioridades
struct fprio_t
{
  struct fpnodo_t *prim ;   // primeiro nodo da fila
  int num ;         // número de itens na fila
} ;

// A COMPLETAR


struct fprio_t *fprio_cria (){
  struct fprio_t *novaFila = malloc (sizeof (struct fprio_t));

  if (!novaFila)
    return NULL;

  novaFila->prim = NULL;
  novaFila->num = 0;

  return novaFila;
}

struct fprio_t *fprio_destroi (struct fprio_t *f){
  struct fpnodo_t *atual = f->prim;
  struct fpnodo_t *prox;

  while (prox){
    prox = atual->prox;

    free(atual->item);
    free(atual->prox);
    free(atual);

    atual = prox;
  }

  free (f);
  f = NULL;

  return NULL;
}

int fprio_insere (struct fprio_t *f, void *item, int tipo, int prio){
  struct fpnodo_t *novoNodo = malloc (sizeof (struct fpnodo_t));
  
  if (!f->prim){
    f-prim = novoNodo;
    novoNodo->prox = NULL;
  }

  struct fpnodo_t *atual = f->prim; 
  struct fpnodo_t *ant;

  while (atual->prio >= prio){
    if (item = atual->item)
      return -1;
    
    ant = atual;
    atual = atual-prox;
  }

  ant->prox = novoNodo;
  novoNodo->prox = atual;

  novoNodo->item = item;
  novoNodo->tipo = tipo;
  novoNodo->prio = prio;

  f->num ++;

  return f->num;
}


int fprio_tamanho (struct fprio_t *f){
  if (!f->num)
    return -1;

  return f->num;
}



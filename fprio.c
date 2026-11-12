// TAD Fila de prioridades (FPRIO) genérica
// Carlos Maziero, DINF/UFPR, Out 2024
// Marcos Castilho, inclui as structs no arquivo.c, Out 2025
// Implementação com lista encadeada simples

#include <stdio.h>
#include <stdlib.h>
#include "fprio.h"

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
  struct fpnodo_t *prox = atual;

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
  if (!f || !item)
    return -1;

  struct fpnodo_t *atual = f->prim;

  while (atual){
    if (atual->item == item)
      return -1;

    atual = atual->prox;
  }

  struct fpnodo_t *novoNodo = malloc(sizeof (struct fpnodo_t));

  if (!novoNodo)
    return -1;

  novoNodo->item = item;
  novoNodo->prio = prio;
  novoNodo->tipo = tipo;

  if (!f->num || f->prim->prio > prio){
    novoNodo->prox = f->prim;
    f->prim = novoNodo;

    f->num ++;

    return f->num;
  }

  atual = f->prim;

  while (atual->prox && atual->prox->prio <= prio)
    atual = atual->prox;

  novoNodo->prox = atual->prox;
  atual->prox = novoNodo;

  f->num ++;

  return f->num;
}

void *fprio_retira (struct fprio_t *f, int *tipo, int *prio){
  if (!f)
    return NULL;

  if (!f->num || !tipo || !prio)
    return NULL;

  *tipo = f->prim->tipo;
  *prio = f->prim->prio;
  struct fpnodo_t *removido = f->prim;

  f->prim = f->prim->prox;

  void *itemRemovido = removido->item;
  free(removido);

  f->num --;

  return itemRemovido;
}

int fprio_tamanho (struct fprio_t *f){
  if (!f)
    return -1;

  return f->num;
}

void fprio_imprime (struct fprio_t *f){
  struct fpnodo_t *atual = f->prim;

  while (atual){
    if (f->num == 1 || !atual->prox){
      printf("(%d %d)", atual->tipo, atual->prio);
      return;
    }

    printf("(%d %d) ", atual->tipo, atual->prio);
    atual = atual->prox;
  }
}


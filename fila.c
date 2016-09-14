#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next, link prev) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  t->prev = prev;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisDireita = f->maisEsquerda = NULL;
  return f;
}

void inserirEsquerda(FILA f, int e) {
  if(f->maisEsquerda == NULL && f->maisDireita == NULL) {
    f->maisEsquerda = f->maisDireita = novoNo(e, NULL, NULL);
  } else {
    f->maisEsquerda->prev = novoNo(e, f->maisEsquerda, NULL);
    f->maisEsquerda = f->maisEsquerda->prev;
  }
}

void inserirDireita(FILA f, int e) {
  if(f->maisEsquerda == NULL && f->maisDireita == NULL) {
    f->maisEsquerda = f->maisDireita = novoNo(e, NULL, NULL);
  } else {
    f->maisDireita->next = novoNo(e, NULL, f->maisDireita);
    f->maisDireita = f->maisDireita->next;
  }
}

int removerEsquerda(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisEsquerda->item;
  t = f->maisEsquerda;
  f->maisEsquerda = f->maisEsquerda->next;
 
  if(f->maisEsquerda == NULL)
    f->maisDireita = NULL;

  free(t);
  return x;
}

int removerDireita(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisDireita->item;
  t = f->maisDireita;
  f->maisDireita = f->maisDireita->prev;
 
  if(f->maisDireita == NULL)
    f->maisEsquerda = NULL;

  free(t);
  return x;
}

int filaVazia(FILA f) {
  return ((f->maisDireita == NULL) && (f->maisEsquerda == NULL));
}

void imprimirFilaDirEsq(FILA f) {
  link t;
  for(t = f->maisEsquerda; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}

void imprimirFilaEsqDir(FILA f) {
  link t;
  for(t = f->maisDireita; t != NULL; t = t->prev) 
    printf ("%d ", t->item);
  printf ("\n");
}

void destroiFila(FILA f) {
  while (!filaVazia(f))
    removerDireita(f);
  free(f);
}

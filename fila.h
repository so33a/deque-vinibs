#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  link prev
  int item;
  link next;
};

typedef struct {
  link maisEsquerda;
  link maisDireita;
} * FILA;

link novoNo(int item, link next, link prev);
FILA novaFila();
void inserirEsquerda(FILA f, int e);
void inserirDireita(FILA f, int e);
int removerEsquerda(FILA f);
int removerDireita(FILA f);
void imprimirFilaDirEsq(FILA f);
void imprimirFilaEsqDir(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 

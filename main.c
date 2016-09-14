#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserirDireita(alunos, 9);
  inserirEsquerda(alunos, 8);
  inserirDireita(alunos, 3);
  inserirEsquerda(alunos, 10);

  imprimirFilaDirEsq(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removerDireita(alunos));


  inserirDireita(alunos, 10);
  inserirEsquerda(alunos, 32);
  
  imprimirFilaEsqDir(alunos);

  destroiFila(alunos);

  return 0;
}

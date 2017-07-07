#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para calcular a área do triângulo
int area(int x1, int y1, int x2, int y2, int x3, int y3){
  return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
}

bool verifica(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){
  int A = area (x1, y1, x2, y2, x3, y3);    /* Calcular área do triângulo ABC */
  int A1 = area (x, y, x2, y2, x3, y3);     /* Calcular área do triângulo PBC */
  int A2 = area (x1, y1, x, y, x3, y3);     /* Calcular área do triângulo PAC */
  int A3 = area (x1, y1, x2, y2, x, y);     /* Calcular área do triângulo PAB */
  if(A == (A1 + A2 + A3)){    /* Verifique se a soma de A1, A2 e A3 é igual a A */
    return true;
  }else{
    return false;
  }
}

FILE *arq, *prm;

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

#define TRUE 1
#define FALSE 0

int intCartas [9] = { 4, 5, 1, 7, 8, 3, 2, 6, 9 };

void PesquisaSequencial (int intValorProcurado)
{
  int intIndice, intEncontrado;

  intIndice = 0;
  intEncontrado = FALSE;

  while((intIndice < 9) && (intEncontrado == FALSE))
  {
    if (intCartas[intIndice] == intValorProcurado)
      intEncontrado = TRUE;
    else
      intIndice++;
  }

  if (intEncontrado == TRUE)
    std::cout << "Valor encontrado na posicao " << intIndice+1 << "\n";
  else
    std::cout << "Valor nao encontrado\n";
}

int main()
{
  int intValorProcurado;

  system("clear");
  std::cout << "Digite o valor a ser procurado: ";
  std::cin >> intValorProcurado;
  PesquisaSequencial(intValorProcurado);
}
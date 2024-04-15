#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int intCartas [9] = { 4, 5, 1, 7, 3, 2, 6, 9, 8 };

void ImprimeMatriz(void)
{
  for (int intContador = 0; intContador < 9; intContador++)
    std::cout << intCartas[intContador] << " ";

  std::cout << "\n\n";
}

void OrdenaMatriz(void)
{
  int intCartaTemp;

  for (int intEsquerda = 0; intEsquerda < 8; intEsquerda++)
  {
    for (int intDireita = intEsquerda + 1; intDireita < 9; intDireita++)
    {
      if (intCartas[intEsquerda] > intCartas[intDireita])
      {
        intCartaTemp = intCartas[intEsquerda];
        intCartas[intEsquerda] = intCartas[intDireita];
        intCartas[intDireita] = intCartaTemp;
      }
    }
    std::cout << "Passagem no." << (intEsquerda + 1) << "\n";
    ImprimeMatriz();
  }
}

int main()
{
  system("clear");
  OrdenaMatriz();
}

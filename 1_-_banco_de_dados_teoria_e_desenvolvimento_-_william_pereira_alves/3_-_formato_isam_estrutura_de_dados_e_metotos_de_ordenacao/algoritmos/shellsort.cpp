#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int intCartas [9] = { 4, 5, 1, 7, 3, 2, 6, 9, 8 };

void ShellSort(int intTamanho)
{
  int intContador1, intContador2, intIncremento, intTemporario;

  intIncremento = intTamanho / 2;

  while (intIncremento > 0)
  {
    intContador1 = 0;

    while(intContador1 < (intTamanho -1))
    {
      intTemporario = intCartas[intContador1];
      intContador2 = intContador1 + intIncremento;

      while(intContador2 <= intTamanho - 1)
      {
        if(intCartas[intContador2] < intTemporario)
        {
          intCartas[intContador1] = intCartas[intContador2];
          intCartas[intContador2] = intTemporario;
          intTemporario = intCartas[intContador1];
        }

        intContador2 += intIncremento;
      }

      intContador1++;

      if((intContador1 + intIncremento) > (intTamanho -1))
        break;
    }

    intIncremento /= 2;
  }
}

void ImprimeMatriz(void)
{
  for (int intContador = 0; intContador < 9; intContador++)
    std::cout << intCartas[intContador] << " ";

  std::cout << "\n\n";
}

int main()
{
  ImprimeMatriz();
  ShellSort(9);
  ImprimeMatriz();
}
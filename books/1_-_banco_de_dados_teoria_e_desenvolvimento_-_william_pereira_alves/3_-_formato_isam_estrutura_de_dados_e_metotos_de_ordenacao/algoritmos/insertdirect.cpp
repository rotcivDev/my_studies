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
  int intPassagem = 0, intContador, intCartaTemp;
  char charTrocou = 'N';

  for(int intItem = 1; intItem < 9; intItem++)
  {
    charTrocou = 'N';
    intCartaTemp = intCartas[intItem];
    intContador = intItem;

    while(intCartas[intContador - 1] > intCartaTemp)
    {
      charTrocou = 'S';
      intCartas[intContador] = intCartas[intContador - 1];
      intContador--;

      if (intContador <= 0)
        break;
    }

    intCartas[intContador] = intCartaTemp;

    if(charTrocou == 'S')
    {
      intPassagem++;
      std::cout << "Passagem no." << intPassagem << "\n";
      ImprimeMatriz();
    }
  }
}

int main()
{
  system("clear");
  OrdenaMatriz();
}
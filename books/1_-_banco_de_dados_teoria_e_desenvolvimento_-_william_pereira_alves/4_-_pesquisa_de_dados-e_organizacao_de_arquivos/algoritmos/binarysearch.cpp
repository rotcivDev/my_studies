#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

#define TRUE 1
#define FALSE 0

int intCartas [9] = { 11, 25, 38, 45, 50, 62, 75, 80, 95 };

void PesquisaBinaria(int intValorProcurado)
{
  int intMeio, intInicio, intFim, intEncontrado;

  intInicio = 0;
  intFim = 8;
  intEncontrado = FALSE;

  while((intInicio <= intFim) && (intEncontrado == FALSE))
  {
    intMeio = (intInicio + intFim) / 2;

    if(intCartas[intMeio] > intValorProcurado)
      intFim = intMeio - 1;
    
    else if(intCartas[intMeio] < intValorProcurado)
      intInicio = intMeio + 1;
    
    else if(intCartas[intMeio] == intValorProcurado)
      intEncontrado = TRUE;
  }

  if(intEncontrado == TRUE)
    std::cout << "Valor encontrado na posicao " << intMeio+1 << "\n";
  else
    std::cout << "Valor nao encontrado\n";
}

int main()
{
  int intValorProcurado;

  system("clear");
  std::cout << "Digite o valor a ser procurado: ";
  std::cin >> intValorProcurado;
  PesquisaBinaria(intValorProcurado);
}
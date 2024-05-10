#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int intCartas [9] = { 4, 5, 1, 7, 3, 2, 6, 9, 8 };

void _sort(int intVetor[], int intInicio, int intFim)
{
  int intPivo, intLadoEsquerdo, intLadoDireito;

  intLadoEsquerdo = intInicio;
  intLadoDireito = intFim;
  intPivo = intVetor[intInicio];

  while (intInicio < intFim)
  {
    while ((intVetor[intFim] >= intPivo) && (intInicio < intFim))
      intFim--;

    if (intInicio != intFim)
    {
      intVetor[intInicio] = intVetor[intFim];
      intInicio++;
    }

    while ((intVetor[intInicio] <= intPivo) && (intInicio < intFim))
      intInicio++;

    if (intInicio != intFim)
    {
      intVetor[intFim] = intVetor[intInicio];
      intFim--;
    }
  }

  intVetor[intInicio] = intPivo;
  intPivo = intInicio;
  intInicio = intLadoEsquerdo;
  intFim = intLadoDireito;

  if(intInicio < intPivo)
    _sort(intVetor, intInicio, intPivo - 1);

  if(intFim > intPivo)
    _sort(intVetor, intPivo + 1, intFim);
}

void Quicksort(int intVetor[], int intTamanho)
{
  _sort(intVetor, 0, intTamanho - 1);
}

void ImprimeMatriz(void)
{
  for (int intContador = 0; intContador < 9; intContador++)
    std::cout << intCartas[intContador] << " ";

  std::cout << "\n\n";
}

int main()
{
  system("clear");
  Quicksort(intCartas, 9);
  ImprimeMatriz();
}
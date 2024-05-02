#include <stdio.h>

/*Celsius to Fahrenheit Equivalence Range
*
* print range
* for c = 0, 20, ..., 300
*/

int main()
{
  int lower, upper, step;
  float fahr, celsius;
  lower = 0; /* lower limit of temperature table*/
  upper = 200; /* upper limit */
  step = 20; /* step size */
  celsius = lower;
  
  printf("Celsius to Fahrenheit Equivalence Range\n");

  while (celsius <= upper){
    fahr = ((9.0/5.0) * celsius) + 32.0;
    printf("%4.0f %6.1f\n",celsius,fahr);
    celsius = celsius + step;
  }
}

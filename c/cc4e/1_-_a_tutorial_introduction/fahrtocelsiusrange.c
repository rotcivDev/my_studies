#include <stdio.h>

/* Fahrenheit to Celsius Equivalence Range
*
* print range
* for f = 0, 20, ..., 300
*/

int main()
{
  int lower, upper, step;
  float fahr, celsius;
  lower = 0; /* lower limit of temperature table*/
  upper = 900; /* upper limit */
  step = 20; /* step size */
  fahr = lower;
  
  printf("Fahrenheit to Celsius Range:\n");

  while (fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%4.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

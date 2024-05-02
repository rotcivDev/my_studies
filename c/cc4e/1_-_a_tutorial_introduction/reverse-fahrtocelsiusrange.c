#include <stdio.h>
/* Fahrenheit to Celsius Equivalence Reverse Range
*
* print range
* for f = 0, 20, ..., 300
*/

#define LOWER 0 /* lower limit */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */

int main()
{
  int fahr;

  printf("Fahrenheit to Celsius Reverse Range:\n");

  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

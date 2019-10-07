/* functions.c
* author: 
* date: 03.10.2019
* Main functionality implementation.
*/

#include "functions.h"
#include "stdio.h"

float calcCredit(float base, float tax, int years)
{
    float a = 1;
    int n = 0;

    while (n++ < years) {
        a = a * ((float) 1 + (tax / (float) 100));
    }

    return base * a;
}

float calcAmortizationRate(float amount, float creditTax, float debtTax)
{
    return amount * (creditTax / 100 + debtTax / 100);
}

float calcBalanceDue(float dueStart, float amortizationRate /* s */, float creditTax, int years)
{
    float be = dueStart - (amortizationRate - dueStart * (creditTax / (float) 100));

    printf("be nach %i jahren: %f\n", years, be);

    if ((years - 1) > 0)
        be = calcBalanceDue(be, amortizationRate, creditTax, --years);

    return be;
}
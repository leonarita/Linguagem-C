#include <stdio.h>      /* Standard Library of Input and Output */
#include <complex.h>    /* Standard Library of Complex Numbers */
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "");
    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("\t\tTrabalhando com números complexos:");

    printf("\n\nValores iniciais: \n\t Z1 = %.2f %+.2fi \n\t Z2 = %.2f %+.2fi", creal(z1), cimag(z1), creal(z2), cimag(z2));

    double complex sum = z1 + z2;
    printf("\n\nA soma: Z1 + Z2 = %.2f %+.2fi", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("\nA subtração: Z1 - Z2 = %.2f %+.2fi", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("\nO produto: Z1 x Z2 = %.2f %+.2fi", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("\nA divisão: Z1 / Z2 = %.2f %+.2fi", creal(quotient), cimag(quotient));

    double complex conjugate = conj(z1);
    printf("\nO conjugado de Z1 = %.2f %+.2fi", creal(conjugate), cimag(conjugate));

    return 0;
}

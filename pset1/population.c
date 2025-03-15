#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int quantInicial, quantFinal;

    do
    {
        quantInicial = get_int("Start size: ");
    }
    while (quantInicial < 9);

    do
    {
        quantFinal = get_int("End size: ");
    }
    while (quantFinal < quantInicial);

    int anos = 0;
    while (quantInicial < quantFinal)
    {
        int nascimentos = quantInicial / 3;
        int mortes = quantInicial / 4;
        quantInicial += (nascimentos - mortes);
        anos++;
    }

    printf("Years: %d\n", anos);

    return 0;
}

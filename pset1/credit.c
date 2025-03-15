#include <cs50.h>
#include <stdio.h>

bool validarLuhn(long numero);
int contarDigitos(long numero);
int obterPrefixo(long numero, int digitos);
void verificarCartao(long numero);

int main(void)
{
    long numero = get_long("Número: ");
    verificarCartao(numero);
}

bool validarLuhn(long numero)
{
    int soma = 0;
    bool dobrar = false;

    while (numero > 0)
    {
        int digito = numero % 10;

        if (dobrar)
        {
            digito *= 2;
            soma += (digito / 10) + (digito % 10);
        }
        else
        {
            soma += digito;
        }

        dobrar = !dobrar;
        numero /= 10;
    }

    return (soma % 10 == 0);
}

int contarDigitos(long numero)
{
    int contador = 0;
    while (numero > 0)
    {
        contador++;
        numero /= 10;
    }
    return contador;
}

int obterPrefixo(long numero, int digitos)
{
    while (numero >= 100)
    {
        numero /= 10;
    }
    return numero;
}

void verificarCartao(long numero)
{
    int digitos = contarDigitos(numero);
    int prefixo = obterPrefixo(numero, digitos);

    if (validarLuhn(numero))
    {
        if ((digitos == 15) && (prefixo == 34 || prefixo == 37))
        {
            printf("AMEX\n");
        }
        else if ((digitos == 16) && (prefixo >= 51 && prefixo <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digitos == 13 || digitos == 16) && (prefixo / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

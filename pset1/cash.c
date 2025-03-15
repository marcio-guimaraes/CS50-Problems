#include <cs50.h>
#include <stdio.h>

int main()
{

    float change;
    change = get_float("Change: ");
    int coins = 0;

    while (change > 0)
    {
        if (coins >= 0.25)
        {
            coins++;
            change -= 0.25;
        }
        else if (change >= 10)
        {
            coins++;
            change -= 0.10;
        }
        else if (change >= 5)
        {
            coins++;
            change -= 0.05;
        }
        else
        {
            change -= 0.01;
            coins++;
        }
    }

    printf("%d\n", coins);

    return 0;
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i; 
    do
    {
        i = get_int("pyramid height: ");
    }
    while (i < 1 || i > 8);
    for (int j = 0; j < i; j++)
    {
        for (int x = i - 1; x > j; x--)
        {
            printf(" ");
        }
        for (int y = 0; y <= j; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}

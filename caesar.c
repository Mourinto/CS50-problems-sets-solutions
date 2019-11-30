#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int counter = 0;
    for (int i = 0; i < strlen(argv[1]); i++) 
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        { 
            printf("Usage: %s key\n", argv[0]);
            return 1;  
        }
        else
        {
            counter++;
        }
    }
    
    if (counter == strlen(argv[1]))
    {
        int key = atoi(argv[1]);
        if (key < 0)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        else
        {
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, k = strlen(text); i < k; i++)
            {
                if (text[i] >= 'a' && text[i] <= 'z')
                {
                    printf("%c", (((text[i] - 'a') + key) % 26) + 'a'); 
                } 
                else if (text[i] >= 'A' && text[i] <= 'Z')
                {
                    printf("%c", (((text[i] - 'A') + key) % 26) + 'A'); 
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

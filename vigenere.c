#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
        if ((argv[1][i] < 'a' || argv[1][i] > 'z') && (argv[1][i] < 'A' || argv[1][i] > 'Z'))
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
        string code = argv[1];
        int code_length = strlen(code);
        string text = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, j = 0, k = strlen(text); i < k; i++)
        {
            int key = tolower(code[j % code_length]) - 'a';
            if (islower(text[i]))
            {
                printf("%c", 'a' + (text[i] - 'a' + key) % 26);
                j++;
            } 
            else if (isupper(text[i]))
            {
                printf("%c", 'A' + (text[i] - 'A' + key) % 26);
                j++;
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}

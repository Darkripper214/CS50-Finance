#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // per instructions -- terminate program if more than one key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char str[100];
    int len;
    strcpy(str, argv[1]);
    len = strlen(str);
    
    // Loop through str
    for (int i = 0; i < len; i++)
    {
        // If character is alphabet, print wrong message, and return
        // It has to be number
        if (isalpha(str[i])) 
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    
    string Plaintext = get_string("plaintext: ");
    int k = atoi(argv[1]);
    string s = Plaintext ;
    for (int i = 0; strlen(Plaintext) > i ; i++)
    {
        // Checking if it is lower case a to z
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = ((((s[i] - 'a') + k) % 26) + 'a');
        }
        
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = ((((s[i] - 'A') + k) % 26) + 'A');
        }
        
    }
    string Cipertext = s ;
    printf("cipertext: %s\n", Cipertext);
    return 0
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    // per instructions -- terminate program if more than one key
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
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
        if (isdigit(str[i])) 
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    
    
    string Plaintext = get_string("plaintext: ");
 //   int k = atoi(argv[1]);
    string s = Plaintext ;
    
    int y = 0;
    for (int i = 0; strlen(s) > i ; i++)
    {
        if(y>(len-1))
        {
          y=0;  
        }
        // Checking if it is lower case a to z
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = ((((s[i] - 'a') + (shift(argv[1][y]))) % 26)  + 'a');
            y++;
        }
        
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = ((((s[i] - 'A') + (shift(argv[1][y]))) % 26)  + 'A');
            y++;
        }
        
        //int key = shift(argv[1][y]);
        //printf("%c\n", s[i]);
    }
    printf("ciphertext: %s\n", s);
    
}

int shift(char c)
{
    //printf("key\n");
    //printf("%c\n", c);
        if (c >= 'a' && c <= 'z')
        {
            c = ((c - 'a') % 26);
        }
        
        else if (c >= 'A' && c <= 'Z')
        {
            c = ((c - 'A') % 26);
        }
    //printf("%i\n", c);
    return c;
}


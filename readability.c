#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: ");
    int letter_count = 0;
    int word_count = 1;
    int sentence_count = 0;
    float index;



    for (int i = 0; i<strlen(text); i++)
    {
        if(tolower(text[i]) >= 97 && tolower(text[i]) <= 122 )
        {
            letter_count++;
        }

        if(text[i] == 32)
        {
            word_count++;
        }

        if(text[i] == 33 || text[i] == 63  || text[i] == 46 )
        {
           sentence_count++;
        }
    }

    float L = 0;
    float S = 0;

    L = 100 * (float)letter_count/(float)word_count;
    S = 100 * (float)sentence_count/(float)word_count;

    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (index >= 1 && index < 16)
    {
        printf("Grade %.00f\n", index);
        return 0;
    }

    if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("%i letter(s)\n", letter_count);
    printf("%i word(s)\n", word_count);
    printf("%i sentence(s)\n", sentence_count);

}
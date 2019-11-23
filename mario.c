#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
void print_space(int num);
void print_hash(int num);

int main(void)
{
    int height = get_positive_int("Positive integer:");
    printf("%i\n", height);
    
    int spaces = height - 1;
    int hashes = 1;
    
    // Build pyramid
    for (int i = 0; i < height; i++)
    {
        print_space(spaces);
        print_hash(hashes);
        printf(" ");
        print_hash(hashes);
        printf("\n");
        spaces--;
        hashes++;
    }
}

// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    return n;
}

// Print hashes
void print_hash(int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("#");
    }
}

// Print spaces
void print_space(int num)
{
    for(int i = 0; i < num; i++)
    {
        printf(" ");
    }
}

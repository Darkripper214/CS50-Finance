#include <stdio.h>
#include <cs50.h>
#include <math.h>

int Obtain_Change(string prompt);

int main(void)
{
    int x = Obtain_Change("Cents");
    int Num_of_coins = 0;

    // Get the amount of coins
    Num_of_coins += x / 25;
    x %= 25;

    Num_of_coins += x / 10;
    x %= 10;

    Num_of_coins += x / 5;
    x %= 5;

    Num_of_coins += x / 1;
    x %= 1;

    printf("%i\n", Num_of_coins);
}

// Get positive integer
int Obtain_Change(string prompt)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    int cents = round(change * 100);
    return cents;
}

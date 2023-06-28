// My note:functions does not plus or minus, And so forth
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    cents = cents + 1000;
    printf("+1000=%i\n",cents);
//printf("q=%i\n",calculate_quarters(cents));
    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
//printf("d=%i\n",calculate_dimes(cents));
    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
//printf("n=%i\n",calculate_nickels(cents));
    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
//printf("p=%i\n",calculate_pennies(cents));
    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents()
{
    int cents;
    // TO ask how much cents
    do
    {
        cents = get_int("Change owed: ");
        printf("a=%i\n",cents);
    }
    while (cents < 0);
    return  cents;
}

int calculate_quarters(int cents)
{
    // TO calculate_quarters
    int q = cents / 25;
    return q
    ;
}

int calculate_dimes(int cents)
{
    // TO calculate_dimes
    int d = cents / 10;
    return d;
}

int calculate_nickels(int cents)
{
    // TO calculate_nickels
    int nk = cents / 5;
    return nk;
}

int calculate_pennies(int cents)
{
    // TO calculate_penny
    int p = cents / 1;
    return p;
}
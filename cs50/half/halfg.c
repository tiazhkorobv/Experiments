// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");
    float bill = bill_amount;
    float tax = bill_amount / 100 * tax_percent;
    float tip = (bill_amount + tax) / 100 * tip_percent;
    printf("Tax: $%.2f \n", tax);
    printf("Tip: $%.2f \n", tip);
    float half = ((bill + tax + tip) / 2);
    printf("You will owe $%.2f each!\n", half);
}

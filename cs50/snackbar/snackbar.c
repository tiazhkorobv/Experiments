// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// Menu itmes have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)// print out menu
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0; //initialize total amount
    while (true)
    {
        string item = get_string("Enter a food item: "); // prompt to choose and type item
        if (strlen(item) == 0) // if chosen nothing than stop
        {
            printf("\n");
            break;
        }
        total += get_cost(item);// sum out order items coast
    }
    printf("Your total cost is: $%.2f\n", total);
}

void add_items(void)//simply hard-coded the item names and prices into the menu array
{
    menu[0].item = "Burger";
    menu[0].price = 9.5;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11;

    menu[2].item = "Hot Dog";
    menu[2].price = 5;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7;

    menu[4].item = "Cheese Fries";
    menu[4].price = 6;

    menu[5].item = "Cold Pressed Juice";
    menu[5].price = 7;

    menu[6].item = "Cold Brew";
    menu[6].price = 3;

    menu[7].item = "Water";
    menu[7].price = 2;

    menu[8].item = "Soda";
    menu[8].price = 2;
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcasecmp(item, menu[i].item) == 0)// to compare the strings case-insensitively for enter the item name in any case.
        {
            return menu[i].price;//If matching item, than return its price
        }
    }
    printf("Item not found in menu.\n");
    return 0.0;
}
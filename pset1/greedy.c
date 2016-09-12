#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // asks user for amount of change repeatedly until non-negative entered
    float input;
    do
    {
        printf("How much change owed: ");
        input = GetFloat();
    }
    while (input < 0);
   
    // change cents to whole number and round to nearest integer
    int change = round(input * 100);
   
    // determine amount of change
    int quarters, dimes, nickels, pennies, remain, total;
    quarters = (change / 25);
    remain = change - (quarters * 25);
    dimes = (remain / 10);
    remain = change - ((quarters * 25) + (dimes * 10));
    nickels = (remain / 5);
    pennies = change - ((quarters * 25) + (dimes * 10) + (nickels * 5));
    total = quarters + dimes + nickels + pennies;
    printf("%d\n", total);
}
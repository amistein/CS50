#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompts user repeatedly until integer bet 0 and 23 is entered
    int input;
    do
    {
        printf("Enter a number between 0 and 23: ");
        input = GetInt();
    }
    while (input < 0 || input > 23);
    
    /*prints the number of lines entered by user, adding a hash and subtracting
    a space with each line*/
    int space = (input - 1);
    int hash = 2;
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < hash; k++)
        {
            printf("#");
        }
        printf("\n");
        space--;
        hash++;
    }
    
    
}
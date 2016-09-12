/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // if n is negative return false
    if (n < 0)
    {
        return false;
    }
    
    // variables for beginning, end, and middle of section being sorted
    int first = 0;
    int last = n - 1; 
    
    // loop until number found or determined not to be in group
    while (first <= last)
    {
        int middle = (first + last) / 2;
        
        // if number is found in middle 
        if (value == values[middle])
        {
            return true;
        }
        
        // if number is in smaller half, search smaller half
        else if (value < values[middle])
        {
            last = middle - 1;
        }   
    
        // if number is in larger half, search larger half
        else if (value > values[middle])
        {
            first = middle + 1;
        }
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // variables for checking if first number is greater than second
    int num1;
    int num2;
    // temporary placeholder for swapping
    int tmp;
    // variable to check if any numbers were swapped this pass
    int didswap;
    
    // pass through numbers and check if they are sorted
    do
    {
        num1 = 0;
        num2 = 1;
        didswap = 0;
        for (int i = 0; i < (n - 1); i++)
        {
            // swap if numbers are not sorted
            if (values[num1] > values[num2])
            {
                tmp = values[num1];
                values[num1] = values[num2];
                values[num2] = tmp;
                didswap = 1;
            }
            num1++;
            num2++;
        }
    }
    while (didswap == 1);
    return;
}
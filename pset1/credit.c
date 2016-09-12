#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    long long int input = GetLongLong();
    char number[20];
    
    sprintf(number, "%lli", input);
    
    printf("%s\n", number);
    
    
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Gets name from user
    string name = GetString();
    
    // capitalizes first initial
    printf("%c", toupper(name[0]));
    
    // iterates through name and capitalizes letter after space
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checks if user entered two arguments
    if (argc != 2)
    {
        printf("Please enter a value for key\n");
        return 1;
    }
    
    // converts key from string to int
    int k = atoi(argv[1]);
    
    // get message
    string message = GetString();
    
    // iterate over every character in message and print coded version
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // if character is lowercase
        if (islower(message[i]))
        {
            // subtract ascii value from character so a = 0 and z = 25
            char plain = message[i] - 97;
            // add key
            char cipher = (plain + k) % 26;
            // add ascii value
            char ascii = cipher + 97;
            printf("%c", ascii);
        }
        
        // if character is uppercase
        else if (isupper(message[i]))
        {
            // subtract ascii value from character so a = 0 and z = 25
            char plain = message[i] - 65;
            // add key
            char cipher = (plain + k) % 26;
            // add ascii value
            char ascii = cipher + 65;
            printf("%c", ascii);
        }
        
        // if character is not alphabetic print character
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
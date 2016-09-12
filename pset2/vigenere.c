#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checks if user entered only one command line argument
    if (argc != 2)
    {
        printf("Try again with one command line argument!\n");
        return 1;
    }
    
    // checks if all characters in key are alphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Please enter only alphabetical characters for key!\n");
            return 1;
        }
    }
    
    // gets message
    string message = GetString();
    
    // counter for alphabetic characters in message
    int alpha = 0;
    
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // if characters in message exceeds characters in key, reuse cyclically
        int keyplace = alpha % strlen(argv[1]);
        int key = argv[1][keyplace];
        
        // subtract ascii value from key
        if (islower(key))
        {
            key = key - 97;
        }
        else if (isupper(key))
        {
            key = key - 65;
        }
        
         // if ith character is lowercase
        if (islower(message[i]))
        {
            // subtract ascii value from character so a = 0 and z = 25
            char plain = message[i] - 97;
            // add key
            char cipher = (plain + key) % 26;
            // add ascii value
            char ascii = cipher + 97;
            printf("%c", ascii);
            // increment alphabetic counter
            alpha++;
        }
        
        // if ith character is uppercase
        else if (isupper(message[i]))
        {
            // subtract ascii value from character so a = 0 and z = 25
            char plain = message[i] - 65;
            // add key
            char cipher = (plain + key) % 26;
            // add ascii value
            char ascii = cipher + 65;
            printf("%c", ascii);
            // increment letter counter
            alpha++;
        }
        
        // if ith character is not alphabetic print character
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
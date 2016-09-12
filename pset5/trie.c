#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Word please: ");
    char* word = GetString();
    
    typedef struct node
    {
        bool isword;
        struct node* letters[26];
    }
    node;
    
    node* first = malloc(sizeof(node));
    
     for (int i = 0; i < 26; i++)
    {
        first->letters[i] = NULL;
    }
    
    int letter;
    node* current = first;
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        letter = word[i] - 97;
        current->letters[letter] = malloc(sizeof(node));
        current = current->letters[letter];
    }
    
    current->isword = true;
    
    
    
    
    
}
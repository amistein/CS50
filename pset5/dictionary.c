/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"



// declare root node
node* root = NULL;
// variable for size of dictionary
unsigned int dicsize = 0;
    


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int letter;
    node* current = root;
    // determine if corresponding children pointer of current letter is NULL
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] == '\'')
        {
            letter = 26;
        }
        else
        {
            letter = toupper(word[i]) - 'A';
        }
        
        if (current->children[letter] == NULL)
        {
            return false;
        }
        else
        {
            current = current->children[letter];
        }
    }
    // if word exists
    if (current->isword == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // allocate memory for root node and set all children pointers to NULL
    root = malloc(sizeof(node));
    for (int i = 0; i < 27; i++)
    {
        root->isword = false;
        root->children[i] = NULL;
    }
    
    // open dictionary file
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    // buffer
    char* word = malloc(LENGTH + 1);
    
    int letter;
    
    // store one word at a time in buffer
    while (fgets(word, (LENGTH + 1), fp) != NULL)
    {
        node* current = root;
        // determine which index of children current letter corresponds to
        // fgets stores newline character, so subtract that from strlen
        for (int i = 0, n = (strlen(word) - 1); i < n; i++)
        {
            if (word[i] == '\'')
            {
                letter = 26;
            }
            else
            {
                letter = toupper(word[i]) - 'A';
            }
            
            // check if corresponding child is already used in word
            if (current->children[letter] == NULL)
            {
                current->children[letter] = malloc(sizeof(node));
                // initialize all pointers of new node to NULL
                current->children[letter]->isword = false;
                for (int i = 0; i < 27; i++)
                {
                    current->children[letter]->children[i] = NULL;
                }
            }
            // move position of current node
            current = current->children[letter];
        }
        // end of word
        current->isword = true;
        dicsize++;
    }
    fclose(fp);
    free(word);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return dicsize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    freenode(root);
    return true;
}

/**
 * Recursive function to free trie
 */
void freenode(node* first)
{
    // interate through children pointers, if not NULL, call freenode on it
    for (int i = 0; i < 27; i++)
    {
        if (first->children[i] != NULL)
        {
            freenode(first->children[i]);
        }
    }
    // when all children pointers == NULL, free node
    free(first);
}

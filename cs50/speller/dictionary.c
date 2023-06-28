// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of words in dictionary
int word_count = 0;

//TODO: Choose number of buckets in hash table
const unsigned int N = 26;

node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO: Take a word and check is it in the dic. or not
    //Hash word to obtain a hash value
    unsigned int index = hash(word);

    //Access linked list at that index in the hash table
    node *cursor = table[index];

    //Traverse linked list, using loop while looking for the word (strcasecmp):
    //Start with cursor set to first item in linked list.
    // Return true if the word is in the dictionary, false otherwise. Case insensitive;
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    // Word is not in dictionary
    return false;
}

// Hashes word to a number - return uns. int. representing which index into the hash table...
unsigned int hash(const char *word) //...you should use that corresponds to that particular word.
{
    // TODO: Improve this hash function (must be deterministic):
    // Input: word, with alphabetical characters and (possibly) apostrophes
    //Output: numerical index between 0 and N - 1, inclusive (take the value % N to get a value in the appropriate range)
    unsigned long sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        sum += toupper(word[i]);//iterates through each character in the input word, converting it to uppercase using the toupper function, and adding its ASCII value to sum.
//  remainder when sum is divided by the number of buckets in the hash table (N). This ensures that the index is within the range of the array.  }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODOOpen dictionary file
    //Use fopen
    //check if return value is NULL
    FILE *dic = fopen(dictionary, "r");
    char word[LENGTH + 1];
    //make sure to check to see if the if value is null make sure that you were able to successfully open up the file
    if (dic == NULL)
    {
        printf("No dictionary available\n");
        return false;
    }

    // Read words from dic and add to hash table
    //use loop running fscanf again and again on one word, after word until you get to the end of the dic.
    //Read Strings from dic with fscanf(dic, "%s", word)
    //fscanf will return EOF once it reaches end of dic

    while (fscanf(dic, "%s", word) != EOF)
    {
        //Create a New Node:
        //Use malloc
        node *new_node = malloc(sizeof(node));
        //Remember to check if return value is NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        //Copy word into node using strcpy
        strcpy(new_node->word, word);
        int h = hash(new_node->word);
        new_node->next = table[h];
        table[h] = new_node;
        word_count++;
        //determine which linked list shold be used when where to place this
        //particular node that e've just created.
        //Use the 'hash' function wich takes a string and returns an index
        //Insert Node into Hash Table (hash table is an array of linked lists)
        // Be sure to set pointers in the correct order!
        // Close dictionary dic
    }
    // Return true to indicate success
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO: Keep track and return the number of added words
    return word_count;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: loop free using variables 'cursor' and 'tmp'
    // Free memory allocated for each node in each linked list
    for (int i = 0; i < N; i++)
    {
        node *pointer = table[i];

        while (table[i] != NULL && pointer != NULL)
        {
            node *tmp = pointer;
            pointer = pointer->next;
            free(tmp);
        }
        free(pointer);
    }
    return true;
}



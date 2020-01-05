#include "dictionary.h"

// define struct for value-pointer pair, i.e., a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// create array of pointer-to-nodes of size HASHTABLE_SIZE
node* hashtable[HASHTABLE_SIZE];

// global variable for tracking of dictionary size
unsigned int word_count = 0;

// global boolean for tracking load/unload dictionary operations
bool loaded = false;

/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
        {
          hash = (hash << 2) ^ needs_hashing[i];
        }
    return hash % HASHTABLE_SIZE;
}

/**
 * Returns true if word is in dictionary else false. Case-insensitive.
 * Assume that check is only passed strings with alphabetical characters and/or
 * apostrophes.
 */
bool check(const char* word)
{
    int len = strlen(word);
    char word_copied[len];

    for (int i = 0; i < len; i++)
    {
        word_copied[i] = tolower(word[i]);
    }

    word_copied[len] = '\0';

    int h = hash_it(word_copied);

    node* cursor = hashtable[h];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word_copied) == 0)
        {
            // word is in dictionary
            return true;
        }
        else
        {
            // check next node
            cursor = cursor->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Stores words in hash table. Returns true if
 * successful else false.
 */
bool load(const char* dictionary)
{
    // make all hash table elements NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    while (true)
    {
        //malloc data for new node
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not allocate memory for new node.\n");
            return false;
        }

        // read a word from the dictionary and store it in new_node
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;

        //release memory if EOF
        if (feof(fp))
        {
            // hit end of file
            free(new_node);
            break;
        }

        word_count++;

        int x = hash_it(new_node->word);

        //check if empty
        if (hashtable[x] == NULL)
        {
            hashtable[x] = new_node;
        }
        // attach node to linked list if not empty
        else
        {
            new_node->next = hashtable[x];
            hashtable[x] = new_node;
        }
    }
    // close dictionary
    fclose(fp);
    loaded = true;
    return true;
}
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* cursor = hashtable[i];
        if (hashtable[i] != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
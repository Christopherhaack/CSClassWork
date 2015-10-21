/*
 * CS 11, C Track, lab 7
 *
 * FILE: hash_table.c
 *
 *       Implementation of the hash table functionality.
 *
 */

/*
 * Include the declaration of the hash table data structures
 * and the function prototypes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "memcheck.h"


/*** Hash function. ***/

int hash(char *s)
{
    int i;
    int sum = 0;
    for (i = 0; i < sizeof(s); i++) {
        sum += s[i];
    }
    return (sum % 128);
}


/*** Linked list utilities. ***/

/* Create a single node. */
node * create_node(int value, char *key, node *n)
{
    node *result = (node *)malloc(sizeof(node));
    
    if (result == NULL)
    {
        fprintf(stderr, "Fatal error: out of memory. "
                "Terminating program.\n");
        exit(1);
    }
    result->key = key;
    result->value = value;  /* Fill in the new node with the given value. */
    result->next = n;
    
    return result;
}


/*
 * free_list:
 *     Free all the nodes of a linked list.
 */

void
free_list(node *list)
{
    node *n;     /* a single node of the list */
    
    while (list != NULL)
    {
        n = list;
        list = list->next;
        
        /*
         * 'n' now points to the first element of the list, while
         * 'list' now points to everything but the first element.
         * Since nothing points to 'n', it can be freed.
         */
        free(n -> key);
        free(n);
    }
}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table()
{
    hash_table *ht = (hash_table *) calloc(NSLOTS, sizeof(hash_table));
    if (ht == NULL)
{
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);  /* abort the program */
}   
    ht -> slot = (node **) calloc(NSLOTS, sizeof(node *));
if (ht -> slot == NULL)
{
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);  /* abort the program */
}   
    return ht;

}


/* Free a hash table. */
void free_hash_table(hash_table *ht)
{
    int i;
    for (i = 0; i < NSLOTS; i++) {
        free_list(ht -> slot[i]);
    }
    free(ht -> slot);
    free(ht);

}


/*
 * Look for a key in the hash table.  Return 0 if not found.
 * If it is found return the associated value.
 */
int get_value(hash_table *ht, char *key)
{
    int h = hash(key);
    node * loc;
    loc = ht -> slot[h];
        while(loc != NULL) {
        if (strcmp(key, loc -> key) == 0) {
            return (loc -> value);
        }
        loc = loc -> next;
        }
        return 0;
    }




/*
 * Set the value stored at a key.  If the key is not in the table,
 * create a new node and set the value to 'value'.  Note that this
 * function alters the hash table that was passed to it.
 */
void set_value(hash_table *ht, char *key, int value)
{
    int h = hash(key);
    node * loc;
    loc = ht -> slot[h]; 
    while(loc != NULL) {
        if (strcmp(key, loc -> key) == 0) {
            loc -> value = value;
            free(key);
            return;
        }
        loc = loc -> next;
    }
    loc = create_node(value, key, ht -> slot[h]);
    ht -> slot[h] = loc;
}


/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht)
{
    int i;
    node * slot_loc;
    for (i = 0; i < NSLOTS; i++) {
        slot_loc = ht -> slot[i];
        while (slot_loc != NULL) {
            fprintf(stdout, "%s %d\n", slot_loc -> key, slot_loc -> value);
            slot_loc = slot_loc -> next;
        }
    }
}



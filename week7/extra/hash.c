#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <limits.h>

typedef struct node_s {
    string key;
    string value;
    struct node_s *next ;
} node ;

typedef struct hashtable_s {
    int size ; 
    struct node_s **table ;
} hashtable ;

hashtable* hashcreate (int size);
void hashdestroy (hashtable* h);

int hash (hashtable* h, string key);

node* hashtableNewPair (string key, string value);  

// размещение узла в таблице
void hashtableSet(hashtable* h, string key , string value);

string hashtableGet (hashtable*h , string key);

hashtable* hashcreate (int size)
{
    hashtable* h = malloc (sizeof (hashtable)) ;
    h->table = malloc(sizeof(node)*size);
    for (int i = 0; i < size ; i++)
    {
        h->table[i] = NULL;
    }
    h->size = size; 
    return h ;
}

void hashdestroy (hashtable* h)
{
    if(h != NULL)
    {
        if(h->table != NULL)
        {
            free(h->table);
            h->table = NULL;
        }
        free(h);
        h = NULL;
    }
}

int hash(hashtable* h , string key)
{
    unsigned long int hashvalue = 0; 
    int i = 0;
    while (hashvalue < ULONG_MAX && i < strlen(key))
    {
        hashvalue = hashvalue << 8 ; // *256 
        hashvalue = hashvalue + key[i];
        i++;
    }
    return hashvalue % h->size ;
}

void hashtableSet(hashtable* h, string key , string value)
{
    int index = hash(h, key);
    node *new_next;
    node* last;
    new_next = h->table[index];
    while(new_next != NULL && new_next->key != NULL && new_next->key != key)
    {
        last = new_next;
        new_next = new_next->next;
    }
    if(new_next !=NULL && new_next->key != NULL && new_next->key == key)
    {
        new_next->value = value;
    }
    else
    {
        node* new_pair = hashtableNewPair(key, value);
        h->table[index] = new_pair;
    }
}

string hashtableGet (hashtable *h , string key)
{
    //int tmp = hash(h, key);
    //printf("%d\n", tmp);
    node *pair = h->table[hash(h, key)];
    while(pair != NULL && pair->key != NULL && pair->key != key)
    {
        pair = pair->next;
    }
    if(pair == NULL)
    {
        return "nothing";
    }
    else
    {
        return pair->value;
    }
    
    
}

node* hashtableNewPair (string key, string value)
{
    node* new_node = malloc (sizeof(node));
    new_node->key = key;
    new_node->value = value ;
    new_node->next = NULL ;
    return new_node;
}

int main ()
{
   hashtable* mytable = hashcreate(100);
    //node* catnode = hashtableNewPair("cat", "kit");
    //node* dognode = hashtableNewPair("dog", "pes");
    hashtableSet(mytable, "cat", "kit");
    hashtableSet(mytable, "dog", "pes");
    string catvalue = hashtableGet(mytable, "cat");
    string dogvalue = hashtableGet(mytable, "elephant");
    printf("%s\n", catvalue);
    printf("%s\n", dogvalue);
    hashdestroy(mytable);
}

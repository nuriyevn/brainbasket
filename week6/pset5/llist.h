#include <stdio.h>
#include <cs50.h>

// struct linked list
typedef struct llist
{
    int age;
    string name;
    struct llist* next;
    
} list;


// functions prototypes
void list_add(list *head, string name);
void list_print(list *head);
bool list_remove_last(list *head);
int list_size(list* head);
#include <stdio.h>
#include <cs50.h>
#include "llist.h"

// declaration of global variable - head of llist

/*
int main()
{
    list_add(GetInt(), GetString());
    list_print();
    list_remove_last();
    list_remove_last();

    list_print();
}
*/

void list_add(list* head, int age, string name)
{
    list* new_item = malloc(sizeof(list));
    new_item->next = NULL;
    new_item->age = age;
    new_item->name = name;
    
    list* tmp = head;
    
    if (tmp == NULL)
    {
        head = new_item;
    }
    else
    {
        while(tmp->next != NULL)
            tmp = tmp->next;
            
        tmp->next = new_item;
    }
}


void list_print(list *head)
{
    list* tmp = head;
    
    while (tmp != NULL)
    {
        
        printf("| age is %d, name is %s | ->", tmp->age, tmp->name);
        tmp = tmp->next;
    }
    
    printf("NULL\n");
}


void list_remove_last(list *headgcc)
{
    list* last = head;
    list* prev = last;
    
    if (last == NULL)
        return;
    
    if (last->next == NULL)
    {
        
        free(last);
        head = NULL;
    }
    else
    {
        while (last->next != NULL)
        {
            prev = last;
            last = last->next;
        }
        
        free(last);
        printf("prev.age = %d\n", prev->age);
        
        prev->next = NULL;
    }
    return;
}
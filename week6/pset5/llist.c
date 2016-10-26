
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

void list_add(list* head, string name)
{
    list* new_item = malloc(sizeof(list));
    new_item->next = NULL;
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
        
        printf("| name is %s | ->", tmp->name);
        tmp = tmp->next;
    }
    
    printf("NULL\n");
}


bool list_remove_last(list *head)
{
    list* last = head;
    list* prev = last;
    
    if (last == NULL)
        return false;
    
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
        prev->next = NULL;
    }
    return true;
}

int list_size(list* head)
{
    printf ("list_size is called");
    list* tmp = head;
    int count = 0;
    printf ("%p\n",tmp);
    while (tmp != NULL)
    {
        tmp = tmp->next;
        count++;
        printf("%i\n", count);
        
    }
    return count ;
    
}
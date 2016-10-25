// struct linked list
typedef struct llist
{
    int age;
    string name;
    struct llist* next;
    
} list;


// functions prototypes
void list_add(list *head, int age, string name);
void list_print(list *head);
void list_remove_last(list *head);

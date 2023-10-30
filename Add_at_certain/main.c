#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *add_at_end(struct node *head,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    head->link = temp;
    return temp;
    
}
void add_at_pos(struct node *ptr,int data,int pos)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
    
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr, 45);
    ptr = add_at_end(ptr, 55);
    ptr = add_at_end(ptr, 66);
    int pos;
    add_at_pos(head,97,5);
    
   ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int data;
    struct ListNode *link;
};
struct ListNode *add_at_end(struct ListNode *ptr, int data)
{
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
struct ListNode* mergeSortedLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result = NULL;
    struct ListNode** lastPtrRef = &result;

    while (1) {
        if (list1 == NULL) {
            *lastPtrRef = list2;
            break;
        } else if (list2 == NULL) {
            *lastPtrRef = list1;
            break;
        }

        if (list1->data <= list2->data) {
            *lastPtrRef = list1;
            list1 = list1->link;
        } else {
            *lastPtrRef = list2;
            list2 = list2->link;
        }

        lastPtrRef = &((*lastPtrRef)->link);
    }

    return result;
}
int main()
{
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->data = 3;
    head->link = NULL;
    struct ListNode *ptr = head;
    ptr = add_at_end(ptr,4);
    ptr = add_at_end(ptr,7);
    ptr = add_at_end(ptr,9);
   struct ListNode *head2 = malloc(sizeof(struct ListNode));
    head2->data = 2;
    head2->link = NULL;
    struct ListNode *ptr2 = head2;
    ptr2 = add_at_end(ptr2,5);
    ptr2 = add_at_end(ptr2,6);
    ptr2 = add_at_end(ptr2,8);
    struct ListNode *mergedList = mergeSortedLists(head, head2);
    struct ListNode *ptr3 = mergedList;
     while(ptr3 != NULL)
    {
        printf("%d\t",ptr3->data);
        ptr3 = ptr3->link;
    }
}
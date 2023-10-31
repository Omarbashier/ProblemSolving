#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
  struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
  void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
    
    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers together until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Remove the nth node from end
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    
    return dummy->next;
}
int main() {
    struct ListNode* head = newNode( 1);
    head->next = newNode( 2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head = removeNthFromEnd(head,5);
    printList(head);

    return 0;
}
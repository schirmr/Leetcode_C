#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return NULL;
    struct ListNode* current = head;
    while(current != NULL && current->next != NULL){
      if (current->val == current->next->val) {
        current->next = current->next->next;
      }
      else current = current->next;
    }
  return head;
}

struct ListNode* createNode(int data){
  struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->val = data;
  newNode->next = NULL;
  return newNode;
}

void printList(struct ListNode* head){
  struct ListNode* temp = head;
  while(temp != NULL){
    printf("%d -> ", temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}

void freeList(struct ListNode* head){
  struct ListNode* current = head;
  struct ListNode* temp;
  while(temp != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
}

int main() {
  struct ListNode* head = createNode(1);
  head->next = createNode(1);
  head->next->next = createNode(1);
  head->next->next->next = createNode(3);
  head->next->next->next->next = createNode(3);
  printf("Lista antes: ");
  printList(head);
  printf("Lista depois: ");
  head = deleteDuplicates(head);
  printList(head);
  freeList(head);
  return 0;
}
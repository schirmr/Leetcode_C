/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* createNode(int val) {
  struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

struct ListNode* mergeNodes(struct ListNode* head) {
  struct ListNode* mergeList = (struct ListNode*)malloc(sizeof(struct ListNode));
  head = head->next;
  mergeList = createNode(0);
  struct ListNode* pmergeList = mergeList;
  while (head != NULL) {
    if (head->val == 0 && head->next == NULL) break;
    if (head->val == 0) {
      head = head->next;
      if (pmergeList->val == 0);
      else {
        pmergeList->next = createNode(0);
        pmergeList = pmergeList->next;
      }
    }
    else {
      pmergeList->val+= head->val;
      head = head->next;
    }
  }
  return mergeList;
}

void printList(struct ListNode* head) {
  struct ListNode* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}

void liberarLista(struct ListNode* head) {
  struct ListNode* atual = head;
  struct ListNode* proximo;
  while (atual != NULL) {
    proximo = atual->next;
    free(atual);
    atual = proximo;
  }
}

int main() {
  struct ListNode* head = createNode(0);
  head->next = createNode(1);
  head->next->next = createNode(0);
  head->next->next->next = createNode(3);
  head->next->next->next->next = createNode(0);
  head->next->next->next->next->next = createNode(2);
  head->next->next->next->next->next->next = createNode(2);
  head->next->next->next->next->next->next->next= createNode(0);
  printList(head);
  struct ListNode* mergeList = mergeNodes(head);
  printList(mergeList);
  liberarLista(head);
  liberarLista(mergeList);
  return 0;
}
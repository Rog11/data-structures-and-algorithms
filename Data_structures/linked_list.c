#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int data;
  struct ListNode *next;
};

struct List {
  struct ListNode *head;
};

void insert(struct List *list, int data)
{
  struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
  node->data = data;
  node->next = list->head; //inserts it to the front of the list
  list->head = node; 
}

//to insert to the back of the list
void insertBack(struct List *list, int data)
{
  struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
  node->data = data; 
  node->next = NULL;

  if (list->head == NULL)
  {
    list->head = node; 
  }
  else 
  {
    struct ListNode *current = list->head;
    while(current->next != NULL)
    {
      current = current->next;
    }
    current->next = node;
  }
}

void printList(struct List *list)
{
  struct ListNode *current = list->head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  struct List list;
  list.head = NULL;
  insert(&list, 10);
  insert(&list, 20);
  insert(&list, 30);
  printList(&list);  // prints 30 20 10
  return 0;
}

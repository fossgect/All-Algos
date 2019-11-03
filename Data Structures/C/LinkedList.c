#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
typedef struct Node lnode;

lnode *createNode() {
  lnode *node;
  node = (lnode *)malloc(sizeof(lnode));
  return node;
}
void display(lnode *head) {
  lnode *temp;
  temp = head;
  if (head == NULL)
    printf("Empty..!!\n");
  else {
    while (temp != NULL) {
      printf("--->| %d |", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
void deleteEnd(lnode **head_ref) {
  lnode *current = *head_ref;
  lnode *next;
  lnode *prev;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  current = NULL;
  free(current);
}
int main() {
  lnode *head = NULL;
  lnode *temp;
  lnode *end;
  lnode *endprev;

  int resp;
  while (1) {
    printf("____Select any options from the following____\n\n1)Insert at "
           "begining\n2)Delete from end\n3)Display\n"
           "4)Stop\n\nEnter "
           "Your Choice:");
    scanf("%d", &resp);
    switch (resp) {
    case 1:
      temp = createNode();
      printf("Enter the data for the new Node : ");
      scanf("%d", &(temp->data));
      if (head == NULL) {
        temp->next = NULL;
        end = temp;

      } else if (head->next == NULL)
        endprev = temp, temp->next = head;
      else
        temp->next = head;
      head = temp;
      //      display(head);
      break;
    case 2:
      deleteEnd(&head);
      break;
      //    display(head);
      //  printf("%d", head->data);
    case 3:
      display(head);
      break;
    case 4:
      exit(0);
      break;
    }
  }
}

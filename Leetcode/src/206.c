struct ListNode* reverseList(struct ListNode* head){
  struct ListNode *prev = NULL;
  struct ListNode *current = head;
  struct ListNode *next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

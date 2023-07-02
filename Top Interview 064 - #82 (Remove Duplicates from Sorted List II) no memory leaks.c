static struct ListNode* _free_and_get_next(struct ListNode* curr) {
    struct ListNode* temp = curr;
    curr = curr->next;
    free(temp);
    return curr;
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) {return head;}
    struct ListNode node = {.next = head,};
    struct ListNode* dummy = &node;   
    for (struct ListNode *prev = dummy, *curr = dummy; curr != NULL; prev->next = curr, prev = curr) {
        for (curr = curr->next; (curr != NULL) && (curr->next != NULL) && (curr->val == curr->next->val); curr = _free_and_get_next(curr)) {
            while ((curr->next != NULL) && (curr->val == curr->next->val)) {curr = _free_and_get_next(curr);}
        }
    }
    return dummy->next; //return head
}

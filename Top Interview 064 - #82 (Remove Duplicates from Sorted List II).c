struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head -> next == NULL) {return head;}
    struct ListNode * dummy = malloc(sizeof(struct ListNode));
    dummy -> next = head;
    struct ListNode *prev = dummy, *curr = head;
    while (curr != NULL) {
        while (curr -> next != NULL && curr -> val == curr -> next -> val) {curr = curr -> next;} //skip the duplicate val
        if (prev->next == curr) {prev = prev->next;} //no duplicates
        else {prev->next = curr->next;} //duplicate
        curr = curr -> next;
    }
    head = dummy->next;
    free(dummy);
    return head;
}

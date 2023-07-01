struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode * move = dummy, * stay = dummy;
    for (int i = 1; i <= n + 1; i++) { //this is 
        move = move -> next; //set up a gap of n nodes between move and stay
    }
    while (move != NULL) {
        move = move -> next;
        stay = stay -> next; //now stay is just before the node to be removed
    }
    stay->next = stay->next->next; //skip the nth node from end
    struct ListNode * result = dummy -> next;
    free(dummy);
    return result;

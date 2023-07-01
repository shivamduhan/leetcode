struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * move = head, * stay = head; //init nodes
    if (head == NULL || head -> next == NULL) {return NULL;} //deal with edge cases
    for (int i = 0; i < n; i++) { //this is to ensure stay will be 1 before node to be reversed
        if (move -> next) {move=move->next;} //set up a gap of n+1 nodes between move and stay
        else {
            struct ListNode * newhead = head -> next;
            free(head);
            return newhead;
        }
    }
    while (move->next != NULL) {
        move = move -> next; //let move go to the end of the list
        stay = stay -> next; //now stay is just before the node to be removed
    }
    stay->next = stay->next->next; //skip the nth node from end
    return head;
}

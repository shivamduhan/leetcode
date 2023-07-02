struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode * smallHead = (struct ListNode*)malloc(sizeof(struct ListNode)); //preserve head of smaller list
    struct ListNode * smallerList = smallHead; //start left partition at dummy node
    struct ListNode * bigHead = (struct ListNode*) malloc(sizeof(struct ListNode)); //preserve head of larger list
    struct ListNode * bigList = bigHead;
    while (head) {
        if (head -> val < x){
            smallerList->next = head; //append node to before list
            smallerList = smallerList->next; 
        }
        else {
            bigList->next = head; //append node to after list
            bigList = bigList->next; 
        }
        head = head->next;
    }
    bigList->next = NULL; //avoid cycle
    smallerList->next=bigHead->next; //connect partitions
    struct ListNode * newHead = smallHead -> next;
    free(smallHead);
    free(bigHead);
    return newHead;
}

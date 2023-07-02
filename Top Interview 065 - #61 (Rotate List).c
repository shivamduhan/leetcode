struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head || !head->next || !k) {return head;}
    struct ListNode * tail = head; //make list circular
    int listLength = 1;
    while (tail->next){ //traverse the list
        tail = tail->next; //find tail node
        listLength++;
    }
    tail->next = head; //make list circular
    int rotations = listLength - (k % listLength); //full rotations dont affect list
    for (int i = 0; i < rotations; i++) {tail = tail->next;} 
    struct ListNode * newHead = tail -> next;
    tail->next = NULL; //make list uncircular
    return newHead;
}

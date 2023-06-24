struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head_ptr = malloc(sizeof(struct ListNode));
    struct ListNode *current = head_ptr;
    int carry = 0;
    while (l1 || l2 || carry) { //gotta add
        if (l1) { //in case l1 is longer, this will keep getting executed
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) { //in case l2 is longer
            carry+=l2->val;
            l2 = l2->next;
        }
        current->next = malloc(sizeof(struct ListNode)); //create newnode in every iteration
        current = current->next; //jump to new node
        current->val = carry % 10; //assign last digit of carry to node
        current->next = NULL; //finish creating node
        carry = carry / 10; //update carry
    }
    struct Listnode *result = head_ptr -> next; //current ptr is at the end of the list so use head_ptr, 1st node of head_ptr is irrelevant.
    free(head_ptr);
    return result;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * move = head, * stay = head; //init nodes
    if (head == NULL || head -> next == NULL) {return NULL;} //deal with edge cases
    for (int i = 0; i < n; i++) { //this is to ensure stay will be 1 before node to be reversed
        if (move -> next) {move=move->next;} //set up a gap of n+1 nodes between move and stay
        else {
            struct ListNode * newhead = head -> next; //deal with case where head needs to be deleted
            free(head);
            return newhead;
        }
    }
    while (move->next != NULL) {
        move = move -> next; //let move go to the end of the list
        stay = stay -> next; //now stay is just before the node to be removed
    }
    struct ListNode * tmp = stay->next;
    stay->next = stay->next->next; //skip the nth node from end
    free(tmp); //free the node that you're removing
    return head;
}

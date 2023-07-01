/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head, int k) {
    struct ListNode *prev = NULL, *curr = head; //In reversed list, 1st Node will have NULL as next node, start reversal from head
    while(k--) { //how many nodes to reverse
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; //head of reversed list
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *curr = head, *prevLast = NULL;
    while(curr) {
        struct ListNode *first = curr, *last = curr;
        for(int i = 1; i < k && last; i++) {
            last = last->next; //find last node
        }
        if(!last) {
            break;
        }
        struct ListNode *nextFirst = last->next;
        curr = last = reverse(first, k); //curr is first node to start reversal from
        if(prevLast) {
            prevLast->next = last; //connect prev group
        } else {
            head = last; //group is 1st grp, update head
        }
        prevLast = first; //last node of prev group
        curr = first->next = nextFirst; //start reversing from second node now i.e. mover curr to next grp
    }
    return head;
}

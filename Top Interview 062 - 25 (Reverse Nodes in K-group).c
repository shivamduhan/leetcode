/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverse(struct ListNode* head, int k) {
    struct ListNode *prev = NULL, *curr = head;
    while(k--) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *curr = head, *prevLast = NULL;
    while(curr) {
        struct ListNode *first = curr, *last = curr;
        for(int i = 1; i < k && last; i++) {
            last = last->next;
        }
        if(!last) {
            break;
        }
        struct ListNode *nextFirst = last->next;
        curr = last = reverse(first, k);
        if(prevLast) {
            prevLast->next = last;
        } else {
            head = last;
        }
        prevLast = first;
        curr = first->next = nextFirst;
    }
    return head;
}
